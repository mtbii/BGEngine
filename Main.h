#pragma once
#include "Game.h"
#include "Mesh.h"

class TestGame : public Game
{
private:
   Mesh testMesh;

public:
   virtual bool Init();
   virtual void Render();
};