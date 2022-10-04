#include "WsInitializer.hpp"
#include "parser/configParser.hpp"

WsInitializer::WsInitializer()
{}

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

void
WsInitializer::parseConfig(const char* path)
{
	configParser	parser(path);
	WsConfigInfo::setTable();

	parser.initParser();
	parser.parse(*this);
}

void		 WsInitializer::pushBack(WsConfigInfo &info)
{
	m_conf.push_back(info);
}

std::vector<WsConfigInfo> WsInitializer::getConfigInfo(void)
{
	return (m_conf);
}

