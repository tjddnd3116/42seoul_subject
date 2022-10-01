#include "WsServer.hpp"
#include "WsSocket.hpp"
#include <sys/_select.h>

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
	for (size_t sockIdx = 0; sockIdx < m_serverSize; sockIdx++)
	{
		WsSocket serverSock;

		serverSock.createSock();
		serverSock.initAddr(m_conf[sockIdx]);
		serverSock.bindSock();
		serverSock.listenSock();
		m_serverSock.push_back(serverSock);
	}
}

WsSocket WsServer::createClientSock(void)
{
	WsSocket clientSock;

	clientSock.setStrBuffer("HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!");
	return (clientSock);
}

void
WsServer::run(void)
{
	fd_set serverFdSet;
	fd_set tmp;

	FD_ZERO(&serverFdSet);
	for (size_t sockIdx = 0; sockIdx < m_serverSize; sockIdx++)
		FD_SET(sockIdx, &serverFdSet);

	for (size_t sockIdx = 0; sockIdx < m_serverSize; sockIdx++)
		if (FD_ISSET(sockIdx, &serverFdSet))
			std::cout << sockIdx << " set" << std::endl;

	while (1)
	{
		tmp = serverFdSet;

		if (select(m_serverSize + 1, &tmp, NULL, NULL, NULL) < 0)
			std::cout << "error" << std::endl;
		for (size_t i = 0; i < m_serverSize; i++)
		{
			std::cout << i << " " << serverFdSet.fds_bits[i] << std::endl;
			if (FD_ISSET(i, &tmp))
			{
				std::cout << "set bit :" << i << std::endl;
				if (m_serverSock[i].m_SocketFd == serverFdSet.fds_bits[i])
				{
					WsSocket clientSock = createClientSock();
					clientSock.acceptSock(m_serverSock[i]);
					m_serverSock[i].readSock(clientSock);
					clientSock.sendSock();
					clientSock.closeSock();
				}
			}
		}
		// for (size_t sockIdx = 0; sockIdx < m_serverSize; sockIdx++)
		// {
		//     WsSocket clientSock = createClientSock();
		//     std::cout << "socket index : " << sockIdx + 1 << std::endl;
		//     std::cout << "waiting for client connection" << std::endl;
        //
		//     clientSock.acceptSock(m_serverSock[sockIdx]);
		//     m_serverSock[sockIdx].readSock(clientSock);
		//     clientSock.sendSock();
		//     clientSock.closeSock();
		// }
	}
}

// void	 WsServer::waitingClient(size_t sockIdx)
// {
//     WsSocket clientSock = createClientSock();
//     while (1)
//     {
//         std::cout << "socket index : " << sockIdx + 1 << std::endl;
//         std::cout << "waiting for client connection" << std::endl;
//
//         clientSock.acceptSock(m_serverSock[sockIdx]);
//         m_serverSock[sockIdx].readSock(clientSock);
//         clientSock.sendSock();
//         clientSock.closeSock();
//     }
// }
