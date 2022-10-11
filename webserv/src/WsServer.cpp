#include "WsServer.hpp"
#include "socket/WsClientSock.hpp"

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
	m_serverSock = copy.m_serverSock;
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
		m_serverSock.push_back(serverSock);
	}
	m_maxServerFd = m_serverSock.back().getSocketFd();
	m_totalFd = m_maxServerFd;
}

void
WsServer::run(void)
{
	initFdSet();
	while (1)
	{
		m_FdSetCopy = m_FdSet;
		if (!selectSock())
			break;
		communicateSock();
	}
}

void
WsServer::initFdSet(void)
{
	for (size_t idx = 0; idx < m_serverSize; idx++)
		FD_SET(m_serverSock[idx].getSocketFd(), &m_FdSet);
}

bool
WsServer::selectSock(void)
{
	int selectRet;
	// struct timeval timeout;
    //
	// timeout.tv_sec = 5;
	// timeout.tv_usec = 5000;
	std::cout << std::endl << "waiting socket to select" << std::endl;
	// std::cout << "fd set : " << m_FdSetCopy.fds_bits[0] << std::endl;
	std::cout << "total fd : " << m_totalFd << std::endl;
	selectRet = select(m_totalFd + 1, &m_FdSetCopy, (fd_set*)0, (fd_set*)0, 0);
	if (selectRet < 0)
	{
		std::cout << "select error" << std::endl;
		return (false);
	}
	std::cout << "selected socket : " << selectRet << std::endl;
	return (true);
}

void WsServer::communicateSock(void)
{
	int serverFd;
	int clientFd;

	for (int fdIdx = 3; fdIdx < m_totalFd + 1; fdIdx++)
	{
		if (isServerSockSet(fdIdx))
		{
			serverFd = fdIdx - 3;
			WsClientSock clientSock(m_serverSock[serverFd]);
			clientSock.createSock();
			m_clientSock.push_back(clientSock);
			FD_SET(clientSock.getSocketFd(), &m_FdSet);
			if (m_totalFd < clientSock.getSocketFd())
				m_totalFd = clientSock.getSocketFd();
			std::cout << "total fd : "<< m_totalFd << std::endl;
			std::cout << "server client connected" << std::endl;
			// continue;
			// return ;
		}
		else if (isClientSockSet(fdIdx))
		{
			clientFd = fdIdx - m_maxServerFd - 1;
			std::cout << "client call to read " << clientFd << std::endl;
			std::vector<WsClientSock>::iterator clientIt = m_clientSock.begin() + clientFd;
			int readRet;

			readRet = (*clientIt).readSock();
			std::cout << "read return : " << readRet << std::endl;
			if (readRet <= 0)
			{
				std::cout << "read finish" << std::endl;
				(*clientIt).sendSock();
				(*clientIt).closeSock();
				m_clientSock.erase(clientIt);
				FD_CLR((*clientIt).getSocketFd(), &m_FdSet);
			}
			// readRet = (*clientIt).readSock();
			// std::cout << "read return : " << readRet << std::endl;
			// if (readRet <= 0)
			// {
			//     std::cout << "read finish" << std::endl;
			//     (*clientIt).sendSock();
			//     (*clientIt).closeSock();
			//     m_clientSock.erase(clientIt);
			//     FD_CLR((*clientIt).getSocketFd(), &m_FdSet);
			//     continue;
			// }
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
