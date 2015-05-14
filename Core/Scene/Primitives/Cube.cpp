#include "Cube.h"

Cube::Cube() :
width(1),
height(1),
depth(1)
{
   GenerateBuffer();
}

Cube::Cube(const float& width, const float& height, const float& depth) :
width(width),
height(height),
depth(depth)
{
   GenerateBuffer();
}

Cube::~Cube()
{
}

void Cube::GenerateBuffer()
{
   this->geometry = new Model3D();
   this->geometry->Init();

   std::vector<Vertex> vertices;

   float width2 = width / 2.0f;
   float height2 = height / 2.0f;
   float depth2 = depth / 2.0f;

   vertices.push_back(Vertex(Position(width2, height2, depth2), Color(255, 0, 0, 255)));
   vertices.push_back(Vertex(Position(width2, height2, -depth2), Color(0, 200, 0, 255)));
   vertices.push_back(Vertex(Position(width2, -height2, depth2), Color(255, 200, 0, 255)));
   vertices.push_back(Vertex(Position(width2, -height2, -depth2), Color(255, 0, 200, 255)));

   vertices.push_back(Vertex(Position(-width2, height2, depth2), Color(10, 0, 200, 255)));
   vertices.push_back(Vertex(Position(-width2, height2, -depth2), Color(25, 10, 0, 255)));
   vertices.push_back(Vertex(Position(-width2, -height2, depth2), Color(5, 255, 0, 255)));
   vertices.push_back(Vertex(Position(-width2, -height2, -depth2), Color(55, 0, 100, 255)));

   unsigned short indexArray[36] = {
      0, 6, 4,
      0, 2, 6,
      0, 3, 2,
      0, 1, 3,
      2, 7, 6,
      2, 3, 7,
      4, 6, 7,
      4, 7, 5,
      0, 4, 5,
      0, 5, 1,
      1, 5, 7,
      1, 7, 3
   };

   std::vector<unsigned short> indices(36);
   for (int i = 0; i < 36; i++)
   {
      indices[i] = indexArray[i];
   }


   this->geometry->SetVertices(vertices, indices);
}