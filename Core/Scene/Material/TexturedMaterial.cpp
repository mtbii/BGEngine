#include "Material.h"


TexturedMaterial::TexturedMaterial(const std::string& textureFilePath) : Material()
{
   this->texture = new Texture();
   this->texture->Init(textureFilePath);

   this->shader = new GLSLProgram();
   this->shader->Compile("Core/Scene/GL/Shaders/texture.vert", "Core/Scene/GL/Shaders/texture.frag");
   this->shader->AddAttribute("vertexPosition");
   this->shader->AddAttribute("vertexUV");
   this->shader->Link();

   this->shader->AddUniform("mvpMat");
}

TexturedMaterial::~TexturedMaterial()
{
   delete this->texture;
}

void TexturedMaterial::Bind()
{
   texture->Bind();
   this->shader->Bind();
}

void TexturedMaterial::Unbind()
{
   this->shader->Unbind();
   texture->Unbind();
}