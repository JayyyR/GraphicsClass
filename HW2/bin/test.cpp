#include <iostream>
#include "ray.h"
#include "image.h"
#include "camera.h"
#include "triangle.h"

image generateImage(const camera& cam, const triangle& t)
{
  image result(cam.width(), cam.height());
  result.clear();

  // for every pixel
  for(image::size_type y=0; y < result.height(); y++)
    for(image::size_type x=0; x < result.width(); x++)
    {
      // create a view ray
      ray r = cam.generateViewRay(x,y);

      // intersect
      float p;
      vec3d bc;
      bool hit = t.intersect(r, bc, p);
     
      // if hit
      if(hit)
      {
	 std::cout<< "bc is: " << bc << std::endl;
	// set the pixel color to the barycentric coordinate
	result(x,y) = color(bc[0], bc[1], bc[2]);
      }
    }

  // Done.
  return result;
}


int main(int argc, char** argv)
{
  std::cout << "Hello World!" << std::endl;
  
  triangle t1( vec3d(1.0f, -1.0f, -3.0f),
	       vec3d(0.0f, 1.0f, -3.0f),
	       vec3d(-1.0f, -1.0f, -3.0f) );
  
    camera c1( vec3d(0.0f, 0.0f, 0.0f),    // eye
	     vec3d(0.0f, 0.0f, -1.0f),   // view
	     vec3d(0.0f, 1.0f, 0.0f),    // up
	     60.0f / 180.0f * M_PI,      // field of view
	     512, 512 );                 // resolution
    
  image result1 = generateImage(c1, t1);
    
  return 0;
}

