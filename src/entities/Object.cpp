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
void Object::SetImage(const sf::Image &image)
{
  image_ = image;
}
void Object::SetTexture(const sf::Texture &texture)
{
  texture_ = texture;
}
void Object::SetSprite(const sf::Sprite &sprite)
{
  sprite_ = sprite;
}
sf::Texture &Object::GetLinkTexture()
{
  return texture_;
}
sf::Image &Object::GetLinkImage()
{
  return image_;
}
Object::Object(const sf::Image &image, const sf::Texture &texture, const sf::Sprite &sprite)
	: image_(image), texture_(texture), sprite_(sprite) {}
Object::Object() = default;
