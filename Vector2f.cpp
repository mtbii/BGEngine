#include "Vector2f.h"
using namespace Engine::Math;


Vector2f::Vector2f()
{
   this->x = 0;
   this->y = 0;
}

Vector2f::Vector2f(float x, float y)
{
   this->x = x;
   this->y = y;
}


Vector2f::~Vector2f()
{
}

float Vector2f::length(){
   return sqrt(x*x + y*y);
}

float Vector2f::dot(Vector2f v){
   return x * v.getX() + y * v.getY();
}

Vector2f Vector2f::normalize(){
   float length = this->length();
   x /= length;
   y /= length;
   return *this;
}

Vector2f Vector2f::rotateDegrees(float angle){
   float rads = 4 * atan(1.0) / 180.0f * angle;
   return rotate(rads);
}

Vector2f Vector2f::rotate(float angle){
   float cosine = cos(angle);
   float sine = sin(angle);

   return Vector2f(x*cosine - y*sine, x*sine + y*cosine);
}

float Vector2f::getX(){
   return x;
}

void Vector2f::setX(float x){
   this->x = x;
}

float Vector2f::getY(){
   return y;
}

void Vector2f::setY(float y){
   this->y = y;

}


Vector2f Engine::Math::operator+(const Vector2f& vec1, const Vector2f& vec2) {
   Vector2f a(vec1.x + vec2.x, vec1.y + vec2.y);
   return a;
}

Vector2f Engine::Math::operator+(const Vector2f& vec1, float offset){
   return Vector2f(vec1.x + offset, vec1.y + offset);
}

Vector2f Engine::Math::operator-(const Vector2f& vec1){
   Vector2f v(-vec1.x, -vec1.y);
   return v;
}

Vector2f Engine::Math::operator-(const Vector2f& vec1, const Vector2f& vec2){
   Vector2f a(vec1.x - vec2.x, vec1.y - vec2.y);
   return a;
}

Vector2f Engine::Math::operator-(const Vector2f& vec1, float offset){
   return Vector2f(vec1.x - offset, vec1.y - offset);
}

Vector2f Engine::Math::operator*(const Vector2f& vec1, const Vector2f& vec2){
   return Vector2f(vec1.x*vec2.x, vec1.y*vec2.y);
}

Vector2f Engine::Math::operator*(const Vector2f vec1, float scale){
   return scale*vec1; //Use other overload here
}

Vector2f Engine::Math::operator*(float scale, const Vector2f vec1){
   return Vector2f(vec1.x*scale, vec1.y*scale);
}

Vector2f Engine::Math::operator/(const Vector2f& vec1, const Vector2f& vec2){
   return Vector2f(vec1.x / vec2.x, vec1.y / vec2.y);
}

Vector2f Engine::Math::operator/(const Vector2f& vec1, float scale){
   return vec1 * (1.0f / scale);
}