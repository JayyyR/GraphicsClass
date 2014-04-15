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

  double x1 = floor(x);
  double x2= x1+1;
  double y1 = floor(y);
  double y2 = y1+1;
  double dx = x - x1;
  double dy = y - y1;

  //clamp values
  if(x1 < 0) {
    x1 = 0.0f;
  }
  else if(x1 > _texture.width() - 1) {
    x1 = _texture.width() - 1;
  }
  if(x2 < 0) {
    x2 = 0.0f;
  }
  else if(x2 > _texture.width() - 1) {
    x2 = _texture.width() - 1;
  }
  if(y1 < 0) {
    y1 = 0.0f;
  }
  else if(y1 > _texture.width() - 1) {
    y1 = _texture.width() - 1;
  }
  if(y2 < 0) {
    y2 = 0.0f;
  }
  else if(y2 > _texture.width() - 1){ 
    y2 = _texture.width() - 1;
  }
  
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
