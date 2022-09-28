#ifndef fileReader_hpp
#define fileReader_hpp

#include <string>
#include <fstream>
#include <iostream>
#include <cctype>

#include "../WsException.hpp"

class fileReader
{
	private:
		std::ifstream	m_configFile;
		std::string		m_buffer;
		size_t			m_pos;
		bool			m_eof;

	public:
		fileReader(const char* path);
		~fileReader();

		std::string	readFile(void);
		int			checkBufPos(void);
		void		readToBuf(void);
		bool		isEof(void) const;


};
#endif //fileReader_hpp
