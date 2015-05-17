#pragma once

#include <vector>
#include <glm/glm.hpp>
#include "Transform.h"
#include "Camera/Camera.h"

class SceneObject
{
public:
   SceneObject* parent;
   Transform* transform;
   std::vector<SceneObject*> children;

   inline ~SceneObject(){
      for (unsigned int i = 0; i < children.size(); i++)
      {
         delete children[i];
      }
      children.clear();
   }

   virtual void Update() = 0;
   inline virtual void Draw(Camera& camera) = 0;

   inline void DrawAll(Camera& camera){
      Draw(camera);

      for (unsigned int i = 0; i < children.size(); i++)
      {
         children[i]->Draw(camera);
      }
   }

   inline virtual void AddChild(SceneObject* child)
   {
      child->parent = this;
      children.push_back(child);
   }

   inline virtual void RemoveChild(SceneObject* child)
   {
      for (unsigned int i = 0; i < children.size(); i++)
      {
         if (children[i] == child)
         {
            delete children[i];
            children.erase(children.begin() + i);
            break;
         }
      }
   }

   inline virtual void SetParent(SceneObject* parent)
   {
      this->parent = parent;
   }

   inline virtual SceneObject* GetParent(){ return parent; }
   inline virtual glm::mat4 GetTransformMatrix(){ return this->transform->GetTransformMatrix(); }

   inline virtual std::vector<SceneObject*> GetChildren(){ return children; }
};