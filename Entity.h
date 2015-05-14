#pragma once

#include<glew.h>
#include<glm/glm.hpp>
#include<type_traits>
#include "Vertex.h"
#include "Model3D.h"
#include "GLSLProgram.h"
#include "Transform.h"

template <class T>
class Entity
{
   static_assert(std::is_base_of<Model3D, T>::value, "T must be a descendent of Model3D");

private:
   inline void SetupBasicShader(){
      GLSLProgram shader;
      shader.Compile("basic.vert", "basic.frag");
      shader.AddAttribute("vertexPosition");
      shader.AddAttribute("vertexColor");
      shader.Link();
      shader.AddUniform("time");
      shader.AddUniform("translationMat");
      shader.AddUniform("rotationMat");
      shader.AddUniform("scaleMat");
      this->shader = shader;
   }

public:
   T geometry;
   GLSLProgram shader;
   Transform transform;

   inline Entity() :
      transform(),
      geometry()
   {
      SetupBasicShader();
   }

   inline Entity(const T& data) :
      transform(),
      {
      this->geometry = data;
      SetupBasicShader();
      }

   inline ~Entity(){};

   inline void Draw(){
      shader.Bind();
      shader.SetUniformf("time", Time::GetTime());
      shader.SetUniformMatrix4("translationMat", transform.GetTranslationMatrix());
      shader.SetUniformMatrix4("rotationMat", transform.GetRotationMatrix());
      shader.SetUniformMatrix4("scaleMat", transform.GetScaleMatrix());

      ((Model3D)geometry).Draw();

      shader.Unbind();
   }
};

