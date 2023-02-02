#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace FutureEngine {
	class FE_API Log
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

#define FE_CORE_TRACE(...)	::FutureEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FE_CORE_INFO(...)	::FutureEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FE_CORE_WARN(...)	::FutureEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FE_CORE_ERROR(...)	::FutureEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FE_CORE_FATAL(...)	::FutureEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define FE_TRACE(...)	::FutureEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FE_INFO(...)	::FutureEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define FE_WARN(...)	::FutureEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FE_ERROR(...)	::FutureEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define FE_FATAL(...)	::FutureEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)