#include "tokenizer.hpp"
#include "../WsInitializer.hpp"

tokenizer::tokenizer()
{
	m_tokenIdx = 0;
}

tokenizer::~tokenizer()
{

}


void
tokenizer::pushBackToken(const std::string& str)
{
	if (str == "")
		return ;
	t_token token;

	token.str = str;
	token.type = selectTokenType(token.str);
	m_tokenVec.push_back(token);
}

e_tokenType
tokenizer::selectTokenType(const std::string& str)
{
	if (str == "server")
		return (SERVER);
	else if (str == "{")
		return (OPEN_BRACE);
	else if (str == "}")
		return (CLOSE_BRACE);
	else
		return (SERVER_CONTEXT);
}

void	 tokenizer::parse(WsInitializer &initializer)
{
	WsConfigInfo::setTable();

	while (m_tokenIdx != m_tokenVec.size() && m_tokenVec[m_tokenIdx].type == SERVER)
	{
		WsConfigInfo info;
		serverParse(info);
		// TODO
		// if (verifyInfo(info) == false)
		//     throw WsException("error");
		initializer.pushBack(info);
		initializer.printConf();
	}
	if (m_tokenIdx != m_tokenVec.size())
		throw WsException(std::string(__func__) + ": \"" + m_tokenVec[m_tokenIdx].str + "\"");

}

void	 tokenizer::serverParse(WsConfigInfo &info)
{
	m_tokenIdx++;
	if (m_tokenVec[m_tokenIdx].type == OPEN_BRACE)
		serverContextParse(info);
	if (m_tokenVec[m_tokenIdx].type != CLOSE_BRACE)
		throw WsException(std::string(__func__) + ": \"" + m_tokenVec[m_tokenIdx].str + "\"");
	else
		++m_tokenIdx;
}

void	 tokenizer::serverContextParse(WsConfigInfo &info)
{
	std::vector<std::string>	tokenSet;

	m_tokenIdx++;
	while (m_tokenVec[m_tokenIdx].type == SERVER_CONTEXT)
	{
		std::string &tokenStr = m_tokenVec[m_tokenIdx++].str;

		if (WsConfigInfo::s_table[tokenStr] == 0)
			break;
		tokenSet.clear();
		while (m_tokenVec[m_tokenIdx].str.back() != ';')
			tokenSet.push_back(m_tokenVec[m_tokenIdx++].str);
		tokenSet.push_back(m_tokenVec[m_tokenIdx++].str);
		(info.*(WsConfigInfo::s_table[tokenStr]))(tokenSet);
	}
}

