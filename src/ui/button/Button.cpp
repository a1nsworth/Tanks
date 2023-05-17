//
// Created by Daniel on 11.05.2023.
//

#include "Button.h"

void Button::Render(sf::RenderWindow *render_window)
{
  render_window->draw(*rectangle_shape);
  render_window->draw(*text);
}
Button::State Button::GetState() const
{
  return state_;
}
void Button::Update(const sf::Vector2i &mouse_position)
{
  if (rectangle_shape->getGlobalBounds().contains(sf::Vector2f(mouse_position.x, mouse_position.y)))
  {
	SetState(Button::State::HOVER);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
	  SetState(Button::State::ACTIVE);

	  on_active();
	} else
	  on_hover();
  } else
  {
	SetState(Button::State::IDLE);

	on_idle();
  }

  switch (state_)
  {
	case IDLE: rectangle_shape->setFillColor(idle_color);
	  break;
	case HOVER: rectangle_shape->setFillColor(hover_color);
	  break;
	case ACTIVE: rectangle_shape->setFillColor(active_color);
	  break;
  }
}
void Button::SetState(Button::State state)
{
  state_ = state;
}
Button::Button()
{
  SetUpColors();
  SetUpRectangleShape();
  SetUpSubjects();
  SetUpText();
}
void Button::SetUpRectangleShape()
{
  rectangle_shape = new sf::RectangleShape();
}
void Button::SetUpText()
{
  text = new sf::Text();
}
void Button::SetUpColors()
{
  idle_color = sf::Color();
  hover_color = sf::Color();
  active_color = sf::Color();
}
void Button::SetUpSubjects()
{
}

