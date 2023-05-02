//
// Created by Daniel on 30.04.2023.
//

#include "Ground.h"
sf::Sprite Ground::GetSprite() const
{
  return sprite_;
}
Ground::Ground()
{
  image_.loadFromFile(PATH_TILES);
  texture_.loadFromImage(image_);
  sprite_.setTexture(texture_);
  sprite_.setTextureRect(sf::IntRect(290, 105, 79, 79));
}
