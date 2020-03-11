#include "Logger.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace AceEngine
{
	std::shared_ptr<spdlog::logger> Logger::sp_CoreLogger;
    std::shared_ptr<spdlog::logger> Logger::sp_GameLogger;
	void Logger::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		sp_CoreLogger = spdlog::stdout_color_mt("AceEngine");
		sp_CoreLogger->set_level(spdlog::level::trace);

		sp_GameLogger = spdlog::stdout_color_mt("Game");
		sp_GameLogger->set_level(spdlog::level::trace);
	}
}
