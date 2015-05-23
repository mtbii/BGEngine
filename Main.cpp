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

   //SceneObject* box = new Shapes::Sphere(2.0f);
   //box->material = new ColoredMaterial(Color(.4f, 1.0f, 0.2f, 1.0f), Color(1.0f, 1.0f, 1.0f, 1.0f), Color(1.0f, 1.0f, 1.0f, 1.0f), 1.0);
   //
   //SceneObject* box2 = new Shapes::Sphere(1.0f);
   //box2->material = new ColoredMaterial(Color(0.1f, 0.1f, 0.1f, 1.0f), Color(1.0f, 1.0f, 1.0f, 1.0f), Color(1.0f, 1.0f, 1.0f, 1.0f), 1.0);
   //box2->transform->SetTranslation(glm::vec3(5.0, 0.0, 0.0));
   //box->AddChild(box2);

   //scene->AddSceneObject(box);

   vector<Vertex> vertices;
   vertices.push_back(Vertex(Position(1.0, 0.0, 1.0), TextureCoordinate(1.0, 1.0)));
   vertices.push_back(Vertex(Position(1.0, 0.0, -1.0), TextureCoordinate(1.0, 0.0)));
   vertices.push_back(Vertex(Position(-1.0, 0.0, -1.0), TextureCoordinate(0.0, 0.0)));
   vertices.push_back(Vertex(Position(-1.0, 0.0, 1.0), TextureCoordinate(0.0, 1.0)));

   vector<unsigned short> indices;
   indices.push_back(0); indices.push_back(1); indices.push_back(2);
   indices.push_back(2); indices.push_back(3); indices.push_back(0);

   Model3D* model3D = new Model3D();
   model3D->Init(vertices, indices);
   Entity* entity = new Entity(*model3D);
   entity->transform->SetScale(glm::vec3(10, 10, 10));
   //entity->material = new ColoredMaterial(Color(0.1f, 0.1f, 0.1f, 1.0f), Color(1.0f, 1.0f, 1.0f, 1.0f), Color(1.0f, 1.0f, 1.0f, 1.0f), 1.0);
   entity->material = new TexturedMaterial("sample_pic.jpg");

   scene->AddSceneObject(entity);

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