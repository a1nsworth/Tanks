//
// Created by Daniel on 30.04.2023.
//

#include "Tank.h"
void Tank::Render(sf::RenderWindow *const render_window)
{
  if (is_alive_)
  {
	render_window->draw(GetSprite());
	shoot_component_->Render(render_window);
  }
  animation_death_->Render(render_window);
}
void Tank::Update(const float delta_time)
{
  if (is_alive_)
  {
	move_component_->UpdateDirect();
	shoot_component_->Update(delta_time);
  }
  animation_death_->Update(delta_time);
}
Tank::Tank(const sf::Color color,
		   const KeyAssignments key_assignments)
	: color_(color),
	  key_assignments_(new KeyAssignments(key_assignments)),
	  animation_death_(new AnimationDeath(color_)),
	  on_getting_damage(Subject())
{
  image_.loadFromFile(PATH_TILES);
  texture_.loadFromImage(image_);
  sprite_.setTexture(texture_);

  SetUpSettings();
  SetUpComponents(color_);
}
void Tank::SetUpSettings()
{
  sprite_.setScale(1, 1);
  sprite_.setOrigin(WIDTH_TANK / 2., HEIGHT_TANK / 2.);
}
void Tank::MoveUp(const float delta_time)
{
  move_component_->MoveUp(delta_time);
}
void Tank::MoveDown(const float delta_time)
{
  move_component_->MoveDown(delta_time);
}
void Tank::SpinClockwise(const float delta_time)
{
  spin_component_->SpinClockwise(delta_time);
}
void Tank::SpinAntiClockwise(const float delta_time)
{
  spin_component_->SpinAntiClockwise(delta_time);
}
KeyAssignments *Tank::GetKeyAssignments() const
{
  return key_assignments_;
}
void Tank::ActionOnCollision(SolidBody *collided_object)
{
  ActionOnCollision(collided_object->GetSprite().getGlobalBounds());
}
void Tank::ActionOnCollision(const sf::FloatRect &collided_object)
{
  const auto kTankGlobalBounds = sprite_.getGlobalBounds();
  const auto kTankOrigin = sprite_.getOrigin();
#pragma region Коллизия справа
  if (kTankGlobalBounds.left < collided_object.left
	  && kTankGlobalBounds.left + kTankGlobalBounds.width < collided_object.left + collided_object.width
	  && kTankGlobalBounds.top < collided_object.top + collided_object.height
	  && kTankGlobalBounds.top + kTankGlobalBounds.height > collided_object.top)
  {
	sprite_.setPosition(collided_object.left - kTankGlobalBounds.width,
						kTankGlobalBounds.top + kTankOrigin.y);
  }
#pragma endregion
#pragma region Коллизия слева
  else if (kTankGlobalBounds.left > collided_object.left
	  && kTankGlobalBounds.left + kTankGlobalBounds.width > collided_object.left + collided_object.width
	  && kTankGlobalBounds.top < collided_object.top + collided_object.height
	  && kTankGlobalBounds.top + kTankGlobalBounds.height > collided_object.top)
  {
	sprite_.setPosition(collided_object.left + collided_object.width,
						kTankGlobalBounds.top + kTankOrigin.y);
  }
#pragma endregion
#pragma region Коолизия снизу
  if (kTankGlobalBounds.top < collided_object.top
	  && kTankGlobalBounds.top + kTankGlobalBounds.height
		  < collided_object.top + collided_object.height
	  && kTankGlobalBounds.left < collided_object.left + collided_object.width
	  && kTankGlobalBounds.left + kTankGlobalBounds.width > collided_object.left)
  {
	sprite_.setPosition(kTankGlobalBounds.left + kTankOrigin.x,
						collided_object.top - collided_object.height + kTankOrigin.y);
  }
#pragma endregion
#pragma region Коллизия сверху
  else if (kTankGlobalBounds.top > collided_object.top
	  && kTankGlobalBounds.top + kTankGlobalBounds.height
		  > collided_object.top + collided_object.height
	  && kTankGlobalBounds.left < collided_object.left + collided_object.width
	  && kTankGlobalBounds.left + kTankGlobalBounds.width > collided_object.left)
  {
	sprite_.setPosition(kTankGlobalBounds.left + kTankOrigin.x,
						collided_object.top + kTankGlobalBounds.height + kTankOrigin.y);
  }
#pragma endregion
}
void Tank::Shot(const float delta_time)
{
  shoot_component_->Shot(delta_time);
}
Bullet *Tank::GetBullet() const
{
  return shoot_component_->GetBullet().get();
}
void Tank::Hit(unsigned int damage)
{
  if (health_ == 1)
  {
	is_alive_ = false;
	animation_death_->Run(sf::Vector2f(sprite_.getGlobalBounds().left, sprite_.getGlobalBounds().top));
  } else
	health_ -= damage;
  on_getting_damage.Notify();
}
void Tank::DeleteBullet()
{
  shoot_component_->DeleteBullet();
}
bool Tank::IsAlive() const
{
  return is_alive_;
}
void Tank::SetUpComponents(const sf::Color &color)
{
  move_component_ = new TankMoveComponent(&sprite_, 100000);
  spin_component_ = new TankSpinComponent(&sprite_, 200000);
  color_component_.SetColor(&sprite_, color);
  shoot_component_ = new TankShootComponent(move_component_, color);
}
