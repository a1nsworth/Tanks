//
// Created by Daniel on 29.04.2023.
//

#ifndef TANKS_SRC_INTERFACES_IRENDERED_H_
#define TANKS_SRC_INTERFACES_IRENDERED_H_

#include <SFML/Graphics/RenderWindow.hpp>

class IRendered
{
 public:
  virtual void Render(sf::RenderWindow *render_window) = 0;
};

#endif //TANKS_SRC_INTERFACES_IRENDERED_H_
