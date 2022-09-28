#ifndef WsServer_hpp
#define WsServer_hpp

#include <sys/socket.h>
#include <netinet/in.h>

#include "WsInitializer.hpp"
#include "WsSocket.hpp"

class WsServer
{
		private:
			// member variable
			// struct configInfo m_conf;

		public:
			// Orthodox Canonical Form
			WsServer(struct configInfo conf);
			~WsServer();
			WsServer(const WsServer& copy);
			WsServer& operator=(const WsServer& copy);

			WsSocket createServerSock(void);
			WsSocket createClientSock(void);
			void run(void);

};
#endif //WsServer_hpp
