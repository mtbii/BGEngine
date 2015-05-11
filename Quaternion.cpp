#include "Quaternion.h"
using namespace Engine::Math;

Quaternion::Quaternion()
{
   this->x = 0;
   this->y = 0;
   this->z = 0;
   this->w = 0;
}

Quaternion::Quaternion(float x, float y, float z, float w)
{
   this->x = x;
   this->y = y;
   this->z = z;
   this->w = w;
}

Quaternion::~Quaternion()
{
}

float Quaternion::length(){
   return sqrt(x*x + y*y + z*z + w*w);
}

Quaternion Quaternion::normalize(){
   float length = this->length();
   x /= length;
   y /= length;
   z /= length;
   w /= length;
   return *this;
}

Quaternion Quaternion::conjugate(){
   return Quaternion(-x, -y, -z, w);
}


float Quaternion::getX(){
   return x;
}

void Quaternion::setX(float x){
   this->x = x;
}

float Quaternion::getY(){
   return y;
}

void Quaternion::setY(float y){
   this->y = y;

}

float Quaternion::getZ(){
   return z;
}

void Quaternion::setZ(float z){
   this->z = z;

}

float Quaternion::getW(){
   return w;
}

void Quaternion::setW(float w){
   this->w = w;
}

Quaternion Engine::Math::operator*(Quaternion q1, Quaternion q2){
   return Quaternion(
      q1.getW()*q2.getW() - q1.getX()*q2.getX() - q1.getY()*q2.getY() - q1.getZ()*q2.getZ(),
      q1.getX()*q2.getW() + q1.getW()*q2.getX() + q1.getY()*q2.getZ() - q1.getZ()*q2.getY(),
      q1.getY()*q2.getW() + q1.getW()*q2.getY() + q1.getZ()*q2.getX() - q1.getX()*q2.getZ(),
      q1.getZ()*q2.getW() + q1.getW()*q2.getZ() + q1.getX()*q2.getY() - q1.getY()*q2.getX());
}

Quaternion Engine::Math::operator*(Quaternion q1, Vector3f v1){
   return Quaternion(
      -q1.getX()*v1.getX() - q1.getY()*v1.getY() - q1.getZ()*v1.getZ(),
       q1.getW()*v1.getX() + q1.getY()*v1.getZ() - q1.getZ()*v1.getY(),
       q1.getW()*v1.getY() + q1.getZ()*v1.getX() - q1.getX()*v1.getZ(),
       q1.getW()*v1.getZ() + q1.getX()*v1.getY() - q1.getY()*v1.getX());
}