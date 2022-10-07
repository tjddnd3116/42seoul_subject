#include "WsServer.hpp"

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
		std::cout << "fd :" << serverSock.getSocketFd() << std::endl;
	}
	m_maxServerFd = m_serverSock.back().getSocketFd();
}

void
WsServer::run(void)
{
	std::cout << m_FdSet.fds_bits[0] << std::endl;
	initFdSet();
	std::cout << m_FdSet.fds_bits[0] << std::endl;
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

	std::cout << std::endl << "waiting socket to select" << std::endl;
	selectRet = select(m_maxServerFd + 1, &m_FdSetCopy, (fd_set*)0, (fd_set*)0, NULL);
	if (selectRet < 0)
	{
		std::cout << "select error" << std::endl;
		return (false);
	}
	std::cout << "selected socket" << std::endl;
	return (true);
}

void WsServer::communicateSock(void)
{
	int serverFd;

	for (int fdIdx = 3; fdIdx < m_maxServerFd + 1; fdIdx++)
	{
		if (FD_ISSET(fdIdx, &m_FdSetCopy))
		{
			serverFd = fdIdx - 3;
			WsClientSock clientSock(m_serverSock[serverFd]);
			std::cout << "server socket fd : " << m_serverSock[serverFd].getSocketFd() << std::endl;
			clientSock.createSock();
			if (clientSock.readSock() > 0)
			{
				clientSock.sendSock();
				clientSock.closeSock();
			}
		}
	}
}

