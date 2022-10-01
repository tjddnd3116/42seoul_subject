#include "WsInitializer.hpp"
#include "parser/configParser.hpp"

WsInitializer::WsInitializer()
{

}

WsInitializer::~WsInitializer()
{

}

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

	parser.initParser();
	WsConfigInfo::setTable();
	parser.parse(*this);
}

void		 WsInitializer::pushBack(WsConfigInfo &info)
{
	m_conf.push_back(info);
}

void		 WsInitializer::printConf(void)
{
	m_conf.back().printConf();
}

std::vector<WsConfigInfo> WsInitializer::getConfigInfo(void)
{
	return (m_conf);
}

