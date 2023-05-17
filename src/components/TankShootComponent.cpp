//
// Created by Daniel on 17.05.2023.
//

#include "TankShootComponent.h"
void TankShootComponent::Shot(const float delta)
{
  if (auto now = clock_.getElapsedTime().asSeconds(); time_last_shoot_ == 0 || now - time_last_shoot_ >= duration_)
  {
	time_last_shoot_ = now;

	const auto kDirect = sf::Vector2f(move_component_->GetDirect().x, -move_component_->GetDirect().y);
	bullet_ = std::make_unique<SimpleBullet>(move_component_->GetSprite()->getPosition(),
											 move_component_->GetSprite()->getRotation(),
											 kDirect, color_);
	bullet_->SetIsLaunched(true);
  }
}
void TankShootComponent::DeleteBullet()
{
  bullet_.reset();
}
TankShootComponent::TankShootComponent(TankMoveComponent *move_component,
									   const sf::Color &color,
									   float duration) :
	move_component_(move_component), color_(color), duration_(duration) {}
void TankShootComponent::Render(sf::RenderWindow *render_window)
{
  if (bullet_)
	bullet_->Render(render_window);
}
void TankShootComponent::Update(float delta_time)
{
  if (bullet_)
	bullet_->Update(delta_time);
}
const std::unique_ptr<Bullet> &TankShootComponent::GetBullet() const
{
  return bullet_;
}
float TankShootComponent::GetDuration() const
{
  return duration_;
}
float TankShootComponent::GetTimeLastShoot() const
{
  return time_last_shoot_;
}
const sf::Clock &TankShootComponent::GetClock() const
{
  return clock_;
}
