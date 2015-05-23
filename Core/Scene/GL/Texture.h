#pragma once

#include <glew.h>
#include <IL/ilut.h>
#include "../../../Utilities/Utilities.h"

class Texture
{
private:
   std::string filePath;

public:
   GLuint texId;
   GLuint glImgId;

   Texture();
   ~Texture();

   void Init(const std::string& filePath);
   void Bind();
   void Unbind();

   static Texture Load(const std::string& filePath);
};

