#include "WsConfigInfo.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

std::unordered_map<std::string, WsConfigInfo::t_getterType>	WsConfigInfo::s_table;

WsConfigInfo::WsConfigInfo()
{
	/*
	m_rootPath = "";
	m_indexFile = "";
	m_serverName = "";
	m_listenPort = 0;
	*/
}

WsConfigInfo::~WsConfigInfo()
{

}

// TODO: location
void	WsConfigInfo::setTable()
{
	s_table["root"] = &WsConfigInfo::getRootPath;
	s_table["index"] = &WsConfigInfo::getIndexFile;
	s_table["server_name"] = &WsConfigInfo::getServerName;
	s_table["listen"] = &WsConfigInfo::getListenPort;
}

// TODO: push_back
void	WsConfigInfo::getRootPath(std::vector<std::string>& set)
{
	m_rootPath = set;
}

void	WsConfigInfo::getIndexFile(std::vector<std::string>& set)
{
	m_indexFile = set;
}

void	WsConfigInfo::getServerName(std::vector<std::string>& set)
{
	m_serverName = set;
}

void	WsConfigInfo::getListenPort(std::vector<std::string>& set)
{
	m_listenPort.push_back(atoi(set[0].c_str()));
}

void WsConfigInfo::printConf()
{
	std::cout << "root : " << m_rootPath[0] << ", " << m_rootPath[1] << std::endl;
	std::cout << "index : " << m_indexFile[0] << ", " << m_indexFile[1] << std::endl;
	std::cout << "servername : " << m_serverName[0] << ", " << m_serverName[1] << std::endl;
	std::cout << "listen : " << m_listenPort[0] << std::endl;
}

