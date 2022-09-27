#include "WsInitializer.hpp"
#include "WsException.hpp"

WsInitializer::WsInitializer(char *path)
{
	(void)path;
	m_conf.m_listenPort = 4001;
	m_conf.m_rootPath = "./html";
	m_conf.m_indexFile = "index.html";
	m_conf.m_serverName = "webserv";
}

WsInitializer::~WsInitializer()
{}

WsInitializer::WsInitializer(const WsInitializer& copy)
{
	*this = copy;
}

WsInitializer
WsInitializer::operator=(const WsInitializer& copy)
{
	m_conf = copy.m_conf;
	return (*this);
}

struct configInfo
WsInitializer::getConfigInfo(void) const
{
	return (m_conf);
}
