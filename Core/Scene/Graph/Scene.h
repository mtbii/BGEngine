#pragma once

#include "SceneObject.h"
#include "../../Window.h"
#include "Camera/Camera.h"

class Scene
{
public:
   Scene(Camera* mainCamera);
   ~Scene();

   //vector<Light*> lights;
   std::vector<Camera*> cameras;
   Camera* activeCamera;

   std::vector<SceneObject*> sceneObjects;

   //void AddLight(Light* light);
   //void RemoveLight(Light* light);

   void AddCamera(Camera* camera);
   void RemoveCamera(Camera* camera);
   void SetActiveCamera(Camera* camera);

   void AddSceneObject(SceneObject* obj);
   void RemoveSceneObject(SceneObject* obj);

   void Draw();
   virtual void Draw(Camera& camera);

   void Update();
};

