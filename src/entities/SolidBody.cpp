//
// Created by Daniel on 30.04.2023.
//

#include "SolidBody.h"

bool SolidBody::IsCollide(const SolidBody *const collided_object)
{
  return IsCollide(collided_object->GetSprite().getGlobalBounds());
}
bool SolidBody::IsCollide(const sf::FloatRect &collided_object)
{
  return GetSprite().getGlobalBounds().intersects(collided_object);
}