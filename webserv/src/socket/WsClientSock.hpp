#ifndef WsClientSock_hpp
#define WsClientSock_hpp

#include "../parser/WsConfigInfo.hpp"
#include "WsASocket.hpp"
#include "WsRequest.hpp"
#include "WsResponse.hpp"

class WsClientSock : public WsASocket
{
	private:
		WsRequest	m_request;
		WsResponse	m_response;

	public:
		WsClientSock(const WsConfigInfo& conf);
		WsClientSock(const WsASocket& serverSock);
		~WsClientSock();
		WsClientSock(const WsClientSock& copy);
		WsClientSock& operator=(const WsClientSock& copy);

		void	createSock(void);
		int		readSock(void);
		int		sendSock(void);
};
#endif //WsClientSock_hpp
