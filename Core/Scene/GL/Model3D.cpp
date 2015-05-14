#include "Model3D.h"

Model3D::Model3D() :
vboId(0),
size(0)
{
}

Model3D::~Model3D(){
   glDeleteBuffers(1, &vboId);
}

void Model3D::Init(){
   if (vboId == 0)
   {
      glGenBuffers(1, &vboId);
   }
}

void Model3D::SetVertices(std::vector<Vertex> vertices){
   size = vertices.size();
   glBindBuffer(GL_ARRAY_BUFFER, vboId);
   glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);
   glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Model3D::SetVertices(int count, float vertices[]){
   this->size = count;
   glBindBuffer(GL_ARRAY_BUFFER, vboId);
   glBufferData(GL_ARRAY_BUFFER, count*sizeof(float), vertices, GL_STATIC_DRAW);
   glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Model3D::Draw(){

   glEnableVertexAttribArray(0);
   glEnableVertexAttribArray(1);
   glBindBuffer(GL_ARRAY_BUFFER, vboId);

   //Position attribute pointer
   glVertexAttribPointer(0, Vertex::POSITION_SIZE, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));

   //Color attribute pointer
   glVertexAttribPointer(1, Vertex::COLOR_SIZE, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));

   glDrawArrays(GL_TRIANGLES, 0, size);

   glDisableVertexAttribArray(0);
   glDisableVertexAttribArray(1);
}