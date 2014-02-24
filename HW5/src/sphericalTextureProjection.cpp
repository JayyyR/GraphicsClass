#include "sphericalTextureProjection.h"

#include <cmath>
#include <iostream>
#include <cstdlib>


//////////////////
// Constructors //
//////////////////
sphericalTextureProjection::sphericalTextureProjection(void) : textureProjection_base()
{
  // Do nothing
}


sphericalTextureProjection::sphericalTextureProjection(const transformation3d& t) : textureProjection_base(t)
{
  // Do nothing
}


sphericalTextureProjection::sphericalTextureProjection(const sphericalTextureProjection& stp) : textureProjection_base(stp)
{
  // Do nothing
}



///////////////
// Operators //
///////////////
sphericalTextureProjection& sphericalTextureProjection::operator=(const sphericalTextureProjection& stp)
{
  _assign(stp);
  return *this;
}



///////////////////////
// Protected Methods //
///////////////////////
void sphericalTextureProjection::_assign(const sphericalTextureProjection& stp)
{
  textureProjection_base::_assign(stp);
}


void sphericalTextureProjection::_swap(sphericalTextureProjection& stp)
{
  textureProjection_base::_swap(stp);
}


void sphericalTextureProjection::_print(std::ostream& s) const
{
  s << "Spherical Texture Projection: " << _transformation;
}


vec2d sphericalTextureProjection::computeTextureCoordinate(const vec3d& v) const
{
  // HW5: Implement this.
  //      returns: the spherical coordinate (theta, phi) of v projected onto a unit sphere.
  //      modifies: nothing.
  
  vec3d projectedVec = v.normalize();
  double theta = acos(projectedVec.z);
  
  double phi = atan2(projectedVec.y,projectedVec.x);
  
  //std::cout << "phi: " << phi << std::endl;
  //adjust for negative angles
  if (phi<0){
    phi = (3.14159265359*2)+phi;
  }
  //std::cout << "adjusted phi: " << adjustedPhi << std::endl;
  
 // std::cout << "theta: " << theta << std::endl;
  //std::cout << "phi: " << phi << std::endl;
  
  return vec2d((phi/(3.14159265359*2)), (theta/(3.14159265359)));
}
