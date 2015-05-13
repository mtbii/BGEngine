#pragma once

#include <string>
#include <fstream>
#include <glew.h>
#include <vector>
#include <map>
#include <glm/glm.hpp>
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
   void AddUniform(const std::string& uniformName);

   void GLSLProgram::SetUniformi(const std::string& uniformName, int value);
   void GLSLProgram::SetUniformf(const std::string& uniformName, float value);
   void GLSLProgram::SetUniform3f(const std::string& uniformName, const glm::vec3& value);
   void GLSLProgram::SetUniformMatrix4(const std::string& uniformName, const glm::mat4& value);

   void Bind();
   void Unbind();

private:
   GLuint programId;
   GLuint vertexShaderId;
   GLuint fragmentShaderId;
   int numAttributes;
   std::map<std::string, int> uniforms;

   void Compile(const std::string& filePath, const GLuint& id);
};

