//
// Created by Daniel on 17.05.2023.
//

#ifndef TANKS_SRC_COMPONENTS_SIMPLEBULLETCOLORCOMPONENT_H_
#define TANKS_SRC_COMPONENTS_SIMPLEBULLETCOLORCOMPONENT_H_

#include "SFML/Graphics.hpp"
#include "../application/ApplicationConstants.h"

class SimpleBulletColorComponent
{
 public:
  void SetColor(sf::Sprite *sprite, const sf::Color &color);
};

#endif //TANKS_SRC_COMPONENTS_SIMPLEBULLETCOLORCOMPONENT_H_
