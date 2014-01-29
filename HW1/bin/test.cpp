      #include <iostream>
      #include "vec3d.h"
      int main(int argc, char** argv)
      {
	std::cout << "Hello World!" << std::endl;
	
	vec3d u(3.0f, 1.0f, 2.0f);
	vec3d v(1.0f, 0.0f, 0.0f);
	vec3d w(0.0f, 1.0f, 0.0f);
	
	
	std::cout  << (u/4) << std::endl;
	return 0;
      }
      