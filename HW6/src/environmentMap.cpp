#include "environmentMap.h"
#include "vec2d.h"
//////////////////
// Constructors //
//////////////////
environmentMap::environmentMap(const std::string& textureName, const transformation3d& transformation)
{
  _texture.load(textureName);
  _transformation = transformation;
}


environmentMap::environmentMap(const environmentMap& em)
{
  _texture = em._texture;
  _transformation = em._transformation;
}


  
//////////////
// Operator //
//////////////
environmentMap& environmentMap::operator=(const environmentMap& em)
{
  _assign(em);
  return *this;
}



/////////////
// Methods //
/////////////
color environmentMap::evaluate(const ray& r) const
{
  // HW6: implement this
  //      returns: the color in the environment in direction r.  You can see the environment as an infinitely 
  //               large sphere that sits around the scene (and which reflects light inwards).  You should use
  //               the normal theta-phi encoding of direction to texture coordinate.
  //      modifies: nothing
  
  vec3d v = r.direction();
  
   // normalize
  vec3d n = v.normalize();

  // compute (theta,phi)
  vec2d thetaPhi(atan2(n.y, n.x), acos(n.z));

  // map to [0,1]
  if(thetaPhi.u < 0.0f) thetaPhi.u += (2.0f * M_PI);
  thetaPhi /= vec2d(2.0f * M_PI, M_PI);
  
  //bilinearly interpolate thetaphi
  double x = thetaPhi.u * (_texture.width()-1);
  double y = thetaPhi.v*(_texture.height()-1);
  

  double x1 = floor(x);
  double x2= x1+1;
  double y1 = floor(y);
  double y2 = y1+1;
  double dx = x - x1;
  double dy = y - y1;

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
void environmentMap::_swap(environmentMap& em)
{
  std::swap(_texture, em._texture);
  std::swap(_transformation, em._transformation);
}


void environmentMap::_assign(const environmentMap& em)
{
  // sanity check
  if(this == &em) return;

  // copy
  environmentMap temp(em);
  _swap(temp);

  // Done.
}
