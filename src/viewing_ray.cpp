#include "viewing_ray.h"

void viewing_ray(
  const Camera & camera,
  const int i,
  const int j,
  const int width,
  const int height,
  Ray & ray)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  double u = camera.width/width * (i + 0.5) - camera.width /2;
  double v = camera.height/height * (j + 0.5) - camera.height /2;

  if( u == 0 && v == 0 ){
    int center = 0;
  }

  Eigen::Vector3d direction(u, v, -camera.d);
  ray.origin = camera.e;
  ray.direction = direction - camera.e;
  ////////////////////////////////////////////////////////////////////////////
}

