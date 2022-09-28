#include "configParser.hpp"
#include "tokenizer.hpp"

configParser::configParser()
{
}

configParser::~configParser()
{

}

void
configParser::initParser(const char* path, WsInitializer& init)
{
	std::string tmpStr;

	fileReader	fr(path);
	tokenizer	tokenizer;

	while (1)
	{
		if (fr.isEof())
			break;
		tmpStr = fr.readFile();
		tokenizer.pushBackToken(tmpStr);
	}
	tokenizer.parse(init);
}
