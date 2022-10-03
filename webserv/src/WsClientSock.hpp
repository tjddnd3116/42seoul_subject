#ifndef WsClientSock_hpp
#define WsClientSock_hpp

#include "WsASocket.hpp"
#include "WsConfigInfo.hpp"
#include "WsRequest.hpp"
#include "WsResponse.hpp"

class WsClientSock : public WsASocket
{
	private:
		WsRequest	m_request;
		WsResponse	m_response;

	public:
		WsClientSock(const WsConfigInfo& conf);
		~WsClientSock();

		void	createSock(void);
		void	acceptSock(const WsASocket &serverSock);
		int		readSock();
		void	sendSock();
};
#endif //WsClientSock_hpp
