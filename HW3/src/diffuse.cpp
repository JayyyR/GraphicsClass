#include "diffuse.h"
#include "constants.h"
#include <iostream>
#include <cstdlib>

using namespace std;

/////////////////
// Constructor //
/////////////////
diffuse::diffuse(void)
{
  // Do nothing.
}


diffuse::diffuse(const diffuse& d)
{
  // Do nothing
}



///////////////
// Operators //
///////////////
diffuse& diffuse::operator=(const diffuse& d)
{
  _assign(d);
  return *this;
}



/////////////
// Methods //
/////////////
float diffuse::evaluate(const vec3d& in, const vec3d& normal, const vec3d& /*out*/) const
{
  // HW3: Implement me
  //      Input: in = light source direction
  //             normal = surface normal
  //             out = view direction
  //      Modifies: nothing
  //      Returns: evaluation of the diffuse (Lambertian) brdf.
  
  float answer = (normal.dot(in));
  //cout<<"answer: " << answer << endl;
  
  return answer;   

}



///////////////////////
// Protected Methods //
///////////////////////
void diffuse::_swap(diffuse& d)
{
  // Do nothing.
}


void diffuse::_assign(const diffuse& d)
{
  // Do nothing.
}


void diffuse::_print(std::ostream& s) const
{
  s << "Diffuse BRDF";
}
