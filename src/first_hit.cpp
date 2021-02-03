#include "first_hit.h"

bool first_hit(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  int & hit_id, 
  double & t,
  Eigen::Vector3d & n)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  int index = 0;
  double closest = 0;
  std::vector<std::shared_ptr<Object>>::iterator it;
  //output
  double temp_t = 0;
  Eigen::Vector3d temp_n;

  for (auto & it : objects) {
    if (it->intersect(ray, min_t,temp_t,temp_n))
    {
      if (temp_t >= min_t && (temp_t < closest || closest == 0) )
      {
        closest = temp_t;
        t = temp_t;
        hit_id = index;
        n = temp_n;
      }
      
    }
    index ++;
  }
  return true;
  ////////////////////////////////////////////////////////////////////////////
}

