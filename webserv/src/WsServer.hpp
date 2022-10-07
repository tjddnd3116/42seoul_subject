#ifndef WsServer_hpp
#define WsServer_hpp

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/_select.h>
#include <vector>

#include "WsInitializer.hpp"
#include "./parser/WsConfigInfo.hpp"
#include "./socket/WsClientSock.hpp"
#include "./socket/WsServerSock.hpp"

class WsServer
{
	private:
		// member variable
		std::vector<WsConfigInfo>	m_conf;
		std::vector<WsServerSock>	m_serverSock;
		std::vector<WsClientSock>	m_clientSock;
		size_t						m_serverSize;

		fd_set						m_FdSet;
		fd_set						m_FdSetCopy;
		int							m_maxServerFd;

		void	initFdSet(void);
		bool	selectSock(void);
		void	communicateSock(void);

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
