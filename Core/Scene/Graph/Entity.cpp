#include "Entity.h"

Entity::Entity() :
components()
{
   SetupBasicShader();
}

Entity::Entity(Model3D& data) : SceneObject()
{
   this->transform = new Transform();
   this->components.push_back(&data);
   SetupBasicShader();
}

Entity::Entity(std::vector<Model3D*>& data, Transform& transform) : SceneObject()
{
   this->transform = &transform;
   this->components = data;
   SetupBasicShader();
}

Entity::~Entity()
{
   for (unsigned int i = 0; i < components.size(); i++)
   {
      delete components[i];
   }

   components.clear();
   delete shader;
   delete transform;
};

void Entity::SetupBasicShader(){
   GLSLProgram* shader = new GLSLProgram();
   shader->Compile("basic.vert", "basic.frag");
   shader->AddAttribute("vertexPosition");
   shader->AddAttribute("vertexColor");
   shader->Link();
   shader->AddUniform("time");
   shader->AddUniform("mvpMat");
   this->shader = shader;
}

void Entity::Update()
{

}

void Entity::Draw(Camera& camera)
{
   shader->Bind();
   shader->SetUniformf("time", Time::GetTime() / 10.0f);
   shader->SetUniformMatrix4("mvpMat", camera.GetVPMatrix()*(parent ? parent->GetTransformMatrix() : glm::mat4(1.0f))*transform->GetTransformMatrix());

   for (unsigned short i = 0; i < components.size(); i++)
   {
      ((Model3D*)components[i])->Draw();
   }

   shader->Unbind();
}