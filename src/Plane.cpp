#include "Plane.h"
#include "Ray.h"

bool Plane::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  t = (normal * -1.0).dot(ray.origin - point) / normal.dot(ray.direction) ;
  n = normal;
  return true;
  ////////////////////////////////////////////////////////////////////////////
}

