//
// Created by Daniel on 17.05.2023.
//

#include "SimpleBulletColorComponent.h"
void SimpleBulletColorComponent::SetColor(sf::Sprite *sprite, const sf::Color &color) {
  if (color == sf::Color::Red)
	sprite->setTextureRect(sf::IntRect(520, 725, WIDTH_SIMPLE_BULLET, HEIGHT_SIMPLE_BULLET));
  else if (color == sf::Color::Yellow)
	sprite->setTextureRect(sf::IntRect(520, 625, WIDTH_SIMPLE_BULLET, HEIGHT_SIMPLE_BULLET));
}
