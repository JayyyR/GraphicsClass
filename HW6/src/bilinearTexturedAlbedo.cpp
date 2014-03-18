#include "bilinearTexturedAlbedo.h"
#include <iostream>

#include <math.h>       /* floor */
/////////////////
// Constructor //
/////////////////
bilinearTexturedAlbedo::bilinearTexturedAlbedo(const std::string& textureName)
{
  _texture.load(textureName);
}


bilinearTexturedAlbedo::bilinearTexturedAlbedo(const bilinearTexturedAlbedo& bta)
{
  _texture = bta._texture;
}



//////////////
// Operator //
//////////////
bilinearTexturedAlbedo& bilinearTexturedAlbedo::operator=(const bilinearTexturedAlbedo& bta)
{
  _assign(bta);
  return *this;
}



/////////////
// Methods //
/////////////
color bilinearTexturedAlbedo::evaluate(const vec2d& textureCoord) const
{
  // HW6: Implement this.
  //      Exactly the same as texturedAlbedo, but it now return the bilinearly interpolated texel color.
  double x = textureCoord.u * (_texture.width()-1);
  double y = textureCoord.v*(_texture.height()-1);
  
  //std::cout << "texture coords: "<< x<< ", " << y<< std::endl;
 // std::cout << "texture width height: "<< _texture.width()<< " " << _texture.height()<< std::endl;
  
  //if(x < 0) x = 0.0f;
 // else if(x > _texture.width() - 1) x = _texture.width() - 1;


  double x1 = floor(x);
  //std::cout << "x1: " << x1<< std::endl;
  double x2= x1+1;
  //std::cout << "x2: " << x2<< std::endl;
  double y1 = floor(y);
  //std::cout << "y1: "<< y1<< std::endl;
  double y2 = y1+1;
 // std::cout << "y2: "<< y2<< std::endl;
  double dx = x - x1;
  double dy = y - y1;
  //std::cout << "dx dy: "<< dx<< " " << dy<< std::endl;
  
  

  ///dunnno???
  
  if(x1 < 0) {
     std::cout << "x1 was less than 0: " << x1<< std::endl;
    x1 = 0.0f;
  }
  else if(x1 > _texture.width() - 1) {
     std::cout << "x1 was greater: " << x1<< std::endl;
    x1 = _texture.width() - 1;
  }
  if(x2 < 0) {
   std::cout << "x2 was less than 0: " << x2<< std::endl;
    x2 = 0.0f;
  }
  else if(x2 > _texture.width() - 1) {
    std::cout << "x2 was greater: " << x2<< std::endl;
    x2 = _texture.width() - 1;
    
  }
  if(y1 < 0) {
    std::cout << "y1 was less than 0: "<< y1<< std::endl;
    y1 = 0.0f;
  }
  else if(y1 > _texture.width() - 1) {
     std::cout << "y1 was greater: "<< y1<< std::endl;
    y1 = _texture.width() - 1;
  }
  if(y2 < 0) {
   std::cout << "y2 was less than 0: "<< y2<< std::endl;
    y2 = 0.0f;
  }
  else if(y2 > _texture.width() - 1){ 
   std::cout << "y2 was greater: "<< y2<< std::endl;
    y2 = _texture.width() - 1;
  }
  
  ///////
  
  color a = _texture(x1,y1) * (1-dx) + _texture(x2,y1)*dx;
  color b = _texture(x1,y2) * (1-dx) + _texture(x2,y2)*dx;
  color result = a*(1-dy) + b*dy;
  
  return result;
}



/////////////////////
// Private Methods //
/////////////////////
void bilinearTexturedAlbedo::_swap(bilinearTexturedAlbedo& bta)
{
  std::swap(_texture, bta._texture);
}


void bilinearTexturedAlbedo::_assign(const bilinearTexturedAlbedo& bta)
{
  _texture = bta._texture;
}


void bilinearTexturedAlbedo::_print(std::ostream& s) const
{
  s << "Bilinear Texture Albedo: (" << _texture.width() << "x" << _texture.height() << ")";
}
