//
// Created by Daniel on 29.04.2023.
//

#ifndef _IRENDERED_H_
#define _IRENDERED_H_

#include <SFML/Graphics/RenderWindow.hpp>

class IRendered
{
 public:
  virtual void Render(sf::RenderWindow *const render_window) = 0;
};

#endif //_IRENDERED_H_
