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

