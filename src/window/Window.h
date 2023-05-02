//
// Created by Daniel on 30.04.2023.
//

#ifndef TANKS_SRC_WINDOW_WINDOW_H_
#define TANKS_SRC_WINDOW_WINDOW_H_

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "../interfaces/IRendered.h"
#include "../interfaces/IUpdatable.h"

class Window
{
 protected:
  sf::RenderWindow *render_window_;

 public:
  explicit Window(const sf::VideoMode &video_mode, const sf::String &title);
  ~Window() = default;

  [[nodiscard]] sf::RenderWindow *GetRenderWindow() const;
};

#endif //TANKS_SRC_WINDOW_WINDOW_H_
