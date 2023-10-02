#pragma once

#ifdef PLATFORM_WINDOWS
    #ifdef BUILD_DLL
        #define DLL_API __declspec(dllexport)
    #else
        #define DLL_API __declspec(dllimport)
    #endif
#else 
    #error It Only Support Windows
#endif 

#define BIT(x) (1 << x)