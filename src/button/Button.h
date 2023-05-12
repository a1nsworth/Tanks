//
// Created by Daniel on 11.05.2023.
//

#ifndef TANKS_SRC_BUTTON_BUTTON_H_
#define TANKS_SRC_BUTTON_BUTTON_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "../interfaces/IRendered.h"
#include "../interfaces/IUpdatable.h"

class ButtonBuilder;

class Button : public IRendered, public IUpdatable
{
 public:
  enum State
  {
	IDLE,
	HOVER,
	ACTIVE
  };

  sf::RectangleShape *rectangle_shape;
  sf::Text *text;

  sf::Color idle_color;
  sf::Color hover_color;
  sf::Color active_color;

  Button();
  ~Button() = default;

  void SetState(State state);
  State GetState() const;

  static ButtonBuilder *CreateBuilder();

  void Render(sf::RenderWindow *render_window) override;
  void Update(float delta_time) override;

 private:
  State state_ = IDLE;
};

#endif //TANKS_SRC_BUTTON_BUTTON_H_
