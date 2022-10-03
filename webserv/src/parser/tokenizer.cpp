#include "tokenizer.hpp"
#include "../WsInitializer.hpp"
#include <exception>

tokenizer::tokenizer()
{
	m_tokIdx = 0;
}

tokenizer::~tokenizer()
{}

void
tokenizer::pushBackToken(t_token token)
{
	if (token.str == "")
		return ;
	token.type = selectTokenType(token.str);
	m_tokVec.push_back(token);
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
	else if (str == ";")
		return (SEMICOLON);
	else
		return (SERVER_CONTEXT);
}

void
tokenizer::parseToken(WsInitializer &initializer)
{
	while (m_tokIdx != m_tokVec.size() && m_tokVec[m_tokIdx].type == SERVER)
	{
		WsConfigInfo info;

		serverParse(info);
		verifyInfo(info);
		initializer.pushBack(info);
	}
	if (m_tokIdx != m_tokVec.size())
		throw WsException(m_tokVec[m_tokIdx].lineNum, "invaild server");
}

void
tokenizer::serverParse(WsConfigInfo &info)
{
	m_tokIdx++;
	if (isSafeIdx() && m_tokVec[m_tokIdx].type == OPEN_BRACE)
		serverContextParse(info);
	else
		throw WsException(m_tokVec[m_tokIdx - 1].lineNum, "miss '{' - server");

	if (!isSafeIdx())
		throw WsException(m_tokVec[m_tokIdx].lineNum + 1, "miss '}' - server");
	else if (m_tokVec[m_tokIdx].type != CLOSE_BRACE)
		throw WsException(m_tokVec[m_tokIdx].lineNum + 1, "miss '}' - server");
	else
		m_tokIdx++;
}

void
tokenizer::serverContextParse(WsConfigInfo &info)
{
	std::vector<std::string>	tokenSet;
	size_t						optionLineNum;

	m_tokIdx++;
	while (m_tokIdx < m_tokVec.size() && m_tokVec[m_tokIdx].type == SERVER_CONTEXT)
	{
		if (m_tokVec[m_tokIdx].str == "location")
		{
			locationParse(info);
			continue ;
		}
		optionLineNum = m_tokVec[m_tokIdx].lineNum;
		std::string &tokenStr = m_tokVec[m_tokIdx++].str;
		if (WsConfigInfo::s_table[tokenStr] == 0)
			throw WsException(m_tokVec[m_tokIdx - 1].lineNum, "invaild server option");
		else if (!isSafeIdx())
			throw WsException(m_tokVec[m_tokIdx].lineNum, "2???");
		tokenSet.clear();
		while (isSafeIdx() && m_tokVec[m_tokIdx].str.back() != ';')
			tokenSet.push_back(m_tokVec[m_tokIdx++].str);

		if (m_tokVec[m_tokIdx].lineNum != optionLineNum)
			throw WsException(optionLineNum, "miss ';'");

		if (m_tokVec[m_tokIdx].type == SEMICOLON)
			m_tokIdx++;
		else if (m_tokVec[m_tokIdx].str.back() == ';')
		{
			m_tokVec[m_tokIdx].str.pop_back();
			tokenSet.push_back(m_tokVec[m_tokIdx++].str);
		}

		try
		{
			(info.*(WsConfigInfo::s_table[tokenStr]))(tokenSet);
		}
		catch (std::exception& e)
		{
			throw WsException(m_tokVec[m_tokIdx - 1].lineNum, "invaild port or path");
		}
	}
}

bool
tokenizer::verifyInfo(WsConfigInfo& info)
{
	info.checkConfig();
	return (true);
}

void
tokenizer::locationContextParse(WsConfigInfo &info)
{
	std::vector<std::string>	tokenSet;
	size_t						optionLineNum;

	m_tokIdx++;
	while (isSafeIdx() && m_tokVec[m_tokIdx].type == SERVER_CONTEXT)
	{
		optionLineNum = m_tokVec[m_tokIdx].lineNum;
		std::string &tokenStr = m_tokVec[m_tokIdx++].str;

		if (WsConfigInfo::s_table["loc_" + tokenStr] == 0)
			throw WsException(m_tokVec[m_tokIdx - 1].lineNum, "invaild location option");
		else if (!isSafeIdx())
			throw WsException(m_tokVec[m_tokIdx].lineNum, "3???");

		tokenSet.clear();
		while (isSafeIdx() && m_tokVec[m_tokIdx].str.back() != ';' && m_tokVec[m_tokIdx].type == SERVER_CONTEXT)
			tokenSet.push_back(m_tokVec[m_tokIdx++].str);

		if (m_tokVec[m_tokIdx].lineNum != optionLineNum)
			throw WsException(optionLineNum, "miss ';'");

		if (m_tokVec[m_tokIdx].type == SEMICOLON)
			m_tokIdx++;
		else if (m_tokVec[m_tokIdx].str.back() == ';')
		{
			m_tokVec[m_tokIdx].str.pop_back();
			tokenSet.push_back(m_tokVec[m_tokIdx++].str);
		}
		(info.*(WsConfigInfo::s_table["loc_" + tokenStr]))(tokenSet);
	}
}

void	 tokenizer::locationParse(WsConfigInfo &info)
{
	m_tokIdx++;
	if (!isSafeIdx() || info.createLocation(m_tokVec[m_tokIdx].str))
		throw WsException(m_tokVec[m_tokIdx - 1].lineNum, "invaild location path");
	m_tokIdx++;
	if (isSafeIdx() && m_tokVec[m_tokIdx].type == OPEN_BRACE)
		locationContextParse(info);
	else
		throw WsException(m_tokVec[m_tokIdx].lineNum - 1, "miss '{' - location");

	if (!isSafeIdx())
		throw WsException(m_tokVec[m_tokIdx].lineNum, "4???");
	else if (m_tokVec[m_tokIdx].type != CLOSE_BRACE)
		throw WsException(m_tokVec[m_tokIdx].lineNum + 1, "miss '}' - location");
	else
		++m_tokIdx;
}

bool
tokenizer::isSafeIdx(void)
{
	if (m_tokIdx >= m_tokVec.size())
	{
		m_tokIdx--;
		return (false);
	}
	return (true);
}

