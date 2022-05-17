#pragma once

#include <memory>
#include "Core.h"
#include "Spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Harbor {

	class HARBOR_API Log
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

// Core log macros
#define HB_CORE_TRACE(...) ::Harbor::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HB_CORE_INFO(...)  ::Harbor::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HB_CORE_WARN(...)  ::Harbor::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HB_CORE_ERROR(...) ::Harbor::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HB_CORE_FATAL(...) ::Harbor::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define HB_INFO(...)       ::Harbor::Log::GetClientLogger()->info(__VA_ARGS__)
#define HB_WARN(...)       ::Harbor::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HB_ERROR(...)      ::Harbor::Log::GetClientLogger()->error(__VA_ARGS__)
#define HB_TRACE(...)      ::Harbor::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HB_FATAL(...)      ::Harbor::Log::GetClientLogger()->fatal(__VA_ARGS__)



