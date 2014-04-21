    #include "constants.h"
    #include "boundingVolumeElement.h"
    #include <string>
    #include <cstdio>
    #include <cstdlib>
    #include <iostream>
    
    
    //////////////////
    // Constructor //
    /////////////////
    boundingVolumeElement::boundingVolumeElement(std::vector<const triangle*>& triangleList, unsigned int start_index, unsigned int end_index)
    {
      //std::cout<<"yo"<<std::endl;
      // init
      _left = _right = NULL;
      _triangle = NULL;
      
      
      std::cout<<"startindex: "<< start_index<<"end_index:"<<end_index<<std::endl;
      if (start_index >= end_index){
	std::cout<<"SETTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTING TRIANLGE"<<std::endl;
	_triangle = triangleList[start_index];
	std::cout<<"returning early"<< std::endl;
	
	//debug print
	/*if (start_index==1983){
	  for(int i = 0; i<=end_index; i++){
	    std::cout<<"FINALLL centroid list: " << centroid(triangleList, i, 1) << std::endl;
	    //std::cout<<"centroid tri: " << centroidList[i].tri->vertex(0) << std::endl;
	  }
	  
	}*/
	return;
      }
      //else sort the indices spatially then create new elemenets with those halves

      //grab random centroid to act as pivot
      int pivotNum = rand() % (end_index+1 - start_index) +start_index;
      std::cout<<"pivotNum is: "<< pivotNum << std::endl;
      int randAxis = rand() % (3);
      std::cout<<"random axis is: "<< randAxis << std::endl;
      float randCentroid = centroid(triangleList, pivotNum, randAxis);
      std::cout<<"rand centroid is: "<< randCentroid << std::endl;
      
      //print centroid list
      for(int i = start_index; i<=end_index; i++){
      std::cout<<"centroid list: " << centroid(triangleList, i, randAxis) << std::endl;
	//std::cout<<"centroid tri: " << centroidList[i].tri->vertex(0) << std::endl;
      }

      //partition the centroid list
      int i = start_index;
      int j = end_index;
      
      std::cout<<"BEFORE i is: " << i << " j is: " << j<<std::endl;
      while (i<j){
	while (centroid(triangleList, i, randAxis) <= randCentroid && i<j){
	  //std::cout<<"increasing i...the centroid is:" << centroid(triangleList, i, randAxis)<< std::endl;
	  i++;
	}
	while (centroid(triangleList, j, randAxis) > randCentroid && i<j){
	  //std::cout<<"decreasing j...the centroid is:" << centroid(triangleList, j, randAxis)<< std::endl;
	  j--;
	}
	std::cout<<"i is: " << i << " j is: " << j<<std::endl;
	
	  //swap
	  const triangle* tempTri = triangleList[i];
	  triangleList[i] = triangleList[j];
	  triangleList[j] = tempTri;
      }
      

      
      //print centroid list
      for(int i = start_index; i<=end_index; i++){
      std::cout<<"after centroid list: " << centroid(triangleList, i, randAxis) << std::endl;
	//std::cout<<"centroid tri: " << centroidList[i].tri->vertex(0) << std::endl;
      }

      //std::cout<<"CHECKING I and J when finding MIDPOINT i is: " << i << " j is: " << j<<std::endl;

      if(i>0){
	std::cout<<"GOING LEFT"<<std::endl;
	_left = new boundingVolumeElement(triangleList, start_index, i-1);
      }

	std::cout<<"GOING RIGHT"<<std::endl;
	_right = new boundingVolumeElement(triangleList, i, end_index);

      // Homework 7: This is the constructor that will create the bounding volume hierarchy. This hierarchy will be in the form of a binary tree, where each bounding
      //             volume element refers to zero, one or two child elements. As input you get a list of (pointers to) triangles, and a start and end index
      //             which indicate which part of the triangleList you need to create the bounding volume hierarchy for: triangleList[start_index] to 
      //             (including) triangleList[end_index].  The object itself stores the following information: a bounding box, a pointer to two child elements (_left and 
      //             _right), and a pointer to a triangle (_triangle).  You are free to choose whether you want to include a triangle in every element, or only at the leaf
      //             nodes (in which case you leave the pointer to _triangle at NULL).
      //     modifies: triangleList can be altered (optional).  Note that you can only change the _order_ of the pointers, not the content of the linked triangles.
      //     returns: nothing
    }
    
    
    
    ////////////////
    // Destructor //
    ////////////////
    boundingVolumeElement::~boundingVolumeElement(void)
    {
      if(_left) delete _left;
      if(_right) delete _right;
      if(_triangle) _triangle = NULL;
    }
    
    
    
    /////////////
    // Methods //
    /////////////
    bool boundingVolumeElement::isBoundingBoxHit(const ray& r) const
    {
      // Homework 7: returns true if the bounding box of this node is hit by the ray r.
      //        modifes: nothing
      //        returns: true/false when hit/missed.
      //std::cout<<"isbbhit"<<std::endl;
      
      //std::cout<<"bb size: " << _bb.size()<<std::endl;
      if (_bb.isHit(r)){
	return true;
      }
      
      return false;
    }
    
    
    bool boundingVolumeElement::isHit(const ray& r) const
    {
      //std::cout<<"is hit"<<std::endl;
      // Homework 7: returns true if this element or any of its children is hit by the ray r.
      //        modifies: nothing
      //        returns: true/false on hit/miss
      
      
      
      //if bounding box not hit, return false
      if (!_bb.isHit(r)){
	return false;
      }
      
      //if no children, check triangle
      if (_left == NULL && _right == NULL){
	float t;
	vec3d bc;
	if (_triangle->intersect(r, bc, t))
	  return true;
	else
	  return false;
      }
      
      //otherwise recurse
      if (_left->isHit(r))
	return true;
      if (_right->isHit(r))
	return true;
      
      return false;

    }
    
    
    intersectionPoint boundingVolumeElement::intersect(const ray& r, const triangleMesh& mesh) const
    {
    // std::cout<<"intersect"<<std::endl;
      // Homework 7: returns the intersection point of the triangle (stored in this element or any of its children) closest to the origin on the ray r.
      //             Note that the triangleMesh is provided in order to be able to create an intersection point (which needs the material, and which is
      //             not stored in the mesh).  You can assume that the mesh is the same as the one that was used for creating the bounding volume hierarchy.
      //        modifies: nothing
      //        returns: intersection point of the hit
      
      //if bounding box not hit, return false
    // std::cout<<"checking bb hit"<<std::endl;
      if (!_bb.isHit(r)){
	//std::cout<<"bb not hti"<<std::endl;
	return intersectionPoint();
      }
      
      //if no children, check triangle
      //std::cout<<"checking if children"<<std::endl;
      if (_left == NULL && _right == NULL){
	float t;
	vec3d bc;
	//std::cout<<"in children"<<std::endl;
	//if (_triangle == NULL)
	  //std::cout<<"triangle was null"<<std::endl;
	//std::cout<<"triangle: " << _triangle<<std::endl;
	if (_triangle->intersect(r, bc, t)){
	  //std::cout<<"returning good intersect point"<<std::endl;
	  return intersectionPoint(r, bc, t, *_triangle, mesh.getMaterial());
	}
	else{
	  //std::cout<<"returning bad intersect point"<<std::endl;
	  return intersectionPoint();
	}
      }
      
      //otherwise recurse
      intersectionPoint leftIP = _left->intersect(r, mesh);
      intersectionPoint rightIP = _right->intersect(r,mesh);

      //std::cout<<"checking closest ray"<<std::endl;
      //return IP closest to origin of the ray
      if (leftIP < rightIP){
      // std::cout<<"returning leftIP"<<std::endl;
	return leftIP;
      }
      else{
	//std::cout<<"returning rightIP"<<std::endl;
	return rightIP;
      }
    }
    
    
    
    /////////////////////
    // Private Methods //
    /////////////////////
    float boundingVolumeElement::centroid(const std::vector<const triangle*>& list, unsigned int index, unsigned int coord)
    {
      return (list[index]->vertex(0)[coord] + list[index]->vertex(1)[coord] + list[index]->vertex(2)[coord]) / 3.0f;
    }
    
    