#include "WsInitializer.hpp"
#include "WsException.hpp"

WsInitializer::WsInitializer(char *path)
{

	(void)path;
	// std::ifstream	configFile(path);
	std::string		errStatus;

	// if (configFile.fail())
	//     throw (WsException("open() error occured!"));
	_listenPort = 4000;
	_rootPath = "./html";
	_indexFile = "index.html";
	_serverName = "webserv";
	// _configTypes = loadConfigTypes();
	// if ((errStatus = getConfigInfo(configFile)) != "")
	//     throw (WsException("invalid config info : " + errStatus));
}

WsInitializer::~WsInitializer()
{}


std::string
WsInitializer::getConfigInfo(std::ifstream &configFile)
{
	if (configFile.is_open())
	{
		std::string line;
		while (std::getline(configFile, line))
			loadConfigInfo(splitGetLine(line));
	}
	return (checkConfigInfo());
}

std::string
WsInitializer::checkConfigInfo(void) const
{
	if (_rootPath == "")
		return ("root path");
	if (_indexFile == "")
		return ("index file");
	if (_serverName == "")
		return ("server name");
	if (_listenPort == -1)
		return ("listen port");
	return ("");
}

std::vector<std::string>
WsInitializer::loadConfigTypes(void) const
{
	std::vector<std::string> tmpVec;

	// tmpVec.push_back("server");
	tmpVec.push_back("listen");
	tmpVec.push_back("root");
	tmpVec.push_back("index");
	tmpVec.push_back("server_name");
	tmpVec.push_back("location");
	return (tmpVec);
}

void
WsInitializer::loadConfigInfo(const std::vector<std::string> &info)
{
	(void)info;
}

std::vector<std::string>
WsInitializer::splitGetLine(const std::string &line)
{
	std::vector<std::string> retVec;
	std::string key;
	std::string value;
	std::string tmpLine(line);
	size_t found;
	std::vector<std::string>::iterator vecIt;

	vecIt = _configTypes.begin();
	for (; vecIt != _configTypes.end(); vecIt++ )
	{
		found = tmpLine.find_first_of(*vecIt);
		if (found != std::string::npos)
		{
			key = *vecIt;
		}
	}
	return (retVec);
}

