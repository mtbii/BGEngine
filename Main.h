#pragma once
#include "Core/Game.h"
#include "Core/Scene/GL/Model3D.h"
#include "Core/Scene/Entity.h"
#include "Core/Scene/Primitives/Cube.h"

class TestGame : public Game
{
private:
   Cube* testCube;

public:
   TestGame(Window& window, const int& fps) : Game(window, fps){};
   virtual bool Init();
   virtual void Render();
   virtual void Update();
   virtual void CleanUp();
   virtual void OnEvent(SDL_Event* event);
};