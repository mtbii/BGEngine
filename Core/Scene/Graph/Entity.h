#pragma once

#include<glew.h>
#include<glm/glm.hpp>
#include "../GL/Vertex.h"
#include "../GL/Model3D.h"
#include "../GL/GLSLProgram.h"
#include "SceneObject.h"
#include "Transform.h"
#include "../Material/Material.h"
#include "../../../Utilities/Utilities.h"

class Entity : public SceneObject
{
private:
   void SetupBasicMaterial();

public:
   std::vector<Model3D*> components;

   Entity();
   Entity(Model3D& data);
   Entity(std::vector<Model3D*>& data, Transform& transform);
   ~Entity();

   void Update();

   void Draw(Camera& camera);
};

