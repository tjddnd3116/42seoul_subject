#include "WsClientSock.hpp"
#include "WsConfigInfo.hpp"

WsClientSock::WsClientSock(const WsConfigInfo& conf)
	:WsASocket(conf), m_response(conf)
{}

WsClientSock::~WsClientSock()
{}

void WsClientSock::createSock(void)
{
	setStrBuffer("HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!");
}

void WsClientSock::acceptSock(const WsASocket &serverSock)
{

	std::cout << "wait accept" << std::endl;
	m_SocketFd = accept(serverSock.getSocketFd(), (struct sockaddr*)&m_SocketAddr, &m_SocketAddrSize);
	// fcntl(m_SocketFd, F_SETFL, O_NONBLOCK);
	if (m_SocketFd < 0)
		throw WsException("accept socket fail");
	std::cout << "accept finish" << std::endl;
}

int WsClientSock::readSock()
{
	int readRet;

	std::memset(m_buffer, 0, sizeof(m_buffer));
	//TODO : change to recv
	std::cout << "before read" << std::endl;
	readRet = recv(m_SocketFd, m_buffer, BUFFER_SIZE, O_NONBLOCK);
	if (readRet < 0)
	{
		closeSock();
		return (readRet);
		std::cout << readRet << " : read fail" << std::endl;
		// throw WsException("read socket fail");
	}
	else
	{
		m_request.readRequest(m_buffer);
		m_request.printRequest();
	}
	return (readRet);
}

void WsClientSock::sendSock()
{
	int sendRet;

	if (m_request.getMethod() == NULL)
		std::cout << "get method is null" << std::endl;
	m_response.makeResponse(m_request.getMethod());
	std::cout << m_response().c_str() << std::endl;
	sendRet = send(m_SocketFd, m_response().c_str(), m_response.getBufSize() + 1, 0);
}

