#ifndef WsInitializer_hpp
#define WsInitializer_hpp

#include <string>
#include <fstream>
#include <vector>

#include "WsException.hpp"
#include "WsSocket.hpp"
#include "WsConfigInfo.hpp"
#include "./parser/configParser.hpp"

#define BUFFER_SIZE 1024

// typedef struct

class WsInitializer
{
		private:
			// member variable
			std::vector<WsConfigInfo>	m_conf;

		public:
			// Orthodox Canonical Form
			WsInitializer();
			~WsInitializer();
			WsInitializer(const WsInitializer& copy);
			WsInitializer	operator=(const WsInitializer& copy);

			void			parseConfig(const char* path);
			void			pushBack(WsConfigInfo &info);
			void			printConf(void);
};
#endif //WsInitializer_hpp
