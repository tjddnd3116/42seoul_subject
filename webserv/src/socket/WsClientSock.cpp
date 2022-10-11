#include "WsClientSock.hpp"
#include "WsASocket.hpp"
#include <sys/fcntl.h>
#include <sys/socket.h>

WsClientSock::WsClientSock(const WsConfigInfo& conf)
	:WsASocket(conf), m_response(conf)
{}

WsClientSock::WsClientSock(const WsASocket& serverSock)
	:WsASocket(serverSock.getConf()), m_response(serverSock.getConf())
{
	m_SocketFd = serverSock.getSocketFd();
}

WsClientSock::~WsClientSock()
{}

WsClientSock::WsClientSock(const WsClientSock& copy)
	:WsASocket(copy.m_conf), m_response(copy.m_response)
{
	*this = copy;
}

WsClientSock&
WsClientSock::operator=(const WsClientSock& copy)
{
	m_conf = copy.m_conf;
	m_SocketAddr = copy.m_SocketAddr;
	m_SocketAddrSize = copy.m_SocketAddrSize;
	m_SocketFd = copy.m_SocketFd;
	m_strBuffer = copy.m_strBuffer;
	m_request = copy.m_request;
	m_response = copy.m_response;
	return (*this);
}


void WsClientSock::createSock(void)
{
	int opts;

	m_SocketFd = accept(m_SocketFd, (struct sockaddr*)&m_SocketAddr,
			&m_SocketAddrSize);
	opts = fcntl(m_SocketFd, F_SETFL);
	opts = (opts | O_NONBLOCK);
	fcntl(m_SocketFd, F_SETFL, opts);
	if (m_SocketFd < 0)
		throw WsException("create(accept) socket fail");
	std::cout << "created(accept) client socket : " << m_SocketFd << std::endl;

}

int WsClientSock::readSock(void)
{
	int readRet;

	std::memset(m_buffer, 0, sizeof(m_buffer));
	readRet = read(m_SocketFd, m_buffer, BUF_SIZE);
	if (readRet < 0)
		std::cout << "non-blocking" << std::endl;
	else if (readRet == 0)
		std::cout << "client socket close!" << std::endl;
	else
	{
		m_request.readRequest(m_buffer);
		m_request.printRequest();
	}
	return (readRet);
}

void WsClientSock::sendSock(void)
{
	if (m_request.getMethod() == NULL)
	{
		std::cout << "get method is null" << std::endl;
		return;
	}
	m_response.makeResponse(m_request.getMethod());
	std::cout << BLUE << "-----------response----------------" << std::endl;
	std::cout << m_response().c_str() << std::endl;
	std::cout << "-------------------------------" << RESET << std::endl;
	send(m_SocketFd, m_response().c_str(), m_response.getBufSize(), 0);
}
