#pragma once

#include <glew.h>

#include "../GL/GLSLProgram.h"
#include "../GL/Vertex.h"
#include "../GL/Texture.h"
#include "../../../Utilities/Utilities.h"

class Material
{
public:
   GLSLProgram* shader;
   virtual void Bind() = 0;
   virtual void Unbind() = 0;
};

class ColoredMaterial : public Material
{
private:
   Color diffuse;
   Color ambient;
   Color specular;
   float hardness;

public:
   ColoredMaterial(const Color& diffuse, const Color& ambient, const Color& specular, const float& hardness);
   ~ColoredMaterial();

   virtual void Bind();
   virtual void Unbind();
};

class TexturedMaterial : public Material
{
private:
   Texture* texture;

public:
   TexturedMaterial(const std::string& textureFilePath);
   ~TexturedMaterial();

   virtual void Bind();
   virtual void Unbind();
};