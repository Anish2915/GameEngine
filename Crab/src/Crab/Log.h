#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Crab {
	
	class DLL_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}
// Core log 
#define CRAB_CORE_TRACE(...) ::Crab::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CRAB_CORE_INFO(...)  ::Crab::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CRAB_CORE_WARN(...)  ::Crab::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CRAB_CORE_ERROR(...) ::Crab::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CRAB_CORE_FATAL(...) ::Crab::Log::GetCoreLogger()->critical(__VA_ARGS__)

//client log
#define CRAB_TRACE(...) ::Crab::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CRAB_INFO(...)  ::Crab::Log::GetClientLogger()->info(__VA_ARGS__)
#define CRAB_WARN(...)  ::Crab::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CRAB_ERROR(...) ::Crab::Log::GetClientLogger()->error(__VA_ARGS__)
#define CRAB_FATAL(...) ::Crab::Log::GetClientLogger()->critical(__VA_ARGS__)