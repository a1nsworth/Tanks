//
// Created by Daniel on 11.05.2023.
//

#ifndef TANKS_SRC_UI_BUTTON_BUTTON_H_
#define TANKS_SRC_UI_BUTTON_BUTTON_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "boost/signals2.hpp"
#include "../../subject/Subject.h"
#include "../../interfaces/IRendered.h"

class ButtonBuilder;

class Button : public IRendered
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

  boost::signals2::signal<void()> on_active;
  boost::signals2::signal<void()> on_hover;
  boost::signals2::signal<void()> on_idle;

  Button();
  ~Button() = default;

  void SetState(State state);
  [[nodiscard]] State GetState() const;

  void SetUpRectangleShape();
  void SetUpText();
  void SetUpColors();
  void SetUpSubjects();

  static ButtonBuilder *CreateBuilder();

  void Render(sf::RenderWindow *render_window) override;
  virtual void Update(const sf::Vector2i &mouse_position);

 protected:
  State state_ = IDLE;
};

#endif //TANKS_SRC_UI_BUTTON_BUTTON_H_
