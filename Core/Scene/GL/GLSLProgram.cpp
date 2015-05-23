#include "GLSLProgram.h"
using namespace std;

GLSLProgram::GLSLProgram() :
programId(0),
vertexShaderId(0),
fragmentShaderId(0),
numAttributes(0),
uniforms()
{

}

GLSLProgram::~GLSLProgram()
{
   if (vertexShaderId == 0)
   {
      glDeleteShader(vertexShaderId);
   }
   if (fragmentShaderId == 0)
   {
      glDeleteShader(fragmentShaderId);
   }
   if (programId == 0)
   {
      glDeleteProgram(programId);
   }
}

void GLSLProgram::Compile(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath)
{
   vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
   if (vertexShaderId == 0){
      error("Could not create vertex shader");
   }

   fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
   if (fragmentShaderId == 0){
      error("Could not create fragment shader");
   }

   Compile(vertexShaderFilePath, vertexShaderId);
   Compile(fragmentShaderFilePath, fragmentShaderId);
   programId = glCreateProgram();
}

void GLSLProgram::Compile(const std::string& filePath, const GLuint& id)
{
   std::string text = FileUtils::GetFileContents(filePath);
   const char* textPtr = text.c_str();
   glShaderSource(id, 1, &textPtr, nullptr);
   glCompileShader(id);

   GLint success = 0;
   glGetShaderiv(id, GL_COMPILE_STATUS, &success);
   if (success == GL_FALSE){
      GLint maxLength = 0;
      glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);

      std::vector<char> errorLog(maxLength);
      glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);

      glDeleteShader(id);

      error("%s", &errorLog[0]);
      fatal("Could not compile shader from file: %s", filePath.c_str());
   }
}

void GLSLProgram::Link()
{
   glAttachShader(programId, vertexShaderId);
   glAttachShader(programId, fragmentShaderId);
   glLinkProgram(programId);

   GLint success = 0;
   glGetProgramiv(programId, GL_LINK_STATUS, &success);
   if (success == GL_FALSE){
      GLint maxLength = 0;
      glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &maxLength);

      std::vector<char> infoLog(maxLength);
      glGetProgramInfoLog(programId, maxLength, &maxLength, &infoLog[0]);

      glDeleteProgram(programId);
      glDeleteShader(vertexShaderId);
      glDeleteShader(fragmentShaderId);

      error("%s", &infoLog[0]);
      fatal("Could not link shaders");
   }

   glDetachShader(programId, vertexShaderId);
   glDetachShader(programId, fragmentShaderId);
   glDeleteShader(vertexShaderId);
   glDeleteShader(fragmentShaderId);
}

void GLSLProgram::AddAttribute(const std::string& attrName){
   glBindAttribLocation(programId, numAttributes++, attrName.c_str());
}

void GLSLProgram::AddUniform(const std::string& uniformName){
   int uniformLocation = glGetUniformLocation(programId, uniformName.c_str());
   if (uniformLocation == -1){
      fatal("Error: could not find uniform: %s", uniformName.c_str());
   }

   uniforms[uniformName] = uniformLocation;
}

void GLSLProgram::SetUniformi(const std::string& uniformName, int value)
{
   map<std::string, int>::iterator itemIter = uniforms.find(uniformName);
   if (itemIter != uniforms.end())
   {
      glUniform1i(itemIter->second, value);
   }
}

void GLSLProgram::SetUniformf(const std::string& uniformName, float value)
{
   map<std::string, int>::iterator itemIter = uniforms.find(uniformName);
   if (itemIter != uniforms.end())
   {
      glUniform1f(itemIter->second, value);
   }
}

void GLSLProgram::SetUniform3f(const std::string& uniformName, const glm::vec3& value)
{
   map<std::string, int>::iterator itemIter = uniforms.find(uniformName);
   if (itemIter != uniforms.end())
   {
      glUniform3f(itemIter->second, value.x, value.y, value.z);
   }
}

void GLSLProgram::SetUniform4f(const std::string& uniformName, const glm::vec4& value)
{
   map<std::string, int>::iterator itemIter = uniforms.find(uniformName);
   if (itemIter != uniforms.end())
   {
      glUniform4f(itemIter->second, value.x, value.y, value.z, value.w);
   }
}

void GLSLProgram::SetUniformColor(const std::string& uniformName, const Color& value)
{
   map<std::string, int>::iterator itemIter = uniforms.find(uniformName);
   if (itemIter != uniforms.end())
   {
      glUniform4f(itemIter->second, value.r / 255.0f, value.g / 255.0f, value.b / 255.0f, value.a / 255.0f);
   }
}

void GLSLProgram::SetUniformMatrix4(const std::string& uniformName, const glm::mat4& value)
{
   map<std::string, int>::iterator itemIter = uniforms.find(uniformName);
   if (itemIter != uniforms.end())
   {
      glUniformMatrix4fv(itemIter->second, 1, GL_FALSE, &value[0][0]);
   }
}

void GLSLProgram::Bind()
{
   glUseProgram(programId);
   for (int i = 0; i < numAttributes; i++)
   {
      glEnableVertexAttribArray(i);
   }
}

void GLSLProgram::Unbind()
{
   glUseProgram(0);
   for (int i = 0; i < numAttributes; i++)
   {
      glDisableVertexAttribArray(i);
   }
}