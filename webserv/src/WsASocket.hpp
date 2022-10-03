#ifndef WsASocket_hpp
#define WsASocket_hpp

#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <sys/_endian.h>
#include <cstdio>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <fcntl.h>

#include "WsException.hpp"
#include "WsConfigInfo.hpp"

#define BUFFER_SIZE 1024

class WsASocket
{
		protected:
			WsConfigInfo		m_conf;
			struct sockaddr_in	m_SocketAddr;
			socklen_t			m_SocketAddrSize;
			int					m_SocketFd;
			char				m_buffer[BUFFER_SIZE];
			std::string			m_strBuffer;

		public:
			// Orthodox Canonical Form
			WsASocket(const WsConfigInfo& conf);
			virtual ~WsASocket();
			WsASocket(const WsASocket& copy);
			WsASocket& operator=(const WsASocket &copy);


			virtual void		createSock(void) = 0;
			void				closeSock();
			void				setStrBuffer(const std::string &str);
			int					getSocketFd(void) const;
			const WsConfigInfo&	getConf(void) const;
};

#endif //WsSocket_hpp
