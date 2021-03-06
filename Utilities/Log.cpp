#include "Log.h"
using namespace std;

void fatal(const char* msg, ...){
   stringstream sstream;
   sstream << "ERROR: " << msg << "\n";
   va_list list;
   va_start(list, msg);
   vfprintf(stderr, sstream.str().c_str(), list);
   va_end(list);
   exit(1);
}

void error(const char* msg, ...){
   stringstream sstream;
   sstream << "ERROR: " << msg << "\n";
   va_list list;
   va_start(list, msg);
   vfprintf(stderr, sstream.str().c_str(), list);
   va_end(list);
}

void warning(const char* msg, ...){
   stringstream sstream;
   sstream << "WARNING: " << msg << "\n";
   va_list list;
   va_start(list, msg);
   vfprintf(stderr, sstream.str().c_str(), list);
   va_end(list);
}

void message(const char* msg, ...){
   stringstream sstream;
   sstream << "MESSAGE: " << msg << "\n";
   va_list list;
   va_start(list, msg);
   vprintf(sstream.str().c_str(), list);
   va_end(list);
}