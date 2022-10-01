#ifndef WsConfigInfo_hpp
#define WsConfigInfo_hpp

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <cstdlib>
#include <cctype>

#include "WsException.hpp"

class WsConfigInfo
{
		public:
			struct Location
			{
				Location(std::string &path);
				std::string					locPath;
				std::vector<std::string>	locRoot;
				std::vector<std::string>	locExpires;
				std::vector<std::string>	locProxyPass;
			};

		private:
			std::vector<std::string>	m_rootPath;
			std::vector<std::string>	m_indexFile;
			std::vector<std::string>	m_serverName;
			std::vector<int>			m_listenPort;
			std::vector<Location>		m_location;

			static bool		isPath(std::string& str);
			static bool		isPath(std::vector<std::string>& str);
			static bool		isNum(std::string& str);
			static bool		isNum(std::vector<std::string>& str);

		public:
			WsConfigInfo();
			~WsConfigInfo();


			typedef void 		(t_setter)(std::vector<std::string>&);
			typedef t_setter	WsConfigInfo::*t_setterType;

			static void	setTable();

			void		setRootPath(std::vector<std::string>& set);
			void		setIndexFile(std::vector<std::string>& set);
			void		setServerName(std::vector<std::string>& set);
			void		setListenPort(std::vector<std::string>& set);
			void		setLocationExpires(std::vector<std::string>& set);
			void		setLocationRoot(std::vector<std::string>& set);
			void		setLocationProxy(std::vector<std::string>& set);
			int			createLocation(std::string& path);
			void		printConf(void);
			void		checkConfig(void);

			std::vector<int> getListenPort(void) const;


			static std::unordered_map<std::string, t_setterType>	s_table;

};

#endif //WsConfigInfo_hpp
