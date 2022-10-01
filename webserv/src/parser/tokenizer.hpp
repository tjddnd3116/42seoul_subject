#ifndef tokenizer_hpp
#define tokenizer_hpp

#include <string>
#include <sys/resource.h>
#include <vector>
#include <iostream>
#include <exception>

#include "../WsConfigInfo.hpp"
#include "../WsException.hpp"

enum e_tokenType
{
	SERVER,
	OPEN_BRACE,
	CLOSE_BRACE,
	SERVER_CONTEXT,
	SEMICOLON
};

class WsInitializer;

typedef struct	s_token
{
	std::string line;
	std::string	str;
	e_tokenType	type;
	size_t		lineNum;
}				t_token;

class tokenizer
{
	private:
		std::vector<t_token>	m_tokVec;
		size_t					m_tokIdx;

	public:
		tokenizer();
		~tokenizer();

		void		pushBackToken(t_token token);
		e_tokenType	selectTokenType(const std::string& str);
		void	 	parseToken(WsInitializer &initializer);
		void	 	serverParse(WsConfigInfo &wsConfigInfo);
		void		serverContextParse(WsConfigInfo &info);
		void		locationContextParse(WsConfigInfo &info);
		void		locationParse(WsConfigInfo &info);
		bool		verifyInfo(WsConfigInfo& info);
		bool		isSafeIdx(void);
};

#endif //tokenizer_hpp
