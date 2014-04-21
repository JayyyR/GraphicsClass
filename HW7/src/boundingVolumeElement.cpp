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
      return;
    }
    //else sort the indices spatially then create new elemenets with those halves?
   // std::cout<<"yo"<<std::endl;
    
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
      std::cout<<"DA CENTROIDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDd: "<<daCentroid<<std::endl;
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
      //std::cout<<"centroid tri: " << centroidList[i].tri->vertex(0) << std::endl;
    }
    
    //grab random centroid to act as pivot
    int pivotNum = rand()%centroidListSize;
    //int pivotNum = centroidListSize-1;
    std::cout<<"pivotNum is: "<< pivotNum << std::endl;
    float randCentroid = centroidList[pivotNum].theCentroid;
    std::cout<<"rand centroid is: "<< randCentroid << std::endl;
    
    /*
    //move pivot to end
    centroidItem temp;
    temp.theCentroid = centroidList[centroidListSize-1].theCentroid;
    temp.tri = centroidList[centroidListSize-1].tri;
    centroidList[centroidListSize-1] = centroidList[pivotNum];
    centroidList[pivotNum] = temp;*/
	
    
    //partition the centroid list
    int i = 0;
    std::cout<<"centroid list size is: "<< centroidListSize <<std::endl;
    int j = centroidListSize-1;
    
     std::cout<<"BEFORE i is: " << i << " j is: " << j<<std::endl;
    while (i<j){
     // std::cout<<"i is: "<< i<< std::endl;
     // std::cout<<"j is: " <<j<<std::endl;
      while (centroidList[i].theCentroid <= randCentroid && i<j){
	std::cout<<"increasing i...the centroid is: " << centroidList[i].theCentroid << std::endl;
	i++;
      }
      while (centroidList[j].theCentroid > randCentroid && i<j){
	std::cout<<"decreasing j...the centroid is: " << centroidList[j].theCentroid << std::endl;
	j--;
      }
      std::cout<<"i is: " << i << " j is: " << j<<std::endl;
      
      /*// if the values are equal increase i or decrease j depending on where the pivot is located
      if (centroidList[i].theCentroid == centroidList[j].theCentroid){
	if (i==pivotNum){
	  std::cout<<"they were the same, decreasing j"<< std::endl;
	  j--;
	}
	else{
	  std::cout<<"they were the same, increasing i"<< std::endl;
	  i++;
	}  
      }*/
      /*else */
      //if (i<=j){
	//swap the items
	centroidItem tempItem;
	tempItem.theCentroid = centroidList[i].theCentroid;
	tempItem.tri = centroidList[i].tri;
	centroidList[i] = centroidList[j];
	centroidList[j] = tempItem;
	
	/*//change pivotnum
	if (i==pivotNum){
	  std::cout<<"pivotNum is changing from" << i << "to" << j <<std::endl;
	  pivotNum=j;
	}
	else if (j==pivotNum){
	  std::cout<<"pivotNum is changing from" << j << "to" << i <<std::endl;
	  pivotNum=i;
	}*/
	
	//i++;
	//j--;
      //}
      
      
    }
    
    /*std::cout<<"moving pivot back to j+1: " << j+1  <<std::endl;
    //swap pivot back to j
    centroidItem temp2;
    temp2.theCentroid = centroidList[j+1].theCentroid;
    temp2.tri = centroidList[j+1].tri;
    centroidList[j+1] = centroidList[centroidListSize-1];
    centroidList[centroidListSize-1] = temp2;
    pivotNum=j+1;*/
    
    //pivotnum is where the pivot is currently located in the centroid list
   // std::cout<<"pivotNum is: " <<pivotNum<<std::endl;
    //print centroid list
    for(int i = 0; i<(centroidListSize); i++){
      std::cout<<"centroid list AFTER: " << centroidList[i].theCentroid << std::endl;
      //std::cout<<"centroid tri: " << centroidList[i].tri->vertex(0) << std::endl;
    }
    
    //std::cout<<"pivotNum after is "<< pivotNum <<std::endl;
    //find midpoint by adjusting pivotnum for the start and end indicies
    std::cout<<"CHECKING I and J when finding MIDPOINT i is: " << i << " j is: " << j<<std::endl;
    int midpoint = start_index+j;
    std::cout<<"midpoint is: " <<midpoint<<std::endl;
    
        
    //debug: print trianglelist
    std::cout<<"before changin triangles" <<std::endl;
     for(int i = start_index; i < end_index+1; i++){
      std::cout<< triangleList[i] <<std::endl;
    }
    
    //change triangle pointers in triangle list to reflect the triangle pointers in centroidList
    int centListIdx = 0;
    for(int i = start_index; i < end_index+1; i++){
      triangleList[i] = centroidList[centListIdx].tri;
      centListIdx++;
    }
    
    //debug: print trianglelist
    std::cout<<"after changin triangles" <<std::endl;
     for(int i = start_index; i < end_index+1; i++){
      std::cout<< triangleList[i] <<std::endl;
    }
    
    //recurse for left and right nodes
    
    //check if we are out of bounds
    //if (start_index <= midpoint){
      std::cout<<"GOING LEFT"<<std::endl;
      _left = new boundingVolumeElement(triangleList, start_index, midpoint-1);
    //}
    //check if we are out of bounds
    //if (end_index >= midpoint+1){
      std::cout<<"GOING RIGHT"<<std::endl;
      _right = new boundingVolumeElement(triangleList, midpoint, end_index);
    //}
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
  
  