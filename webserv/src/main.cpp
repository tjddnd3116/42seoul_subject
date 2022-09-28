#include <exception>
#include <iostream>
#include "WsInitializer.hpp"
#include "WsException.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw (WsException("invalid arguments count"));

		WsInitializer wsInit;

		wsInit.parseConfig(argv[1]);

		// WsServer	wsServer(wsInit.getConfigInfo());
		// wsServer.run();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << "Webserv server exit....." << std::endl;
	}

	return (0);
}
