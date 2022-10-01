#ifndef WsServer_hpp
#define WsServer_hpp

#include <sys/socket.h>
#include <netinet/in.h>
#include <vector>

#include "WsConfigInfo.hpp"
#include "WsInitializer.hpp"
#include "WsSocket.hpp"

class WsServer
{
		private:
			// member variable
			std::vector<WsConfigInfo>	m_conf;
			std::vector<WsSocket>		m_serverSock;
			size_t						m_serverSize;

		public:
			// Orthodox Canonical Form
			WsServer(const std::vector<WsConfigInfo>& conf);
			~WsServer();
			WsServer(const WsServer& copy);
			WsServer& operator=(const WsServer& copy);

			void		createServerSock(void);
			WsSocket	createClientSock(void);
			void 		run(void);
			// void		waitingClient(size_t sockIdx);

};
#endif //WsServer_hpp
