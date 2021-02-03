#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code from computer-graphics-raster-images
    std::ofstream ppm(filename);
  if (num_channels == 3 ) ppm << "P3" << std::endl;
  else ppm << "P2" << std::endl;
  
  ppm << width << " " << height << std::endl;
  ppm << "255" << std::endl;

  int i = 1;
  for (auto it = data.begin(); it != data.end(); it++, i++) {
    if (i % num_channels == 0){
      ppm << (int)*it << std::endl;
    }
    else{
      ppm << (int)*it << " ";
    }
  }

  ppm.close();
  return true;
  ////////////////////////////////////////////////////////////////////////////
}
