#include "Entity.h"

Entity::Entity() :
components()
{
   SetupBasicMaterial();
}

Entity::Entity(Model3D& data) : SceneObject()
{
   this->transform = new Transform();
   this->components.push_back(&data);
   SetupBasicMaterial();
}

Entity::Entity(std::vector<Model3D*>& data, Transform& transform) : SceneObject()
{
   this->transform = &transform;
   this->components = data;
   SetupBasicMaterial();
}

Entity::~Entity()
{
   for (unsigned int i = 0; i < components.size(); i++)
   {
      delete components[i];
   }

   components.clear();
};

void Entity::SetupBasicMaterial(){
   SceneObject::material = new ColoredMaterial(Color(1.0f, 1.0f, 1.0f, 1.0f), Color(1.0f, 1.0f, 1.0f, 1.0f), Color(1.0f, 1.0f, 1.0f, 1.0f), 1.0);
}

void Entity::Update()
{

}

void Entity::Draw(Camera& camera)
{
   material->Bind();
   //shader->SetUniformf("time", Time::GetTime() / 10.0f);
   material->shader->SetUniformMatrix4("mvpMat", camera.GetVPMatrix()*(parent ? parent->GetTransformMatrix() : glm::mat4(1.0f))*transform->GetTransformMatrix());

   for (unsigned short i = 0; i < components.size(); i++)
   {
      ((Model3D*)components[i])->Draw();
   }

   material->Unbind();
   //shader->Unbind();
}