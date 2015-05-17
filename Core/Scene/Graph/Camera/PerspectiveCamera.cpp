#include "PerspectiveCamera.h"

PerspectiveCamera::PerspectiveCamera(const CameraControlType& type, const float& fov, const float& aspectRatio, const float& zNear, const float& zFar) :
controlType(type),
fov(fov),
aspectRatio(aspectRatio),
zNear(zNear),
zFar(zFar)
{
   this->projectionMatrix = glm::perspective(fov, aspectRatio, zNear, zFar);
   this->viewMatrix = glm::lookAt(position, target, glm::vec3(0.0f, 1.0f, 0.0f));
}

PerspectiveCamera::~PerspectiveCamera()
{

}

void PerspectiveCamera::Update()
{
   this->projectionMatrix = glm::perspective(fov, aspectRatio, zNear, zFar);
   this->viewMatrix = glm::lookAt(position, target, glm::vec3(0.0f, 1.0f, 0.0f));
}