#include "IOUtils.h"

std::string FileUtils::GetFileContents(const std::string& filePath)
{
   std::ifstream inputFile(filePath);
   std::string fileContents = "";
   std::string line = "";

   while (std::getline(inputFile, line))
   {
      fileContents += line + "\n";
   }

   inputFile.close();

   return fileContents;
}

std::string TextUtils::Trim(const std::string& text)
{
   return TrimEnd(TrimStart(text));
}

// trim from start
std::string TextUtils::TrimStart(const std::string& s) {
   std::string outString = "";
   outString += s;
   outString.erase(outString.begin(), std::find_if(outString.begin(), outString.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
   return outString;
}

// trim from end
std::string TextUtils::TrimEnd(const std::string& s) {
   std::string outString = "";
   outString += s;
   outString.erase(std::find_if(outString.rbegin(), outString.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), outString.end());
   return outString;
}