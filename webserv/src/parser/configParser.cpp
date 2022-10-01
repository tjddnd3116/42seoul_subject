#include "configParser.hpp"
#include "tokenizer.hpp"

configParser::configParser(const char* path)
{
	m_fileReader.initFileReader(path);
}

configParser::~configParser()
{}

void
configParser::initParser(void)
{
	t_token		token;
	tokenizer	tokenizer;

	while (1)
	{
		if (m_fileReader.isEof())
			break;
		token = m_fileReader.readFile();
		m_tokenizer.pushBackToken(token);
	}
	m_config = m_fileReader.getAllBuffer();
}

void configParser::parse(WsInitializer& init)
{
	try
	{
		m_tokenizer.parseToken(init);
	}
	catch (WsException& e)
	{
		e.printConfigErr(m_config);
		throw WsException("invalid config file");
	}

}

