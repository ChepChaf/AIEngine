#include "Logger.h"
	
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>


namespace AIEngine
{
	static std::shared_ptr<spdlog::logger>s_coreLogger;

	void Logger::Init()
	{
		std::vector<spdlog::sink_ptr> logSinks;
		logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("AIEngine.log", true));

		logSinks[0]->set_pattern("%^[%T] %n: %v%$");
		logSinks[1]->set_pattern("[%T] [%l] %n: %v");

		s_coreLogger = std::make_shared<spdlog::logger>("AIEngine Core", begin(logSinks), end(logSinks));
		spdlog::register_logger(s_coreLogger);
		s_coreLogger->set_level(spdlog::level::trace);
		s_coreLogger->flush_on(spdlog::level::trace);
	}	
	std::shared_ptr<spdlog::logger> Logger::GetCoreLogger()
	{
		{
			return s_coreLogger;
		} 
	}
}