#include "Camera.h"

enum CameraControlType{ ArcBall, FPS };

class PerspectiveCamera : public Camera
{
private:
   CameraControl* control;

   CameraControlType controlType;
   float fov;
   float aspectRatio;
   float zNear;
   float zFar;

public:
   glm::vec3 position;
   glm::vec3 target;

   PerspectiveCamera(const CameraControlType& type, const float& fov, const float& aspectRatio, const float& zNear, const float& zFar);
   ~PerspectiveCamera();
   void Update();
};

