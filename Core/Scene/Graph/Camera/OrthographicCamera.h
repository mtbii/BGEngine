#include "Camera.h"

class OrthographicCamera : public Camera
{
private:
   float left;
   float right;
   float bottom;
   float top;
   float zNear;
   float zFar;

public:
   OrthographicCamera(const float& left, const float& right, const float& bottom, const float& top, const float& zNear, const float& zFar);
   ~OrthographicCamera();

   virtual void Update();
};