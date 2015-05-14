#pragma once
#include "Game.h"
#include "Model3D.h"

class TestGame : public Game
{
private:
   //Entity<Model3D>* testEntity;
   Model3D model;

public:
   TestGame(Window& window) : Game(window){};
   virtual bool Init();
   virtual void Render();
   virtual void Update();
   virtual void CleanUp();
   virtual void OnEvent(SDL_Event* event);
};