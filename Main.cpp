#include "Main.h"
using namespace std;

void TestGame::Render(){
   Game::Render();

   scene->Draw();
}

bool TestGame::Init(){
   bool status = Game::Init();

   PerspectiveCamera* camera = new PerspectiveCamera(CameraControlType::ArcBall, glm::radians(45.0f), (float)this->window.width / (float)this->window.height, 1.0f, 200.0f);
   camera->position = glm::vec3(10.0f);
   scene = new Scene(camera);

   SceneObject* box = new Shapes::Sphere(2.0f);
   SceneObject* box2 = new Shapes::Sphere(1.0f);
   box2->transform->SetTranslation(glm::vec3(3.0, 0.0, 0.0));
   box->AddChild(box2);

   scene->AddSceneObject(box);

   ////Load a model and position/rotate/scale it properly
   //Transform* transform = new Transform(glm::vec3(6.0f), glm::quat(glm::vec3(0.0f)), glm::vec3(0.2f));
   //vector<Model3D*> model = ModelUtils::LoadModel("Core/Scene/Primitives/obj/cube.obj");

   //Entity<Model3D>* entity = new Entity<Model3D>(model, *transform);
   //entities.push_back(entity);

   ////Load a model and position/rotate/scale it properly
   //transform = new Transform(glm::vec3(0.0f), glm::quat(glm::vec3(0.0f)), glm::vec3(0.2f));
   //model = ModelUtils::LoadModel("Core/Scene/Primitives/obj/sphere.obj");

   //entity = new Entity<Model3D>(model, *transform);
   //entities.push_back(entity);

   //projectionMatrix = glm::perspective(glm::radians(45.0f), (float)this->window.width / (float)this->window.height, 1.0f, 200.0f);
   //viewMatrix = glm::lookAt(glm::vec3(10.0f), glm::vec3(0), glm::vec3(0, 1.0f, 0));

   return status;
}

void TestGame::Update(){
   Game::Update();

   scene->Update();

   for (unsigned int i = 0; i < scene->sceneObjects.size(); i++)
   {
      SceneObject* sceneObj = scene->sceneObjects[i];
      sceneObj->transform->SetRotation(sceneObj->transform->GetRotation() * glm::quat(glm::vec3(0.0, 0.01f, 0.0)));

      auto children = sceneObj->children;
      for (unsigned int j = 0; j < children.size(); j++)
      {
         auto childObj = children[j];
         childObj->transform->SetRotation(childObj->transform->GetRotation() * glm::quat(glm::vec3(0.0, 0.1f, 0.0)));
      }
   }
}

void TestGame::OnEvent(SDL_Event* event)
{
   Game::OnEvent(event);

   if (Input::IsKeyDown(SDLK_ESCAPE))
   {
      RequestQuit();
   }
}

void TestGame::CleanUp()
{
   Game::CleanUp();

   delete scene;
}

int main(int argc, char* argv[]){
   Window window("Test Game Engine", 800, 600);
   TestGame game(window, 60);
   int status = game.Execute();
   return status;
}