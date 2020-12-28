#include "Config.h"

#include "Core.h"

namespace AIEngine
{
	std::shared_ptr<Config> Config::s_instance = nullptr;
	const std::vector<std::string> Config::s_allowedKeys = {
			"window_height",
			"window_width"
	};

	void Config::Init(int argc, char** argv)
	{
		if (s_instance != nullptr)
		{
			AIE_CORE_ERROR("Config already initialized.");
			return;
		}

		s_instance = std::make_shared<Config>();

		for (int i = 1; i < argc; i++)
		{
			std::string fullValue = argv[i];
			std::string key = fullValue.substr(0, fullValue.find("="));
			std::string value = fullValue.substr(fullValue.find("=") + 1, fullValue.length());

			if (std::find(s_allowedKeys.begin(), s_allowedKeys.end(), key) != s_allowedKeys.end())
			{
				s_instance->m_configDict[key] = value;
			}
		}

		if (GetValue("window_height") == "")
		{
			s_instance->m_configDict["window_height"] = "640";
		}
		if (GetValue("window_width") == "")
		{
			s_instance->m_configDict["window_width"] = "800";
		}
		if (GetValue("window_maximized") == "")
		{
			s_instance->m_configDict["window_maximized"] = "1";
		}

		AIE_CORE_INFO("Init Config");
	}

	const std::shared_ptr<Config> Config::GetInstance()
	{
		return s_instance;
	}

	const std::string Config::GetValue(std::string key)
	{
		return s_instance->m_configDict[key];
	}
	const int Config::GetIntValue(std::string key)
	{
		std::string value = GetValue(key);

		if (value != "")
		{
			return std::stoi(value);
		}

		return 0;
	}
}
