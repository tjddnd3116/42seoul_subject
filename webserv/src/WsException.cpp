#include "WsException.hpp"

WsException::WsException(const std::string &errMsg)
	:m_errMsg("Error : " + errMsg)
{}

WsException::~WsException() throw()
{}

const char*
WsException::what() const throw()
{
	return (m_errMsg.c_str());
}
