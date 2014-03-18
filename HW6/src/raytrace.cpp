#include <cstdlib>
#include <iostream>
#include "raytrace.h"

#include "ray.h"
#include "vec3d.h"
#include "image.h"
#include "constants.h"
#include "intersectionPoint.h"

color recursiveRayTrace(const ray& r, unsigned int maxBounce, const scene& scene){
  
  //std::cout<<"maxBounce: " << maxBounce << std::endl;
  if (maxBounce < 1){
    //std::cout<<"returning black" << std::endl;
    return color(0.0f,0.0f,0.0f);
  }
  color col;
  //pass in ray from reflected direection, so this has to be called later on, fix recursive logic
  
  
  intersectionPoint ip = scene.intersect(r);
  
  vec3d direction = r.direction();
  vec3d normal = ip.normal();
  
  //if not hit, return environment map or black
  if (!ip.isHit()){
    
    if (scene.hasEnvironmentMap()){
      return scene.getEnvironmentMap().evaluate(r);
    }
    else{
      return color(0.0f,0.0f,0.0f);
    }
  }
  
  vec3d reflected = 2.0f * (normal.dot(direction)) * normal - direction;
  
  //grab a ray with the intersection point and the 3d vec reflected
  ray newRay = ray(ip.point(), -1*reflected);
  col += recursiveRayTrace(newRay, maxBounce-1, scene) *  ip.evaluate(-1*reflected);
  //std::cout<<"maxBounce: " << maxBounce << std::endl;
  //int i;
  //std::cin >> i;
  if(ip.isHit()){
    //std::cout<<"ip was hit" << std::endl;
    //what if there are multiple lightsource
    for (int i=0; i < scene.numberOfLightSources(); i++){
      //std::cout<<"for each light source" << std::endl;
      //shoot ray from object to lightsource for shadows
      vec3d dir = scene.lightSource(i).getDirection(ip.point());
      ray rayToLight = ray(ip.point(), dir*-1);
      intersectionPoint pointToLight = scene.intersect(rayToLight);
      
      //if the ray to the light isn't blocked, add the color
      if (!pointToLight.isHit()){
	//std::cout << ip.evaluate(scene.lightSource(i)) << std::endl;
	//if hte color isn't black, add it to the image
	//std::cout<<"maxBounce: " << maxBounce << std::endl;
	//std::cout<<"scene lightsource: " << ip.evaluate(scene.lightSource(i)) << std::endl;
	
	col += (ip.evaluate(scene.lightSource(i))); //*-1
      }
      
      
      
    }
  }
  
  return col;
  
  
}

image raytrace(const scene& scene, unsigned int samplesPerPixel, unsigned int maxBounce)
{
  // HW 6: implement this
  //       returns: the image of the 'scene', by shooting 'samplesPerPixel' randomly selected 
  //                rays through every pixel, and following specular reflections for 'maxBounce'
  //                bounces (eye->1st intersection == 1 bounce).
  //       modifes: nothing
  
  image result(scene.getCamera().width(), scene.getCamera().height());
  result.clear();
  
  camera cam = scene.getCamera();
  std::cout<< "samples per pixel: " << samplesPerPixel << std::endl;
  int multipleSamples=0;
  if (samplesPerPixel > 1 ){
    std::cout<< "set multiple samples to 1"<<std::endl;
    multipleSamples = 1;
  }
  
  // for every pixel
  for(image::size_type y=0; y < result.height(); y++)
    for(image::size_type x=0; x < result.width(); x++)
    {
      
      int samples = samplesPerPixel;
      color multipleColor = color(0.0f,0.0f,0.0f);
      //multiple samples
      while (samples>0){
	//std::cout<< "samles before subtracting: " << samples<<std::endl;
	samples--;
	
	double xOffset;
	double yOffset;
	
	//center of pixel
	xOffset = .5;
	yOffset = .5;
	//std::cout<< "multiple samples: " << multipleSamples << std::endl;
	//if more than one sample
	if (multipleSamples == 1){
	  //std::cout<<"generating new randoms"<<std::endl;
	  xOffset = ((double) rand() / (RAND_MAX));
	  yOffset = ((double) rand() / (RAND_MAX));
	  
	}
	color col=color(0.0f,0.0f,0.0f);
	
	
	// create view ray
	ray r = cam.generateViewRay(x+xOffset, y+yOffset);
	
	if (maxBounce>1){
	  col = recursiveRayTrace(r, maxBounce, scene);
	}
	else{
	  // intersect
	  intersectionPoint ip = scene.intersect(r);
	  //std::cout << "# of lightsources: "<< scene.numberOfLightSources() << std::endl;
	  
	  
	  // if hit
	  if(ip.isHit())
	  {
	    
	    
	    //what if there are multiple lightsource
	    for (int i=0; i < scene.numberOfLightSources(); i++){
	      
	      
	      //shoot ray from object to lightsource for shadows
	      vec3d dir = scene.lightSource(i).getDirection(ip.point());
	      ray rayToLight = ray(ip.point(), dir*-1);
	      intersectionPoint pointToLight = scene.intersect(rayToLight);
	      
	      //if the ray to the light isn't blocked, add the color
	      if (!pointToLight.isHit()){
		//std::cout << ip.evaluate(scene.lightSource(i)) << std::endl;
		//if hte color isn't black, add it to the image
		col += ip.evaluate(scene.lightSource(i));
	      }
	      
	    }
	    //std::cout<< "samples is: "<<samples<< " and result is: " << col << std::endl;
	    //std::cout<< "x is: " << x<< ", y is: " << y << std::endl;
	    
	  }
	  else{
	    //if not hit, return environment map or black
	    if (scene.hasEnvironmentMap()){
	      col+= scene.getEnvironmentMap().evaluate(r);
	    }
	    
	  }
	  
	}
	multipleColor += col;
	//std::cout<<"adding to multiple color, samples is: " << samples<<std::endl;
	
      }
      //set result to the average color based on the colors of all sample rays
      result(x,y) = multipleColor/samplesPerPixel;
    }
    
    return result;
}


