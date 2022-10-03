#ifndef WsRequest_hpp
#define WsRequest_hpp

#include <iostream>
#include <string>
#include <vector>

#include "WsGetMethod.hpp"
#include "WsPostMethod.hpp"
#include "WsPutMethod.hpp"

class WsRequest
{
		private:
			WsIMethod* m_method;

		public:
			WsRequest();
			~WsRequest();

			void				readRequest(const std::string& request);
			WsIMethod*			methodGenerator(const std::string& readLine);
			const WsIMethod*	getMethod(void) const;

			void				printRequest(void) const;
};
#endif //WsRequest_hpp
