//
// Created by Daniel on 30.04.2023.
//

#include "Obstacle.h"
Obstacle::Obstacle() {
  image_.loadFromFile(PATH_TILES);
  texture_.loadFromImage(image_);
  sprite_.setTexture(texture_);
  sprite_.setTextureRect(sf::IntRect(105, 70, WIDTH_GROUND, HEIGHT_GROUND));
}
