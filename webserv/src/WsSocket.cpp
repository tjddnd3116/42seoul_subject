#include "WsSocket.hpp"
#include "WsException.hpp"

WsSocket::WsSocket()
{
	m_SocketAddrSize = sizeof(m_SocketAddr);
}

WsSocket::~WsSocket()
{
}

WsSocket::WsSocket(const WsSocket& copy)
{
	*this = copy;
}

WsSocket&
WsSocket::operator=(const WsSocket& copy)
{
	m_SocketAddr = copy.m_SocketAddr;
	m_SocketFd = copy.m_SocketFd;
	m_SocketAddrSize = copy.m_SocketAddrSize;
	return (*this);
}

void
WsSocket::createSock(void)
{
	m_SocketFd = socket(AF_INET, SOCK_STREAM, 0);
	if (m_SocketFd == -1)
		throw WsException("create socket fail");
	else
		std::cout << "create socket success!" << std::endl;;
}

void
WsSocket::initAddr(const struct configInfo& conf)
{
	std::memset(&m_SocketAddr, 0, sizeof(m_SocketAddr));
	m_SocketAddr.sin_family = AF_INET;
	m_SocketAddr.sin_port = htons(conf.m_listenPort);
	m_SocketAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	std::cout << "init socket address success!" << std::endl;
}

void
WsSocket::bindSock(void)
{
	int bindRet;

	bindRet = bind(m_SocketFd, (const struct sockaddr*)&m_SocketAddr, sizeof(m_SocketAddr));
	if (bindRet == -1)
		throw WsException("bind socket fail");
	else
		std::cout << "bind socket success!" << std::endl;;
}

void
WsSocket::listenSock(void)
{
	int listenRet;

	listenRet = listen(m_SocketFd, 5);
	if (listenRet == -1)
		throw WsException("listen socket fail");
	else
		std::cout << "listen socket success!" << std::endl;
}

void WsSocket::acceptSock(const WsSocket &serverSock)
{
	m_SocketFd = accept(serverSock.m_SocketFd, (struct sockaddr*)&m_SocketAddr, &m_SocketAddrSize);
	if (m_SocketFd < 0)
		throw WsException("accept socket fail");
	else
		std::cout << "accept socket success!" << std::endl;;
}

void WsSocket::readSock(const WsSocket &clientSock)
{
	int readRet;
	std::string strBuffer;

	std::memset(m_buffer, 0, sizeof(m_buffer));
	readRet = read(clientSock.m_SocketFd, m_buffer, BUFFER_SIZE);
	if (readRet < 0)
	{
		close(clientSock.m_SocketFd);
		throw WsException("read socket fail");
	}
	else
	{
		strBuffer = m_buffer;
		std::cout << "read : "<< m_buffer << std::endl;
	}
	std::cout << "read socekt success!" << std::endl;
}

void WsSocket::sendSock()
{
	send(m_SocketFd, m_strBuffer.c_str(), m_strBuffer.size() + 1, 0);
	std::cout << "send socket success!" << std::endl;
}

void WsSocket::setStrBuffer(const std::string &str)
{
	m_strBuffer = str;
}

void WsSocket::closeSock()
{
	close(m_SocketFd);
	std::cout << "close socket success!" << std::endl;
}

