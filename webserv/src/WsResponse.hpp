#ifndef WsResponse_hpp
#define WsResponse_hpp

#include <string>
#include <fstream>

#include "WsIMethod.hpp"
#include "WsConfigInfo.hpp"

class WsResponse
{
	private:
		std::fstream			m_file;
		std::string				m_responseBuf;
		const WsIMethod*		m_method;
		WsConfigInfo			m_conf;
		int						m_statusCode;

		void	makeHeader(void);
	public:
		WsResponse(const WsConfigInfo& conf);
		~WsResponse();

		void	readFile(void);
		void	makeResponse(const WsIMethod* method);
		size_t	getBufSize(void) const;

		const std::string& operator()(void);
};
#endif //WsResponse_hpp
