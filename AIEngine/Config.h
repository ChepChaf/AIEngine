#pragma once

#include <vector>
#include <map>
#include <string>
#include <memory>

namespace AIEngine
{
	class Config
	{
		static std::shared_ptr<Config> s_instance;
		static const std::vector<std::string> s_allowedKeys;
		std::map<std::string, std::string> m_configDict;
	public:
		static void Init(int argc, char** argv);
		static const std::shared_ptr<Config> GetInstance();
		static const std::string GetValue(std::string key);
		static const int GetIntValue(std::string key);
	};
}
