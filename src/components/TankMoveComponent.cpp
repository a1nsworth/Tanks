//
// Created by Daniel on 16.05.2023.
//

#include "TankMoveComponent.h"
const sf::Vector2f &TankMoveComponent::GetDirect() const {
  return direct_;
}
float TankMoveComponent::GetMovementSpeed() const {
  return movement_speed_;
}
void TankMoveComponent::SetMovementSpeed(float movement_speed)
{
  movement_speed_ = movement_speed;
}
void TankMoveComponent::MoveUp(const float delta_time) {
  Move(sf::Vector2f(direct_.x, -direct_.y), delta_time);
}
void TankMoveComponent::MoveDown(const float delta_time) {
  Move(sf::Vector2f(-direct_.x, direct_.y), delta_time);
}
void TankMoveComponent::UpdateDirect() {
  const auto kAngel = (sprite_->getRotation()) * M_PI / 180;
  direct_ = sf::Vector2f(sin(kAngel), cos(kAngel));
}
void TankMoveComponent::Move(const sf::Vector2f &direct, float delta_time) {
  sprite_->move(direct * delta_time * movement_speed_);
}
sf::Sprite *TankMoveComponent::GetSprite() const
{
  return sprite_;
}
TankMoveComponent::TankMoveComponent(sf::Sprite *sprite, const float movement_speed)
	: movement_speed_(movement_speed), sprite_(sprite) {}
