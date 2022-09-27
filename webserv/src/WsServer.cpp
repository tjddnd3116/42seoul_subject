#include "WsServer.hpp"
#include "WsSocket.hpp"

WsServer::WsServer(struct configInfo conf)
{
	m_conf = conf;
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

WsSocket
WsServer::createServerSock(void)
{
	WsSocket serverSock;

	serverSock.createSock();
	serverSock.initAddr(m_conf);
	serverSock.bindSock();
	serverSock.listenSock();
	return (serverSock);
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
	WsSocket serverSock = createServerSock();
	WsSocket clientSock = createClientSock();

	while (1)
	{
		std::cout << "waiting for client connection" << std::endl;
		clientSock.acceptSock(serverSock);
		serverSock.readSock(clientSock);
		clientSock.sendSock();
		clientSock.closeSock();
	}
}

