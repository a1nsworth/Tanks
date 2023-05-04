//
// Created by Daniel on 30.04.2023.
//

#include "Ground.h"
Ground::Ground()
{
  image_.loadFromFile(PATH_TILES);
  texture_.loadFromImage(image_);
  sprite_.setTexture(texture_);
  sprite_.setTextureRect(sf::IntRect(290, 105, WIDTH_GROUND, HEIGHT_GROUND));
}
