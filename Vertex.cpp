#include "Vertex.h"

Vertex::Vertex(){}

Vertex::~Vertex(){}

Vector3f Vertex::getPosition(){
   return position;
}
void Vertex::setPosition(Vector3f pos){
   position = pos;
}