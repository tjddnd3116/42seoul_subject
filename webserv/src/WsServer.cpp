#include "WsServer.hpp"
#include "WsClientSock.hpp"
#include "WsServerSock.hpp"

WsServer::WsServer(const std::vector<WsConfigInfo> &conf)
	:m_conf(conf)
{
	m_serverSize = m_conf.size();
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
}

void
WsServer::run(void)
{
	int changedFdCnt;

	int maxFd = 0;
	fd_set readSet;
	fd_set readSetOrig;

	FD_ZERO(&readSet);
	FD_ZERO(&readSetOrig);

	maxFd = m_serverSock.back().getSocketFd();
	for (size_t idx = 0; idx < m_serverSize; idx++)
		FD_SET(m_serverSock[idx].getSocketFd(), &readSetOrig);
	while (1)
	{
		readSet = readSetOrig;
		std::cout << "before socket selected" << std::endl;
		changedFdCnt = select(maxFd + 1, &readSet, (fd_set*)0, (fd_set*)0, NULL);
		if (changedFdCnt < 0)
		{
			std::cout << "error" << std::endl;
			break;
		}
		std::cout << "socket selected" << std::endl;
		for (int socketIdx = 0; socketIdx < maxFd + 1; socketIdx++)
		{
			if (FD_ISSET(socketIdx, &readSet))
			{
				WsClientSock clientSock(m_serverSock[socketIdx - 3].getConf());
				clientSock.createSock();
				std::cout << "clientSock created" << std::endl;
				std::cout << "socket index : " << socketIdx << std::endl;
				clientSock.acceptSock(m_serverSock[socketIdx - 3]);
				if (clientSock.readSock() > 0)
				{
					clientSock.sendSock();
					clientSock.closeSock();
				}
			}
		}
	}
}
