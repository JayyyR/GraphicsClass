#include "texturedAlbedo.h"
#include <iostream>
#include <cstdlib>


/////////////////
// Constructor //
/////////////////
texturedAlbedo::texturedAlbedo(const std::string& textureName)
{
  _texture.load(textureName);
}


texturedAlbedo::texturedAlbedo(const texturedAlbedo& ta)
{
  _texture = ta._texture;
}



//////////////
// Operator //
//////////////
texturedAlbedo& texturedAlbedo::operator=(const texturedAlbedo& ta)
{
  _assign(ta);
  return *this;
}



/////////////
// Methods //
/////////////
color texturedAlbedo::evaluate(const vec2d& textureCoord) const
{
  // HW5: implement this
  //      returns: the color at 'textureCoord' in _texture.  Note, textureCoord is given in a resolution independent range.
  //               You will need to scale it such that [0,1]x[0,1] it maps to [0,width-1]x[0,height-1].  Coordinates outside this
  //               range should be mapped to the nearest coordinate inside [0,1]x[0,1] before converting to [0,width-1]x[0,height-1] 
  //      modifies: nothing.
  
  //normalize textureCoord
 //std::cout << "texturecoord: " << textureCoord << std::endl;
  
  //convert pixels
  float mappedWidth = textureCoord.x*(_texture.width());
  float mappedHeight = textureCoord.y*(_texture.height());
  
  vec2d mappedCoord = vec2d(mappedWidth,mappedHeight);
  
  //clamp values
  if (mappedCoord.x < 0)
    mappedCoord.x = 0;
  else if (mappedCoord.x > _texture.width()-1)
    mappedCoord.x = _texture.width()-1;
  
  if (mappedCoord.y < 0)
    mappedCoord.y = 0;
  else if (mappedCoord.y > _texture.height()-1)
    mappedCoord.y = _texture.width()-1;
  
  
  //std::cout << "newCoord: " << newCoord << std::endl;
  //std::cout << "newCoord.x: " << newCoord.x << std::endl;
 // std::cout << "newCoord.y: " << newCoord.y << std::endl;
 // std::cout << "texture width: " << _texture.width() << std::endl;
 // std::cout << "texture height: " << _texture.height() << std::endl;
  
  
  //std::cout << "mappedCoord: " << mappedCoord << std::endl;
  
  //grab color from nearest pixel to normalized texture coord in _texture
  color col = _texture(mappedCoord.x, mappedCoord.y);
  
  //return the color
  return col;
}



/////////////////////
// Private Methods //
/////////////////////
void texturedAlbedo::_swap(texturedAlbedo& ta)
{
  std::swap(_texture, ta._texture);
}


void texturedAlbedo::_assign(const texturedAlbedo& ta)
{
  _texture = ta._texture;
}


void texturedAlbedo::_print(std::ostream& s) const
{
  s << "Texture Albedo: (" << _texture.width() << "x" << _texture.height() << ")";
}
