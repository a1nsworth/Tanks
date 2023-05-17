//
// Created by Daniel on 16.05.2023.
//

#include "TankSpinComponent.h"
void TankSpinComponent::SpinClockwise(const float delta_time)
{
  Spin(-angel_, delta_time);
}
void TankSpinComponent::SpinAntiClockwise(const float delta_time)
{
  Spin(angel_, delta_time);
}

float TankSpinComponent::GetAngle() const
{
  return angel_;
}
TankSpinComponent::TankSpinComponent(sf::Sprite *const sprite, const float angel)
	: angel_(angel), sprite_(sprite) {}
void TankSpinComponent::Spin(const float angle, const float delta_time)
{
  sprite_->rotate(angle * delta_time);
}
void TankSpinComponent::SetAngel(float angel)
{
  angel_ = angel;
}
sf::Sprite *TankSpinComponent::GetSprite() const
{
  return sprite_;
}
