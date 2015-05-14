#pragma once

#include <iostream>
#include <sstream>
#include <cstdarg>

using namespace std;

extern void fatal(const char* msg, ...);
extern void error(const char* msg, ...);
extern void warning(const char* msg, ...);
extern void message(const char* msg, ...);