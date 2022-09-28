#ifndef WsConfigInfo_hpp
#define WsConfigInfo_hpp

#include <vector>
#include <string>
#include <unordered_map>

class WsConfigInfo
{
		private:
			struct Location
			{
				std::string	m_path;
			};
			std::vector<std::string>	m_rootPath;
			std::vector<std::string>	m_indexFile;
			std::vector<std::string>	m_serverName;
			std::vector<int>			m_listenPort;
			std::vector<Location>		m_location;

		public:
			typedef void (t_getter)(std::vector<std::string>&);
			typedef t_getter WsConfigInfo::*t_getterType;

			void	getRootPath(std::vector<std::string>& set);
			void	getIndexFile(std::vector<std::string>& set);
			void	getServerName(std::vector<std::string>& set);
			void	getListenPort(std::vector<std::string>& set);

			WsConfigInfo();
			~WsConfigInfo();

			static std::unordered_map<std::string, t_getterType>	s_table;
			static void	setTable();
			void printConf();
};

// std::unordered_map<std::string, WsConfigInfo::t_getter>	s_table;
//
// static void	setTable()
// {
//     s_table["root"] = &WsConfigInfo::getRootPath;
// }

#endif //WsConfigInfo_hpp
