//
// Created by Daniel on 30.04.2023.
//

#ifndef TANKS_SRC_FIELD_OBSTACLE_H_
#define TANKS_SRC_FIELD_OBSTACLE_H_

#include "../entities/SolidBody.h"
#include "../game/GameConstants.h"

class Obstacle : public SolidBody
{
 public:
  Obstacle()
  {
	image_.loadFromFile(PATH_TILES);
	texture_.loadFromImage(image_);
	sprite_.setTexture(texture_);
  }
};

#endif //TANKS_SRC_FIELD_OBSTACLE_H_
