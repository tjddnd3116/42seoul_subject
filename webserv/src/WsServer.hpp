#ifndef WsServer_hpp
#define WsServer_hpp

#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/_select.h>
#include <vector>

#include "WsConfigInfo.hpp"
#include "WsInitializer.hpp"
#include "WsClientSock.hpp"
#include "WsServerSock.hpp"

class WsServer
{
		private:
			// member variable
			std::vector<WsConfigInfo>	m_conf;
			std::vector<WsServerSock>	m_serverSock;
			size_t						m_serverSize;

		public:
			// Orthodox Canonical Form
			WsServer(const std::vector<WsConfigInfo>& conf);
			~WsServer();
			WsServer(const WsServer& copy);
			WsServer& operator=(const WsServer& copy);

			void		createServerSock(void);
			void 		run(void);
};
#endif //WsServer_hpp
