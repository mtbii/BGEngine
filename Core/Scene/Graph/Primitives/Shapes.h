#pragma once

#include "../../../ModelUtils.h"
#include "../Entity.h"

namespace Shapes{
   class Box : public Entity
   {
   private:
      static int numLoaded;
      static std::vector<Model3D*> mesh;

   public:
      Box(const float& width, const float& height, const float& depth);
      ~Box();
   };

   class Cylinder : public Entity
   {
   public:
      Cylinder(const float& radius, const float& height);
      ~Cylinder();

      static int numLoaded;
      static std::vector<Model3D*> mesh;
   };

   class Monkey : public Entity
   {
   private:
      static int numLoaded;
      static std::vector<Model3D*> mesh;
   public:
      Monkey(const float& size);
      ~Monkey();
   };

   class Sphere : public Entity
   {
   private:
      static int numLoaded;
      static std::vector<Model3D*> mesh;
   public:
      Sphere(const float& radius);
      ~Sphere();
   };

};