#pragma once
#include <glew.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <vector>
#include "Vertex.h"

class Model3D{
public:
   Model3D();
   ~Model3D();
   void Init();
   void SetVertices(std::vector<Vertex> vertices);
   void SetVertices(int count, float vertices[]);
   void Draw();

   GLuint vboId;
   int size;
};
