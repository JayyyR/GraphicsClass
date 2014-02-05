#include "phong.h"
#include <math.h>
#include <iostream>
#include <cstdlib>

using namespace std;
/////////////////
// Constructor //
/////////////////
phong::phong(float sharpness)
{
  _sharpness = sharpness;
}


phong::phong(const phong& d)
{
  _sharpness = d._sharpness;
}



///////////////
// Operators //
///////////////
phong& phong::operator=(const phong& d)
{
  _assign(d);
  return *this;
}



/////////////
// Methods //
/////////////
float phong::evaluate(const vec3d& in, const vec3d& normal, const vec3d& out) const
{
  // HW3: Implement me
  //      Input: in = light source direction
  //             normal = surface normal
  //             out = view direction
  //      Modifies: nothing
  //      Returns: evaluation of the phong brdf.

  vec3d R = 2*(normal.dot(in))*normal - in;
  float answer = out.dot(R);
  float theAns = pow (answer, _sharpness);
  /*if(theAns<0){
    cout<<"returning: 0"<<endl;
    return 0.0f;
  }*/
 // cout<<"returning theAns: "<<theAns<<endl;
  return theAns;
}



///////////////////////
// Protected Methods //
///////////////////////
void phong::_swap(phong& d)
{
  std::swap(_sharpness, d._sharpness);
}


void phong::_assign(const phong& d)
{
  _sharpness = d._sharpness;
}


void phong::_print(std::ostream& s) const
{
  s << "Phong BRDF: " << _sharpness;
}
