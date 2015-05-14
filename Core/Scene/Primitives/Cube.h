#pragma once

#include "../Entity.h"
#include "../GL/Model3D.h"
#include "../GL/Vertex.h"

class Cube : public Entity < Model3D >
{
private:
   void GenerateBuffer();

public:
   Cube();
   Cube(const float& width, const float& height, const float& depth);
   ~Cube();

   float width;
   float height;
   float depth;

};

