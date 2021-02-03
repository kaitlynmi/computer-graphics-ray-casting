#include "Sphere.h"
#include "Ray.h"
bool Sphere::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  Eigen::Vector3d e_minus_c = ray.origin-center;
  double test = ray.direction.dot(ray.origin-center);
  double a = ray.direction.dot(ray.direction);
  double b = 2 *  ray.direction.dot(e_minus_c);
  double c = e_minus_c.dot(e_minus_c) - radius *radius;

  double x1, x2;
  double discriminant = b*b - 4*a*c;
  
  if (discriminant > 0) {
      x1 = (-b + sqrt(discriminant)) / (2*a);
      x2 = (-b - sqrt(discriminant)) / (2*a);
  }
  
  else if (discriminant == 0) {
      x1 = -b/(2*a);
  }

  else {
    return false;
  }

  if(x1 >= min_t){
    t = x1;
  }
  if(x2 >= min_t && x2 < x1){
    t = x2;
  }

  Eigen::Vector3d phit = ray.origin + ray.direction * t; 
  n = (phit-center).normalized();

  return true;
  ////////////////////////////////////////////////////////////////////////////
}

