#include "OrthographicCamera.h"

OrthographicCamera::OrthographicCamera(const float& left, const float& right, const float& bottom, const float& top, const float& zNear, const float& zFar) :
left(left),
right(right),
bottom(bottom),
top(top),
zNear(zNear),
zFar(zFar)
{
   this->projectionMatrix = glm::ortho(left, right, bottom, top, zNear, zFar);
   this->viewMatrix = glm::mat4(1.0);
}

OrthographicCamera::~OrthographicCamera()
{

}

void OrthographicCamera::Update()
{
   this->projectionMatrix = glm::ortho(left, right, bottom, top, zNear, zFar);
}