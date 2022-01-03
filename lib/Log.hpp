#pragma once

#include "Core.hpp"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace syn {
	class Log
	{
	private:
		static std::shared_ptr<spdlog::logger> _core_logger;
		static std::shared_ptr<spdlog::logger> _client_logger;
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return _core_logger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return _client_logger; }
	};
}

// Core logging macros
#define SYN_CORE_FATAL(...)		::syn::Log::getCoreLogger()->fatal(__VA_ARGS__)
#define SYN_CORE_ERROR(...)		::syn::Log::getCoreLogger()->error(__VA_ARGS__)
#define SYN_CORE_WARN(...)		::syn::Log::getCoreLogger()->warn(__VA_ARGS__)
#define SYN_CORE_INFO(...)		::syn::Log::getCoreLogger()->info(__VA_ARGS__)
#define SYN_CORE_TRACE(...)		::syn::Log::getCoreLogger()->trace(__VA_ARGS__)

#define SYN_FATAL(...)			::syn::Log::getClientLogger()->fatal(__VA_ARGS__)
#define SYN_ERROR(...)			::syn::Log::getClientLogger()->error(__VA_ARGS__)
#define SYN_WARN(...)			::syn::Log::getClientLogger()->warn(__VA_ARGS__)
#define SYN_INFO(...)			::syn::Log::getClientLogger()->info(__VA_ARGS__)
#define SYN_TRACE(...)			::syn::Log::getClientLogger()->trace(__VA_ARGS__)