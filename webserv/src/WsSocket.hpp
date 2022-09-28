#ifndef WsSocket_hpp
#define WsSocket_hpp

#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <sys/_endian.h>
#include <cstdio>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>

#include "WsException.hpp"
#include "WsConfigInfo.hpp"

#define BUFFER_SIZE 1024

class WsSocket
{
		private:
			struct sockaddr_in	m_SocketAddr;
			socklen_t			m_SocketAddrSize;
			int					m_SocketFd;
			char				m_buffer[BUFFER_SIZE];
			std::string			m_strBuffer;

		public:
			// Orthodox Canonical Form
			WsSocket();
			~WsSocket();
			WsSocket(const WsSocket& copy);
			WsSocket& operator=(const WsSocket &copy);


			// 서버 소켓 생성
			//
			// IPv4 프로토콜, SOCK_STREAM 인자로 생성
			//
			// address 재할당을 위한 setsockopt() 사용
			void	createSock(void);

			// void	initAddr(const struct configInfo &conf);

			void	bindSock(void);

			void	listenSock(void);

			void	acceptSock(const WsSocket &serverSock);

			void	readSock(const WsSocket &clientSock);

			void	sendSock();

			void	closeSock();

			void	setStrBuffer(const std::string &str);

};
#endif //WsSocket_hpp
