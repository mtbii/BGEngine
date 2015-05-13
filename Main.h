#pragma once
#include "Game.h"
#include "Entity.h"
#include "Model3D.h"

class TestGame : public Game
{
private:
   Entity<Model3D>* testEntity;

public:
   virtual bool Init();
   virtual void Render();
   virtual void Update();
   virtual void CleanUp();
   virtual void OnEvent(SDL_Event* event);
};