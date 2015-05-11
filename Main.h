#pragma once
#include "Game.h"
#include "Mesh.h"
#include "GLSLProgram.h"

class TestGame : public Game
{
private:
   Mesh testMesh;
   GLSLProgram shader;

public:
   virtual bool Init();
   virtual void Render();
};