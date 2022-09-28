#ifndef configParser_hpp
#define configParser_hpp

#include <fstream>
#include <vector>
#include <cstring>
#include <iostream>

#include "../WsConfigInfo.hpp"
#include "fileReader.hpp"
#include "tokenizer.hpp"

class configParser
{
	private:
		std::vector<WsConfigInfo>	m_configInfo;

	public:
		configParser();
		~configParser();

		void	initParser(const char* path, WsInitializer& init);
		void	createParsedConf();
};

#endif //configParser_hpp
