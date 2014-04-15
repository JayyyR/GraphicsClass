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
    // init
    _left = _right = NULL;
    _triangle = NULL;
    
    
    std::cout<<"startindex: "<< start_index<<"end_index:"<<end_index<<std::endl;
    if (start_index >= end_index)	{
      _triangle = triangleList[start_index];
      return;
    }
    //else sort the indices spatially then create new elemenets with those halves?
    std::cout<<"yo"<<std::endl;
    
    struct centroidItem {
      float theCentroid;
      const triangle* tri;
    } ;
    
    int centroidListSize = end_index-start_index+1;
    centroidItem centroidList[centroidListSize];
    
    
    //grab centroids
    int listIndex = 0;
    for(int i = start_index; i < end_index+1; i++){
      float daCentroid = centroid(triangleList, i, 0);
      
      //create centroid item
      centroidItem item;
      item.theCentroid = daCentroid;
      item.tri = triangleList[i];
      
      centroidList[listIndex] = item; //add centroid to centroidlist
      listIndex++;
    }
    
    //print centroid list
    for(int i = 0; i<(centroidListSize); i++){
      std::cout<<"centroid list: " << centroidList[i].theCentroid << std::endl;
      std::cout<<"centroid tri: " << centroidList[i].tri->vertex(0) << std::endl;
    }
    
    //grab random centroid to act as pivot
    int pivotNum = rand()%centroidListSize;
    std::cout<<"pivotNum is: "<< pivotNum << std::endl;
    float randCentroid = centroidList[pivotNum].theCentroid;
    std::cout<<"rand centroid is: "<< randCentroid << std::endl;
    
    //partition the centroid list
    int i = 0;
    int j = centroidListSize-1;
    while (i<=j){
      std::cout<<"i is: "<< i<< std::endl;
      std::cout<<"j is: " <<j<<std::endl;
      while (centroidList[i].theCentroid < randCentroid)
	i++;
      while (centroidList[j].theCentroid > randCentroid)
	j--;
      
      if (i<=j){
	//swap the items
	centroidItem tempItem;
	tempItem.theCentroid = centroidList[i].theCentroid;
	tempItem.tri = centroidList[i].tri;
	centroidList[i] = centroidList[j];
	centroidList[j] = tempItem;
	
	//change pivotnum
	if (i==pivotNum)
	  pivotNum=j;
	else if (j==pivotNum)
	  pivotNum=i;
	
	i++;
	j--;
      }
    }
    
    //pivotnum is where the pivot is currently located in the centroid list
    std::cout<<"pivotNum is: " <<pivotNum<<std::endl;
    //print centroid list
    for(int i = 0; i<(centroidListSize); i++){
      std::cout<<"centroid list: " << centroidList[i].theCentroid << std::endl;
      std::cout<<"centroid tri: " << centroidList[i].tri->vertex(0) << std::endl;
    }
    
    //find midpoint by adjusting pivotnum for the start and end indicies
    int midpoint = start_index+pivotNum;
    std::cout<<"midpoint is: " <<midpoint<<std::endl;
    //change triangle pointers in triangle list to reflect the triangle pointers in centroidList
    int centListIdx = 0;
    for(int i = start_index; i < end_index+1; i++){
      triangleList[i] = centroidList[centListIdx].tri;
      centListIdx++;
    }
    
    //recurse for left and right nodes
    _left = new boundingVolumeElement(triangleList, start_index, midpoint);
    _right = new boundingVolumeElement(triangleList, midpoint+1, end_index);

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
    
    if (_bb.isHit(r)){
      return true;
    }
    
    return false;
  }
  
  
  bool boundingVolumeElement::isHit(const ray& r) const
  {
    // Homework 7: returns true if this element or any of its children is hit by the ray r.
    //        modifies: nothing
    //        returns: true/false on hit/miss
    
   // if (_left == NULL && _right == NULL){
     
      float t;
      vec3d bc;
      if (_triangle->intersect(r, bc, t))
	return true;
      else{
	_left->isHit(r);
	_right->isHit(r);
      }
   // }
      
    return false;
  }
  
  
  intersectionPoint boundingVolumeElement::intersect(const ray& r, const triangleMesh& mesh) const
  {
    // Homework 7: returns the intersection point of the triangle (stored in this element or any of its children) closest to the origin on the ray r.
    //             Note that the triangleMesh is provided in order to be able to create an intersection point (which needs the material, and which is
    //             not stored in the mesh).  You can assume that the mesh is the same as the one that was used for creating the bounding volume hierarchy.
    //        modifies: nothing
    //        returns: intersection point of the hit
    return intersectionPoint();
  }
  
  
  
  /////////////////////
  // Private Methods //
  /////////////////////
  float boundingVolumeElement::centroid(const std::vector<const triangle*>& list, unsigned int index, unsigned int coord)
  {
    return (list[index]->vertex(0)[coord] + list[index]->vertex(1)[coord] + list[index]->vertex(2)[coord]) / 3.0f;
  }
  
  