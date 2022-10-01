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
		fileReader m_fileReader;
		tokenizer m_tokenizer;
		std::vector<std::string> m_config;

	public:
		configParser(const char* path);
		~configParser();

		void	initParser(void);
		void	parse(WsInitializer& init);
};

#endif //configParser_hpp
