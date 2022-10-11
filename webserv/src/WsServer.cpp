#include "WsServer.hpp"
#include "socket/WsClientSock.hpp"
#include <utility>

WsServer::WsServer(const std::vector<WsConfigInfo> &conf)
	:m_conf(conf)
{
	m_serverSize = m_conf.size();
	FD_ZERO(&m_FdSet);
	FD_ZERO(&m_FdSetCopy);
}

WsServer::~WsServer()
{}

WsServer::WsServer(const WsServer& copy)
{
	*this = copy;
}

WsServer&
WsServer::operator=(const WsServer &copy)
{
	m_conf = copy.m_conf;
	m_serverSocket = copy.m_serverSocket;
	m_serverSize = copy.m_serverSize;
	return (*this);
}

void
WsServer::createServerSock(void)
{
	for (size_t serverSockIdx = 0; serverSockIdx < m_serverSize; serverSockIdx++)
	{
		WsServerSock serverSock(m_conf[serverSockIdx]);
		serverSock.createSock();
		serverSock.initAddr();
		serverSock.bindSock();
		serverSock.listenSock();
		m_maxServerFd = serverSock.getSocketFd();
		m_serverSocket.insert(std::make_pair(serverSock.getSocketFd(), serverSock));
	}
	m_totalFd = m_maxServerFd;
}

void
WsServer::run(void)
{
	int selectRet;

	initFdSet();
	while (1)
	{
		m_FdSetCopy = m_FdSet;
		selectRet = selectSock();
		if (selectRet < 0)
			break;
		else if (selectRet == 0)
			continue;
		communicateSock();
	}
}

void
WsServer::initFdSet(void)
{
	// for (size_t idx = 0; idx < m_serverSize; idx++)
	//     FD_SET(m_serverSock[idx].getSocketFd(), &m_FdSet);

	std::map<int, WsServerSock>::iterator serverSockIt = m_serverSocket.begin();
	for (; serverSockIt != m_serverSocket.end(); serverSockIt++)
		FD_SET(serverSockIt->first, &m_FdSet);
}

int
WsServer::selectSock(void)
{
	int selectRet;
	// struct timeval timeout;

	// timeout.tv_sec = 5;
	// timeout.tv_usec = 5000;
	std::cout << std::endl << "waiting socket to select" << std::endl;
	std::cout << "total fd : " << m_totalFd << std::endl;
	selectRet = select(m_totalFd + 1, &m_FdSetCopy, (fd_set*)0, (fd_set*)0, 0);
	if (selectRet < 0)
	{
		std::cout << "select error" << std::endl;
		return (-1);
	}
	if (selectRet == 0)
	{
		std::cout << "select time out" << std::endl;
		return (0);
	}
	std::cout << "selected socket ready socket status num : " << selectRet << std::endl;
	return (1);
}

void WsServer::communicateSock(void)
{
	for (int fdIdx = 3; fdIdx < m_totalFd + 1; fdIdx++)
	{
		if (isServerSockSet(fdIdx))
		{
			WsClientSock clientSock(m_serverSocket.at(fdIdx));
			clientSock.createSock();
			FD_SET(clientSock.getSocketFd(), &m_FdSet);

			m_clientSocket.insert(std::make_pair(clientSock.getSocketFd(), clientSock));
			if (m_totalFd < clientSock.getSocketFd())
				m_totalFd = clientSock.getSocketFd();
			std::cout << "total fd : "<< m_totalFd << std::endl;
			std::cout << "server client connected" << std::endl;
		}
		else if (isClientSockSet(fdIdx))
		{
			int readRet;

			std::cout << "client call to read " << fdIdx << std::endl;

			std::map<int, WsClientSock>::iterator clientIt = m_clientSocket.find(fdIdx);
			readRet = (*clientIt).second.readSock();
			if (readRet == 0)
			{
				FD_CLR((*clientIt).first, &m_FdSet);
				(*clientIt).second.closeSock();
				// m_clientSock.erase(clientIt);
			}
			else if (readRet < 0)
			{}
			else
				(*clientIt).second.sendSock();
				FD_CLR((*clientIt).first, &m_FdSet);
				(*clientIt).second.closeSock();
				// m_clientSock.erase(clientIt);
		}
	}
}

bool WsServer::isServerSockSet(int fdIdx)
{
	if (fdIdx <= m_maxServerFd && FD_ISSET(fdIdx, &m_FdSetCopy))
		return (true);
	return (false);
}

bool WsServer::isClientSockSet(int fdIdx)
{
	if (fdIdx > m_maxServerFd && FD_ISSET(fdIdx, &m_FdSetCopy))
		return (true);
	return (false);
}

// void WsServer::isClientSockEof(void)
// {
//     int readRet;
//
//     for (std::vector<WsClientSock>::iterator clientIt = m_clientSock.begin();
//             clientIt != m_clientSock.end(); clientIt++)
//     {
//         readRet = (*clientIt).readSock();
//         std::cout << "read request finish" << std::endl;
//         std::cout << readRet << std::endl;
//         if (readRet <= 0)
//         {
//             (*clientIt).sendSock();
//             FD_CLR((*clientIt).getSocketFd(), &m_FdSet);
//             (*clientIt).closeSock();
//             m_clientSock.erase(clientIt);
//             return;
//         }
//     }
// }
