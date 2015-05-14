#include "Main.h"

void TestGame::Render(){
   Game::Render();

   testCube->Draw();
}

bool TestGame::Init(){
   bool status = Game::Init();

   vector<Vertex> vertices;

   Vertex v1;
   v1.position.x = 0;
   v1.position.y = 0.5f;
   v1.position.z = 0;
   v1.color.a = 255;
   v1.color.r = 255;
   v1.color.g = 0;
   v1.color.b = 0;

   Vertex v2;
   v2.position.x = 0.5f;
   v2.position.y = -0.5f;
   v2.position.z = 0.0f;
   v2.color.a = 255;
   v2.color.r = 0;
   v2.color.g = 255;
   v2.color.b = 0;

   Vertex v3;
   v3.position.x = -0.5f;
   v3.position.y = -0.5f;
   v3.position.z = 0.0f;
   v3.color.a = 255;
   v3.color.r = 0;
   v3.color.g = 0;
   v3.color.b = 255;

   vertices.push_back(v1);
   vertices.push_back(v2);
   vertices.push_back(v3);


   Transform* transform = new Transform(glm::vec3(0), glm::quat(glm::vec3(0.0f)), glm::vec3(1.0f));

   testCube = new Cube(1, 1, 1);
   testCube->transform = transform;

   return status;
}

void TestGame::Update(){
   Game::Update();
   static int time = 0;
   testCube->transform->SetScale(glm::vec3(sin(glm::radians((float)time++ / 4))));
   testCube->transform->SetRotation(glm::vec3(0.1*tan(glm::radians((float)time++ / 4))));
   testCube->transform->SetTranslation(glm::vec3(0.5f*cos(glm::radians((float)time++ / 4))));
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
   delete testCube;
}

int main(int argc, char* argv[]){
   Window window("Test Game Engine", 600, 600);
   TestGame game(window, 60);
   int status = game.Execute();
   return status;
}