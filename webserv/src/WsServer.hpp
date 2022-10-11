#ifndef WsServer_hpp
#define WsServer_hpp

#include <sys/event.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <map>
#include <vector>
#include <iostream>

#include "WsInitializer.hpp"
#include "./parser/WsConfigInfo.hpp"
#include "./socket/WsClientSock.hpp"
#include "./socket/WsServerSock.hpp"

class WsServer
{
	private:
		// member variable
		std::vector<WsConfigInfo>	m_conf;
		std::map<int, WsServerSock>	m_serverSocket;
		std::map<int, WsClientSock>	m_clientSocket;

		size_t						m_serverSize;
		fd_set						m_FdSet;
		fd_set						m_FdSetCopy;
		int							m_maxServerFd;
		int							m_totalFd;

		void	initFdSet(void);
		int		selectSock(void);
		void	communicateSock(void);
		bool	isServerSockSet(int fdIdx);
		bool	isClientSockSet(int fdIdx);
		// void	isClientSockEof(void);

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
