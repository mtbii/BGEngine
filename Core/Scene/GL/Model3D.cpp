#include "Model3D.h"

Model3D::Model3D() :
vboId(0),
size(0)
{
}

Model3D::~Model3D(){
   glDeleteBuffers(1, &vboId);
   glDeleteBuffers(1, &iboId);
}

void Model3D::Init(){
   if (vboId == 0)
   {
      glGenBuffers(1, &vboId);
      glGenBuffers(1, &iboId);
   }
}

void Model3D::SetVertices(std::vector<Vertex> vertices, std::vector<unsigned short> indices){
   size = indices.size();

   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboId);
   glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned short), &indices[0], GL_STATIC_DRAW);

   glBindBuffer(GL_ARRAY_BUFFER, vboId);
   glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

   glBindBuffer(GL_ARRAY_BUFFER, 0);
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
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
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboId);

   //Position attribute pointer
   glVertexAttribPointer(0, Vertex::POSITION_SIZE, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));

   //Color attribute pointer
   glVertexAttribPointer(1, Vertex::COLOR_SIZE, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));

   glDrawElements(GL_TRIANGLES, size, GL_UNSIGNED_SHORT, (void*)0);

   glDisableVertexAttribArray(0);
   glDisableVertexAttribArray(1);
}