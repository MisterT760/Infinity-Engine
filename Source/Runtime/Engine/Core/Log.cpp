#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Infinity
{
	std::shared_ptr<spdlog::logger> Log::sEngineLogger;
	std::shared_ptr<spdlog::logger> Log::sApplicationLogger;

	void Infinity::Log::Initialize()
	{
		//Set log pattern
		spdlog::set_pattern("%^[%T] %n: %v%$");

		//Set engine log level
		sEngineLogger = spdlog::stdout_color_mt("INFINITY");
		sEngineLogger->set_level(spdlog::level::trace);

		//Set application log level
		sApplicationLogger = spdlog::stdout_color_mt("APPLICATION");
		sApplicationLogger->set_level(spdlog::level::trace);

		INF_ENGINE_INFO("Logger Initialized!");
	}
}