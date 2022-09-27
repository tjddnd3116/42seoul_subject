#ifndef WsException_hpp
#define WsException_hpp

#include <exception>
#include <string>

class WsException : public std::exception
{
		private:
			std::string m_errMsg;

		public:
			WsException(const std::string &errMsg);
			~WsException() throw();

			const char *what() const throw();
};
#endif //WsException_hpp
