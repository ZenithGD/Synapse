#include "Log.hpp"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace syn {

	std::shared_ptr<spdlog::logger> Log::_core_logger;
	std::shared_ptr<spdlog::logger> Log::_client_logger;
	
	void Log::init() {
		// Set colour, timestamp, logger name and log message
		spdlog::set_pattern("%^[%T] %n: %v%$");
		_core_logger = spdlog::stdout_color_mt("Synapse");
		_core_logger->set_level(spdlog::level::trace);

		_client_logger = spdlog::stdout_color_mt("SynapseApp");
		_client_logger->set_level(spdlog::level::trace);
	}
}