//
// Created by Daniel on 04.05.2023.
//

#ifndef TANKS_SRC_INTERFACES_IMOVABLE_H_
#define TANKS_SRC_INTERFACES_IMOVABLE_H_

#include "SFML/Graphics.hpp"

class IMovable
{
  virtual void Move(const sf::Vector2f &direct, float delta_time) = 0;
};

#endif //TANKS_SRC_INTERFACES_IMOVABLE_H_
