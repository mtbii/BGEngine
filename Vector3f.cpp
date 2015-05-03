#include "Vector3f.h"
using namespace Engine::Math;

Vector3f::Vector3f(float x, float y, float z)
{
   this->x = x;
   this->y = y;
   this->z = z;
}


Vector3f::~Vector3f()
{
}

float Vector3f::length(){
   return sqrt(x*x + y*y + z*z);
}

float Vector3f::dot(Vector3f v){
   return x * v.getX() + y * v.getY() + z* v.getZ();
}

Vector3f Vector3f::cross(Vector3f v){
   float x_ = y * v.getZ() - z*v.getY();
   float y_ = z*v.getX() - x*v.getZ();
   float z_ = x*v.getY() - y*v.getX();
   return Vector3f(x_, y_, z_);
}

Vector3f Vector3f::normalize(){
   float length = this->length();
   x /= length;
   y /= length;
   return *this;
}

Vector3f Vector3f::rotateDegrees(Vector3f axis, float angle){
   float rads = 4 * atan(1.0) / 180.0f * angle;
   return rotate(axis, rads);
}

Vector3f Vector3f::rotate(Vector3f axis, float angle){
   float sinAngle = (float)sin(-angle);
   float cosAngle = (float)cos(-angle);

   return this->cross(axis*sinAngle) +            //Rotation on local X
      ((*this)*cosAngle) + (                     //Rotation on local Z
      axis*(this->dot(axis*(1 - cosAngle)))); //Rotation on local Y
}

float Vector3f::getX(){
   return x;
}

void Vector3f::setX(float x){
   this->x = x;
}

float Vector3f::getY(){
   return y;
}

void Vector3f::setY(float y){
   this->y = y;

}

float Vector3f::getZ(){
   return y;
}

void Vector3f::setZ(float z){
   this->z = z;

}

Vector3f Engine::Math::operator+(const Vector3f& vec1, const Vector3f& vec2) {
   Vector3f a(vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z);
   return a;
}

Vector3f Engine::Math::operator+(const Vector3f& vec1, float offset){
   return Vector3f(vec1.x + offset, vec1.y + offset, vec1.z + offset);
}

Vector3f Engine::Math::operator-(const Vector3f& vec1){
   Vector3f v(-vec1.x, -vec1.y, -vec1.z);
   return v;
}

Vector3f Engine::Math::operator-(const Vector3f& vec1, const Vector3f& vec2){
   Vector3f a(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z);
   return a;
}

Vector3f Engine::Math::operator-(const Vector3f& vec1, float offset){
   return Vector3f(vec1.x - offset, vec1.y - offset, vec1.z - offset);
}

Vector3f Engine::Math::operator*(const Vector3f& vec1, const Vector3f& vec2){
   return Vector3f(vec1.x*vec2.x, vec1.y*vec2.y, vec1.z*vec2.z);
}

Vector3f Engine::Math::operator*(const Vector3f vec1, float scale){
   return scale*vec1; //Use other overload here
}

Vector3f Engine::Math::operator*(float scale, const Vector3f vec1){
   return Vector3f(vec1.x*scale, vec1.y*scale, vec1.z*scale);
}

Vector3f Engine::Math::operator/(const Vector3f& vec1, const Vector3f& vec2){
   return Vector3f(vec1.x / vec2.x, vec1.y / vec2.y, vec1.z / vec2.z);
}

Vector3f Engine::Math::operator/(const Vector3f& vec1, float scale){
   return Vector3f(vec1.x / scale, vec1.y / scale, vec1.z / scale);
}