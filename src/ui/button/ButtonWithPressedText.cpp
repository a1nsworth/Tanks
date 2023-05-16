//
// Created by Daniel on 12.05.2023.
//

#include "ButtonWithPressedText.h"
void ButtonWithPressedText::Render(sf::RenderWindow *render_window) {
  render_window->draw(*text);
}
void ButtonWithPressedText::Update(const sf::Vector2i &mouse_position) {
  if (text->getGlobalBounds().contains(sf::Vector2f(mouse_position.x, mouse_position.y)))
  {
	SetState(Button::State::HOVER);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
	  SetState(Button::State::ACTIVE);
	}
  } else
  {
	SetState(Button::State::IDLE);
  }

  switch (state_)
  {
	case IDLE: text->setFillColor(idle_color);
	  break;
	case HOVER: text->setFillColor(hover_color);
	  break;
	case ACTIVE: text->setFillColor(active_color);
	  break;
  }
}
