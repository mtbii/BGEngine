#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <cstdarg>

using namespace std;

extern void error(const char* msg, ...);
extern void warning(const char* msg, ...);
extern void message(const char* msg, ...);