#include "WsServer.hpp"
#include "socket/WsClientSock.hpp"
#include <sys/event.h>

WsServer::WsServer(const std::vector<WsConfigInfo> &conf)
	:m_conf(conf)
{
	m_serverSize = m_conf.size();
	m_kq = kqueue();
	if (m_kq < 0)
		throw (WsException("kqueue fail"));
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
		m_serverSock.insert(std::make_pair(serverSock.getSocketFd(), serverSock));
		addEvents(serverSock.getSocketFd(), EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
	}
	std::cout << "all server socket created" << std::endl;
}

void
WsServer::run(void)
{
	int newEvents;
	while (1)
	{
		newEvents = kevent();
		keventSock(newEvents);
	}
}

void
WsServer::addEvents(uintptr_t ident, int16_t filter, uint16_t flags, uint32_t fflags, intptr_t data, void* udata)
{
	struct kevent tempEvent;

	EV_SET(&tempEvent, ident, filter, flags, fflags, data, udata);
	m_changeList.push_back(tempEvent);
}

int
WsServer::kevent()
{
	int newEvents;

	std::cout << "waiting event" << std::endl;
	newEvents = ::kevent(m_kq, &m_changeList[0], m_changeList.size(),
			m_eventList, EVENT_SIZE, NULL);
	std::cout << "new events count : " << newEvents << std::endl;
	if (newEvents == -1)
		throw (WsException("kevent fail"));
	m_changeList.clear();
	return (newEvents);
}

void
WsServer::keventSock(int newEvents)
{
	for (int i = 0; i < newEvents; i++)
	{
		struct kevent* curEvent;

		curEvent = &m_eventList[i];
		std::cout << curEvent->ident << std::endl;
		std::cout << curEvent->filter << std::endl;
		if (curEvent->flags & EV_ERROR)
		{
			if (isServerSocket(curEvent->ident))
				throw (WsException("server socket fail"));
			if (isClientSocket(curEvent->ident))
				throw (WsException("client socket fail"));
		}
		else if (curEvent->filter == EVFILT_READ)
			readEvent(curEvent);
		else if (curEvent->filter == EVFILT_WRITE)
			writeEvent(curEvent);
	}
}

bool
WsServer::isServerSocket(int fd)
{
	if (m_serverSock.find(fd) != m_serverSock.end())
		return (true);
	return (false);
}

bool
WsServer::isClientSocket(int fd)
{
	if (m_clientSock.find(fd) != m_clientSock.end())
		return (true);
	return (false);
}

void
WsServer::readEvent(struct kevent* curEvent)
{
	if (isServerSocket(curEvent->ident))
	{
		WsClientSock clientSock(m_serverSock.at(curEvent->ident));

		clientSock.createSock();
		m_clientSock.insert(std::make_pair(clientSock.getSocketFd(), clientSock));
		addEvents(clientSock.getSocketFd(), EVFILT_READ,
				EV_ADD | EV_ENABLE, 0, 0, NULL);
		addEvents(clientSock.getSocketFd(), EVFILT_WRITE,
				EV_ADD | EV_ENABLE, 0, 0, NULL);
		std::cout << "client socket created" << std::endl;
	}
	else if(isClientSocket(curEvent->ident))
	{
		int readRet;

		std::map<int, WsClientSock>::iterator clientIt =
			m_clientSock.find(curEvent->ident);
		readRet = (*clientIt).second.readSock();
		if (readRet <= 0)
		{
			if (readRet < 0)
				std::cout << "client read error" << std::endl;
			disconnectClient(curEvent->ident);
		}
		std::cout << "client read finish" << std::endl;
	}
}

void
WsServer::writeEvent(struct kevent* curEvent)
{
	if (isClientSocket(curEvent->ident))
	{
		int sendRet;

		std::map<int, WsClientSock>::iterator clientIt =
			m_clientSock.find(curEvent->ident);
		sendRet = (*clientIt).second.sendSock();
		if (sendRet < 0)
		{
			std::cout << "client send error" << std::endl;
			disconnectClient(curEvent->ident);
		}
		else
		{
			std::cout << "client send finish" << std::endl;
			disconnectClient(curEvent->ident);
		}
	}
}

void WsServer::disconnectClient(int fd)
{
	std::cout << "client disconnected : " << fd << std::endl;
	m_clientSock.at(fd).closeSock();
	m_clientSock.erase(fd);
}
