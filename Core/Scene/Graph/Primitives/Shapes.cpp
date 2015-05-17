#include "Shapes.h"

using namespace Shapes;
using namespace std;

int Box::numLoaded = 0;
int Cylinder::numLoaded = 0;
int Sphere::numLoaded = 0;
int Monkey::numLoaded = 0;

vector<Model3D*> Box::mesh;
vector<Model3D*> Cylinder::mesh;
vector<Model3D*> Sphere::mesh;
vector<Model3D*> Monkey::mesh;

Box::Box(const float& width, const float& height, const float& depth) : Entity()
{
   if (numLoaded == 0)
   {
      mesh = ModelUtils::LoadModel("Core/Scene/Graph/Primitives/obj/cube.obj");
   }

   this->components = mesh;
   this->transform = new Transform();
   this->transform->SetScale(glm::vec3(width / 2, height / 2, depth / 2));
   numLoaded++;
}

Box::~Box(){
   numLoaded--;
   if (numLoaded == 0)
   {
      for (unsigned int i = 0; i < mesh.size(); i++)
      {
         delete mesh[i];
      }
      mesh.clear();
   }
}

Cylinder::Cylinder(const float& radius, const float& height) : Entity()
{
   if (numLoaded == 0)
   {
      mesh = ModelUtils::LoadModel("Core/Scene/Graph/Primitives/obj/cylinder.obj");
   }

   this->components = mesh;
   this->transform = new Transform();
   this->transform->SetScale(glm::vec3(radius / 2, height / 2, radius / 2));
   numLoaded++;
}

Cylinder::~Cylinder(){
   numLoaded--;
   if (numLoaded == 0)
   {
      for (unsigned int i = 0; i < mesh.size(); i++)
      {
         delete mesh[i];
      }
      mesh.clear();
   }
}

Sphere::Sphere(const float& radius) : Entity()
{
   if (numLoaded == 0)
   {
      mesh = ModelUtils::LoadModel("Core/Scene/Graph/Primitives/obj/sphere.obj");
   }

   this->components = mesh;
   this->transform = new Transform();
   this->transform->SetScale(glm::vec3(radius / 2));
   numLoaded++;
}

Sphere::~Sphere()
{
   numLoaded--;
   if (numLoaded == 0)
   {
      for (unsigned int i = 0; i < mesh.size(); i++)
      {
         delete mesh[i];
      }
      mesh.clear();
   }
}
Monkey::Monkey(const float& size) : Entity()
{
   if (numLoaded == 0)
   {
      mesh = ModelUtils::LoadModel("Core/Scene/Graph/Primitives/obj/monkey.obj");
   }

   this->components = mesh;
   this->transform = new Transform();
   this->transform->SetScale(glm::vec3(size / 2));
   numLoaded++;
}

Monkey::~Monkey(){
   numLoaded--;
   if (numLoaded == 0)
   {
      for (unsigned int i = 0; i < mesh.size(); i++)
      {
         delete mesh[i];
      }
      mesh.clear();
   }
}