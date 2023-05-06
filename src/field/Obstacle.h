//
// Created by Daniel on 30.04.2023.
//

#ifndef TANKS_SRC_FIELD_OBSTACLE_H_
#define TANKS_SRC_FIELD_OBSTACLE_H_

#include "../entities/SolidBody.h"
#include "../application/ApplicationConstants.h"

class Obstacle : public SolidBody
{
 public:
  Obstacle();
  void ActionOnCollision(SolidBody *collided_object) override;
  void ActionOnCollision(const sf::FloatRect &collided_object) override;
};

#endif //TANKS_SRC_FIELD_OBSTACLE_H_
