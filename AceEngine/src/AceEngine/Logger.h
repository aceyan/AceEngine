#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace AceEngine
{
	class ACE_ENGINE_API Logger
	{
	public:
		static void  Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return sp_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetGameLogger() { return sp_GameLogger; }
	private:
		static std::shared_ptr<spdlog::logger> sp_CoreLogger;
		static std::shared_ptr<spdlog::logger> sp_GameLogger;
	};
}

#define ACE_CORE_ERROR(...)	 AceEngine::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define ACE_CORE_WARN(...)	 AceEngine::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define ACE_CORE_INFO(...)	 AceEngine::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define ACE_CORE_TRACE(...)	 AceEngine::Logger::GetCoreLogger()->trace(__VA_ARGS__)


#define ACE_GAME_ERROR(...)	 AceEngine::Logger::GetGameLogger()->error(__VA_ARGS__)
#define ACE_GAME_WARN(...)	 AceEngine::Logger::GetGameLogger()->warn(__VA_ARGS__)
#define ACE_GAME_INFO(...)	 AceEngine::Logger::GetGameLogger()->info(__VA_ARGS__)
#define ACE_GAME_TRACE(...)	 AceEngine::Logger::GetGameLogger()->trace(__VA_ARGS__)
