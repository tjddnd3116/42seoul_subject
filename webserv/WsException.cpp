#include "WsException.hpp"

WsException::WsException(const std::string &errMsg)
	:_errMsg("Error : " + errMsg)
{}

WsException::~WsException() throw()
{}

const char*
WsException::what() const throw()
{
	return (_errMsg.c_str());
}
