//
// Created by Daniel on 02.05.2023.
//

#include "Object.h"
const sf::Image &Object::GetImage() const
{
  return image_;
}
const sf::Texture &Object::GetTexture() const
{
  return texture_;
}
const sf::Sprite &Object::GetSprite() const
{
  return sprite_;
}
sf::Sprite &Object::GetLinkSprite()
{
  return sprite_;
}
