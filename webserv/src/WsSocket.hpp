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

#define BUFFER_SIZE 1024

struct configInfo
{
	std::string m_rootPath;
	std::string	m_indexFile;
	std::string	m_serverName;
	int			m_listenPort;
};

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
			// AF_INET : IPv4 인터넷 프로토콜
			//
			// SOCK_STREAM : 순차적, 신뢰할수 있는 양방향 바이트 스트림 연결
			//
			// 0 : 소켓과 함께 사용될 특정 프로토콜을 지정
			//
			// -0으로 지정하면 운영체제는 가장 적절한 프로토콜을 선택함
			//
			// -스트림 소켓에는 TCP를 선택하고 데이터그램 소켓은 UDP를 선택함
			void	createSock(void);

			void	initAddr(const struct configInfo &conf);

			void	bindSock(void);

			void	listenSock(void);

			void	acceptSock(const WsSocket &serverSock);

			void	readSock(const WsSocket &clientSock);

			void	sendSock();

			void	closeSock();

			void	setStrBuffer(const std::string &str);

};
#endif //WsSocket_hpp
