#pragma once

#include <spdlog/spdlog.h>

namespace AIEngine
{
	class Logger
	{
	public:
		static void Init();
		static std::shared_ptr<spdlog::logger> GetCoreLogger();
	};
}

#define AIE_CORE_TRACE(...)    ::AIEngine::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define AIE_CORE_INFO(...)     ::AIEngine::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define AIE_CORE_WARN(...)     ::AIEngine::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define AIE_CORE_ERROR(...)    ::AIEngine::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define AIE_CORE_CRITICAL(...) ::AIEngine::Logger::GetCoreLogger()->critical(__VA_ARGS__)