#ifndef WsInitializer_hpp
#define WsInitializer_hpp

#include <string>
#include <fstream>

#include "WsException.hpp"
#include "WsSocket.hpp"

class WsInitializer
{
		private:
			// member variable
			struct configInfo	m_conf;

		public:
			// Orthodox Canonical Form
			WsInitializer(char *path);
			~WsInitializer();
			WsInitializer(const WsInitializer& copy);
			WsInitializer	operator=(const WsInitializer& copy);

			struct configInfo getConfigInfo(void) const;

};
#endif //WsInitializer_hpp
