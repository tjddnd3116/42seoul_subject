#include "WsResponse.hpp"

WsResponse::WsResponse(const WsConfigInfo& conf)
{
	m_conf = conf;
	// m_conf.printConf();
	m_method = NULL;
	m_responseBuf.clear();
	m_statusCode = 0;
}

WsResponse::~WsResponse()
{}

void WsResponse::makeHeader(void)
{
	std::string path;
	std::string statusCode;
	std::string header;

	path = m_conf.getRootPath()[0];
	if (m_method->getUri() == "/")
		path += m_conf.getIndexFile()[0];
	else
		path += m_method->getUri();

	m_file.open(path);
	if (m_file.fail())
	{
		m_file.clear();
		m_file.open("./html/404.html");
		statusCode = "404 Not Found\n";
		m_statusCode = 200;
	}
	else
	{
		statusCode = "200 OK\n";
		m_statusCode = 404;
	}
	m_responseBuf = "HTTP/1.1 " + statusCode;
}

void WsResponse::readFile(void)
{
	std::string readLine;

	m_responseBuf += "Content-Length: 12\n";
	while (!m_file.eof())
	{
		std::getline(m_file, readLine);
		m_responseBuf += readLine;
	}
}

void WsResponse::makeResponse(const WsIMethod* method)
{
	m_method = method;
	makeHeader();
	m_responseBuf += "Content-Type: text/html\n";
	readFile();
}

const std::string&
WsResponse::operator()(void)
{
	return (m_responseBuf);
}

size_t WsResponse::getBufSize(void) const
{
	return (m_responseBuf.size());
}


