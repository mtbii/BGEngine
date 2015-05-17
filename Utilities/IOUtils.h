#pragma once

#include <string>
#include <sstream>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include <fstream>
#include <iostream>
#include "Log.h"

class FileUtils
{
public:
   static std::string GetFileContents(const std::string& filePath);
};

class TextUtils
{
public:
   static std::string TrimStart(const std::string& text);
   static std::string TrimEnd(const std::string& text);
   static std::string Trim(const std::string& text);
};