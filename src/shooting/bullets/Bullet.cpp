//
// Created by Daniel on 04.05.2023.
//

#include "Bullet.h"
unsigned int Bullet::GetDamage() const
{
  return damage_;
}
Bullet::Bullet(unsigned int damage, float flight_speed, const sf::Vector2f &direct)
	: damage_(damage), flight_speed_(flight_speed), is_launched_(false), direct_(direct) {}
bool Bullet::IsLaunched() const
{
  return is_launched_;
}
void Bullet::SetIsLaunched(bool is_launched)
{
  is_launched_ = is_launched;
}
const sf::Vector2f &Bullet::GetDirect() const
{
  return direct_;
}
