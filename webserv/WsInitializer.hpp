#ifndef WsInitializer_hpp
#define WsInitializer_hpp

#include <string>
#include <fcntl.h>
#include <sys/fcntl.h>
#include <fstream>
#include <vector>

#include "configParser.hpp"
#include "WsException.hpp"

class WsInitializer
{
		private:
			// member variable
			std::vector<std::string>	_configTypes;
			std::string					_rootPath;
			std::string					_indexFile;
			std::string					_serverName;
			int							_listenPort;

			// member functions for config
			std::string
			getConfigInfo(std::ifstream &configFile);

			std::string
			checkConfigInfo(void) const;

			std::vector<std::string>
			loadConfigTypes(void) const;

			void
			loadConfigInfo(const std::vector<std::string> &info);

			std::vector<std::string>
			splitGetLine(const std::string &line);

		public:
			// constructor
			WsInitializer(char *path);

			// destructor
			~WsInitializer();
};
#endif //WsInitializer_hpp
