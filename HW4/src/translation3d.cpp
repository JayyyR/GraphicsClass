#include "translation3d.h"

//////////////////
// Constructors //
//////////////////
translation3d::translation3d(void) : transformation3d()
{
  // Do Nothing
}


translation3d::translation3d(const vec3d& translation) : transformation3d()
{
  // HW4: implement this
  //      return: nothing
  //      modifies: sets the member variables (defined in transformation3d) such that it represents a translation
  /*
  float x= translation[0];
  float y = translation[1];
  float z = translation[2];
  
  _transformation(0,3) = x;
  _transformation(1,3) = y;
  _transformation(2,3) = z;
  
  _inverseTransformation = _transformation.transpose();*/
  
  _translation = translation;
  
}


translation3d::translation3d(const translation3d& t) : transformation3d(t)
{
  // Do Nothing
}
