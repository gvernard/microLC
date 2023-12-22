#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <string>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>

#include <png.h>
#include <CCfits/CCfits>

class Image {
public:
  std::string imageType;
  int Nx;
  int Ny;
  double* data = NULL;
  
  ~Image(){
    free(data);
  };
  
  void writeImageBIN(const std::string filename,int sampling);
  void writeImagePNG(const std::string filename,int sampling);
  void writeImagePNG(const std::string filename,int sampling,int xmin,int xmax,int ymin,int ymax);
  void writeImageFITS(const std::string filename,int sampling);
  
private:
  void scaleMap(int* colors,int sampling);
  void scaleMap(int* colors,int sampling,int xmin,int xmax,int ymin,int ymax);
  void scaleProfile(int* colors,int sampling);
  void setRGB(int* rgb);
  void readRGB(const std::string filename,int* rgb);
  void writeObjectPNG(const std::string filename, int width,int height,int* colors,int* rgb);
  
  const std::vector<int> r{255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,254,250,247,243,240,236,232,229,225,222,218,214,211,207,205,202,198,195,191,187,184,180,177,173,169,166,162,159,155,152,148,144,141,137,134,132,128,125,121,117,114,110,107,103,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102};
  const std::vector<int> g{255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,254,253,252,251,250,249,248,247,246,246,245,243,242,241,240,239,238,237,236,235,234,233,232,225,216,206,197,188,178,169,160,155,146,136,127,118,108,99,92,90,88,86,85,83,81,80,78,76,75,73,71,70,69,67,65,64,62,60,59,57,55,53,52,50,48,47,45,43,42,40,38,37,35,34,32,31,29,27,26,24,22,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20};
  const std::vector<int> b{255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,247,237,226,216,205,195,184,174,164,158,148,137,127,117,106,96,85,75,64,54,43,33,23,21,22,22,23,24,25,26,27,27,28,29,30,31,31,32,33,35,37,39,41,43,45,47,49,51,53,55,57,59,60,61,63,65,67,69,71,73,75,77,79,81,83,85,87,88,90,92,94,96,98,99,101,103,105,107,109,111,113,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115};
};

#endif /* IMAGE_HPP */
