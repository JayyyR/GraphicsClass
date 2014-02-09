#include "rotation3d.h"

//////////////////
// Constructors //
//////////////////
rotation3d::rotation3d(void) : transformation3d()
{
  // Do Nothing
}


rotation3d::rotation3d(float angle, const vec3d& axis) : transformation3d()
{
  // HW4: implement this.
  //      returns: nothing
  //      modifies: sets the member variables (defined in transformation3d) such that it performs a rotation of specified 'angle' along an 'axis'

  float s = sin(angle);
  float c = cos(angle);
  
  float x = axis[0];
  float y = axis[1];
  float z = axis[2];
  
  _transformation(0,0) = (c + pow(x,2)*(1-c));
  _transformation(0,1) = (x*y*(1-c)-z*s);
  _transformation(0,2) = (y*s+x*z*(1-c));
  _transformation(1,0) = (z*s+x*y*(1-c));
  _transformation(1,1) = (c+pow(y,2)*(1-c));
  _transformation(1,2) = (-x*s+y*z*(1-c));
  _transformation(2,0) = (-y*s+x*z*(1-c));
  _transformation(2,1) = (x*s+y*z*(1-c));
  _transformation(2,2) = (c+pow(z,2)*(1-c));
  
  _inverseTransformation = _transformation.transpose();
  
}


rotation3d::rotation3d(const rotation3d& r) : transformation3d(r)
{
  // Do Nothing
}
