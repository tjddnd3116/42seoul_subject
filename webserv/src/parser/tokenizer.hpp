#ifndef tokenizer_hpp
#define tokenizer_hpp

#include <string>
#include <sys/resource.h>
#include <vector>
#include <iostream>

#include "../WsConfigInfo.hpp"
#include "../WsException.hpp"

enum e_tokenType
{
	SERVER,
	OPEN_BRACE,
	CLOSE_BRACE,
	SERVER_CONTEXT,

	SERVER_DIRECTIVE,
	LOCATION,
	LOCATION_CONTEXT,
	LOCATION_DIRECTIVE,

	LISTEN,
	SERVER_NAME,
	ACCESS_LOG,
	ROOT,
	EXPRIES,
	UNEXEPCT_TYPE
};

class WsInitializer;

typedef struct	s_token
{
	std::string	str;
	e_tokenType	type;
}				t_token;

class tokenizer
{
	private:
		std::vector<t_token>	m_tokenVec;
		size_t					m_tokenIdx;

	public:
		tokenizer();
		~tokenizer();

		void		pushBackToken(const std::string& str);
		e_tokenType	selectTokenType(const std::string& str);
		void	 	parse(WsInitializer &initializer);
		void	 	serverParse(WsConfigInfo &wsConfigInfo);
		void		serverContextParse(WsConfigInfo &info);
};

#endif //tokenizer_hpp
