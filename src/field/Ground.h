//
// Created by Daniel on 30.04.2023.
//

#ifndef TANKS_SRC_FIELD_GROUND_H_
#define TANKS_SRC_FIELD_GROUND_H_

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "../game/GameConstants.h"

class Ground
{
 private:
  sf::Image image_;
  sf::Texture texture_;
  sf::Sprite sprite_;

 public:
  Ground();
  ~Ground() = default;

  sf::Sprite GetSprite() const;
};

#endif //TANKS_SRC_FIELD_GROUND_H_
