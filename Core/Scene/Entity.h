#pragma once

#include<glew.h>
#include<glm/glm.hpp>
#include<type_traits>
#include "GL/Vertex.h"
#include "GL/Model3D.h"
#include "GL/GLSLProgram.h"
#include "Transform.h"

template <class T>
class Entity
{
   static_assert(std::is_base_of<Model3D, T>::value, "T must be a descendent of Model3D");

private:
   inline void SetupBasicShader(){
      GLSLProgram* shader = new GLSLProgram();
      shader->Compile("basic.vert", "basic.frag");
      shader->AddAttribute("vertexPosition");
      shader->AddAttribute("vertexColor");
      shader->Link();
      shader->AddUniform("time");
      shader->AddUniform("translationMat");
      shader->AddUniform("rotationMat");
      shader->AddUniform("scaleMat");
      this->shader = shader;
   }

public:
   T* geometry;
   GLSLProgram* shader;
   Transform* transform;

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

         inline ~Entity(){
         delete geometry;
         delete shader;
         delete transform;
      };

      inline void Draw(){
         shader->Bind();
         shader->SetUniformf("time", Time::GetTime() / 10.0f);
         shader->SetUniformMatrix4("translationMat", transform->GetTranslationMatrix());
         shader->SetUniformMatrix4("rotationMat", transform->GetRotationMatrix());
         shader->SetUniformMatrix4("scaleMat", transform->GetScaleMatrix());

         ((Model3D*)geometry)->Draw();

         shader->Unbind();
      }
};

