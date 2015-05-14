#pragma once
#include "Core/Game.h"
#include "Core/Scene/GL/Model3D.h"
#include "Core/Scene/Entity.h"

class TestGame : public Game
{
private:
   Entity<Model3D>* testEntity;

public:
   TestGame(Window& window) : Game(window){};
   virtual bool Init();
   virtual void Render();
   virtual void Update();
   virtual void CleanUp();
   virtual void OnEvent(SDL_Event* event);
};