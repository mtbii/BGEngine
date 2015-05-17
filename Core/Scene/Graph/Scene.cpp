#include "Scene.h"
using namespace std;

Scene::Scene(Camera* camera)
{
   activeCamera = camera;
   cameras.push_back(camera);
}

Scene::~Scene()
{
   for (unsigned i = 0; i < this->sceneObjects.size(); i++)
   {
      delete this->sceneObjects[i];
   }
   this->sceneObjects.clear();

   for (unsigned i = 0; i < this->cameras.size(); i++)
   {
      delete this->cameras[i];
   }
   this->cameras.clear();
}

void Scene::AddCamera(Camera* camera)
{
   cameras.push_back(camera);
}

void Scene::RemoveCamera(Camera* camera)
{
   for (unsigned int i = 0; i < cameras.size(); i++)
   {
      if (cameras[i] == camera)
      {
         delete cameras[i];
         cameras.erase(cameras.begin() + i);
      }
   }
}

void Scene::SetActiveCamera(Camera* camera)
{
   activeCamera = camera;
}

void Scene::AddSceneObject(SceneObject* obj)
{
   sceneObjects.push_back(obj);
}

void Scene::RemoveSceneObject(SceneObject* obj)
{
   for (unsigned int i = 0; i < sceneObjects.size(); i++)
   {
      if (sceneObjects[i] == obj)
      {
         delete sceneObjects[i];
         sceneObjects.erase(sceneObjects.begin() + i);
      }
   }
}

void Scene::Draw()
{
   for (unsigned i = 0; i < this->sceneObjects.size(); i++)
   {
      sceneObjects[i]->DrawAll(*activeCamera);
   }
}

void Scene::Draw(Camera& camera)
{
   for (unsigned i = 0; i < this->sceneObjects.size(); i++)
   {
      sceneObjects[i]->DrawAll(camera);
   }
}

void Scene::Update()
{
   for (unsigned i = 0; i < this->sceneObjects.size(); i++)
   {
      sceneObjects[i]->Update();
   }
}