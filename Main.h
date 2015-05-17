#pragma once
#include "Core/Game.h"
#include "Core/Scene/GL/Model3D.h"
#include "Core/Scene/Graph/Entity.h"
#include "Core/ModelUtils.h"
#include "Core/Scene/Graph/Scene.h"
#include "Core/Scene/Graph/Camera/PerspectiveCamera.h"
#include "Core/Scene/Graph/Primitives/Shapes.h"

class TestGame : public Game
{
private:
   Scene* scene;

public:
   TestGame(Window& window, const int& fps) : Game(window, fps){};
   virtual bool Init();
   virtual void Render();
   virtual void Update();
   virtual void CleanUp();
   virtual void OnEvent(SDL_Event* event);
};