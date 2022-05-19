#pragma once

#ifdef HB_PLATFROM_WINDOWS
	#ifdef HB_BUILD_DLL
		#define HARBOR_API __declspec(dllexport)
	#else
		#define HARBOR_API __declspec(dllimport)
	#endif // HB_BUILD_DLL
#else
	#error Harbor Only Support Windows!
#endif // HB_PLATFROM_WINDOWS

#ifdef HB_ENABLE_ASSERTS
#define HB_ASSERT(x, ...) { if(!(x)) { HB_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define HB_CORE_ASSERT(x, ...) { if(!(x)) { HB_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define HB_ASSERT(x, ...)
#define HB_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)