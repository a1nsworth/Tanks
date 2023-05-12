//
// Created by Daniel on 11.05.2023.
//

#include "Button.h"
#include "ButtonBuilder.h"

ButtonBuilder *Button::CreateBuilder()
{
  return new ButtonBuilder();
}
void Button::Render(sf::RenderWindow *render_window)
{
  render_window->draw(*rectangle_shape);
  render_window->draw(*text);
}
Button::State Button::GetState() const
{
  return state_;
}
void Button::Update(float delta_time)
{
  switch (state_)
  {
	case IDLE: rectangle_shape->setFillColor(idle_color);
	  break;
	case HOVER:rectangle_shape->setFillColor(hover_color);
	  break;
	case ACTIVE:rectangle_shape->setFillColor(active_color);
	  break;
  }
}
void Button::SetState(Button::State state)
{
  state_ = state;
}
Button::Button() {
  rectangle_shape = new sf::RectangleShape();
  text = new sf::Text();
  idle_color = sf::Color();
  hover_color = sf::Color();
  active_color = sf::Color();
}

