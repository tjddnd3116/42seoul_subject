#include "fileReader.hpp"

fileReader::fileReader(const char* path)
{
	m_configFile.open(path);
	if (m_configFile.fail())
		throw WsException("file open failed");
	m_buffer.clear();
	m_pos = 0;
	m_eof = false;
}

fileReader::~fileReader()
{}

std::string fileReader::readFile(void)
{
	std::string retStr;
	size_t		prePos;

	retStr = "";
	if (checkBufPos())
		return (retStr);
	prePos = m_pos;
	m_pos = m_buffer.find(" ", prePos);
	if (m_pos == std::string::npos)
		retStr.assign(m_buffer, prePos, m_buffer.size() - prePos);
	else
		retStr.assign(m_buffer, prePos, m_pos - prePos);
	retStr.erase(std::remove_if(retStr.begin(), retStr.end(), isspace), retStr.end());
	return (retStr);
}

int		 fileReader::checkBufPos(void)
{
	if (m_configFile.eof() && m_pos == std::string::npos)
	{
		m_eof = true;
		m_configFile.close();
		return (1);
	}
	if (m_pos == std::string::npos || m_pos == 0)
		readToBuf();
	else
		m_pos++;
	return (0);
}

void	 fileReader::readToBuf(void)
{
	m_pos = 0;
	std::getline(m_configFile, m_buffer);
	// std::cout << "buffer : " << m_buffer << std::endl;
}

bool	 fileReader::isEof(void) const
{
	return (m_eof);
}

