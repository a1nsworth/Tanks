//
// Created by Daniel on 02.05.2023.
//

#ifndef TANKS_SRC_ENTITIES_OBJECT_H_
#define TANKS_SRC_ENTITIES_OBJECT_H_

#include "SFML/Graphics.hpp"

class Object
{
 protected:
  sf::Image image_;
  sf::Texture texture_;
  sf::Sprite sprite_;
};

#endif //TANKS_SRC_ENTITIES_OBJECT_H_
