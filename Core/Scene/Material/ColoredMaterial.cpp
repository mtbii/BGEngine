#include "Material.h"


ColoredMaterial::ColoredMaterial(const Color& diffuse, const Color& ambient, const Color& specular, const float& hardness)
{
   this->diffuse = diffuse;
   this->ambient = ambient;
   this->specular = specular;
   this->hardness = hardness;

   this->shader = new GLSLProgram();
   this->shader->Compile("Core/Scene/GL/Shaders/basic.vert", "Core/Scene/GL/Shaders/basic.frag");
   this->shader->AddAttribute("vertexPosition");
   this->shader->Link();

   this->shader->AddUniform("mvpMat");
   this->shader->AddUniform("diffuseColor");
   //this->shader->AddUniform("ambientColor");
   //this->shader->AddUniform("specularColor");
   //this->shader->AddUniform("hardness");
}

ColoredMaterial::~ColoredMaterial()
{
}

void ColoredMaterial::Bind()
{
   this->shader->Bind();

   this->shader->SetUniformColor("diffuseColor", this->diffuse);
   //this->shader->SetUniform4f("specularColor", glm::vec4(this->specular.r, this->specular.g, this->specular.b, this->specular.a));
   //this->shader->SetUniform4f("ambientColor", glm::vec4(this->ambient.r, this->ambient.g, this->ambient.b, this->ambient.a));
   //this->shader->SetUniformf("hardness", this->hardness);
}

void ColoredMaterial::Unbind()
{
   this->shader->Unbind();
}