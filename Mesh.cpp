#include "Mesh.h"

Mesh::Mesh() :
vboId(0),
size(0)
{
}

Mesh::~Mesh(){
   glDeleteBuffers(1, &vboId);
}

void Mesh::Init(){
   if (vboId == 0)
   {
      glGenBuffers(1, &vboId);
   }
}

void Mesh::SetVertices(std::vector<Vertex> vertices){
   size = vertices.size() * Vertex::POSITION_SIZE;
   glBindBuffer(GL_ARRAY_BUFFER, vboId);
   glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);
   glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Mesh::SetVertices(int count, float vertices[]){
   this->size = count;
   glBindBuffer(GL_ARRAY_BUFFER, vboId);
   glBufferData(GL_ARRAY_BUFFER, count*sizeof(float), vertices, GL_STATIC_DRAW);
   glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Mesh::Draw(){

   glEnableVertexAttribArray(0);
   glEnableVertexAttribArray(1);
   glBindBuffer(GL_ARRAY_BUFFER, vboId);

   //Position attribute pointer
   glVertexAttribPointer(0, Vertex::POSITION_SIZE, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));

   //Color attribute pointer
   glVertexAttribPointer(1, Vertex::COLOR_SIZE, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));

   glDrawArrays(GL_TRIANGLES, 0, 3);

   glDisableVertexAttribArray(1);
   glDisableVertexAttribArray(0);
}