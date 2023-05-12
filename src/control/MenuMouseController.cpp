//
// Created by Daniel on 12.05.2023.
//

#include "MenuMouseController.h"
void MenuMouseController::Processing(const sf::Vector2f &mouse_position, Button *const button) {
  button->SetState(Button::State::IDLE);

  if (button->rectangle_shape->getGlobalBounds().contains(mouse_position))
  {
	button->SetState(Button::State::HOVER);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
	  button->SetState(Button::State::ACTIVE);
	}
  }
}
