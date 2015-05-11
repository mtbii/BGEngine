#pragma once

#include <string>
#include <fstream>
#include <glew.h>
#include <vector>
#include "Log.h"
#include "IOUtils.h"

class GLSLProgram
{
public:
   GLSLProgram();
   ~GLSLProgram();

   void Compile(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath);
   void Link();
   void AddAttribute(const std::string& attributeName);

   void Bind();
   void Unbind();

private:
   GLuint programId;
   GLuint vertexShaderId;
   GLuint fragmentShaderId;
   int numAttributes;

   void Compile(const std::string& filePath, const GLuint& id);
};

