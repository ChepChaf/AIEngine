#pragma once

#ifdef MAKEDLL
#  define AIE_API __declspec(dllexport)
#else
#  define AIE_API __declspec(dllimport)
#endif

#include "Logger.h"
#undef CreateWindow  // After Logger.h to avoid CreateWindow macro override (WindowsAPI)