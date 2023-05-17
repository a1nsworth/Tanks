//
// Created by Daniel on 17.05.2023.
//

#include "TankColorComponent.h"
void TankColorComponent::SetColor(sf::Sprite *const sprite, const sf::Color &color) {
  if (color == sf::Color::Red)
	sprite->setTextureRect(sf::IntRect(250, 705, WIDTH_TANK, HEIGHT_TANK));
  else if (color == sf::Color::Yellow)
	sprite->setTextureRect(sf::IntRect(250, 600, WIDTH_TANK, HEIGHT_TANK));
}
