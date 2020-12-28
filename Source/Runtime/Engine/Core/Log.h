#pragma once
#include <memory>
#include "InfinityCore.h"
#include "spdlog/spdlog.h"

namespace Infinity
{
	//Might need to move this
	template class INFINITY_API std::shared_ptr<spdlog::logger>;

	class INFINITY_API Log
	{
	public:
		//Initialization function
		static void Initialize();

		//Functions for getting Engine and App loggers
		inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() {
			return sEngineLogger;
		}

		inline static std::shared_ptr<spdlog::logger>& GetApplicationLogger() {
			return sApplicationLogger;
		}

	private:
		//Engine and Application loggers
		static std::shared_ptr<spdlog::logger> sEngineLogger;
		static std::shared_ptr<spdlog::logger> sApplicationLogger;
	};
}

//Engine logger defines
#define INF_ENGINE_TRACE(...)	::Infinity::Log::GetEngineLogger()->trace(__VA_ARGS__)
#define INF_ENGINE_INFO(...)	::Infinity::Log::GetEngineLogger()->info(__VA_ARGS__)
#define INF_ENGINE_WARN(...)	::Infinity::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define INF_ENGINE_ERROR(...)	::Infinity::Log::GetEngineLogger()->error(__VA_ARGS__)
#define INF_ENGINE_FATAL(...)	::Infinity::Log::GetEngineLogger()->critical(__VA_ARGS__)

//Application logger defines
#define INF_LOG_TRACE(...)		::Infinity::Log::GetApplicationLogger()->trace(__VA_ARGS__)
#define INF_LOG_INFO(...)		::Infinity::Log::GetApplicationLogger()->info(__VA_ARGS__)
#define INF_LOG_WARN(...)		::Infinity::Log::GetApplicationLogger()->warn(__VA_ARGS__)
#define INF_LOG_ERROR(...)		::Infinity::Log::GetApplicationLogger()->error(__VA_ARGS__)
#define INF_LOG_FATAL(...)		::Infinity::Log::GetApplicationLogger()->critical(__VA_ARGS__)