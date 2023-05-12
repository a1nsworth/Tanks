//
// Created by Daniel on 30.04.2023.
//

#include <iostream>
#include "Tank.h"
void Tank::Render(sf::RenderWindow *const render_window)
{
  if (is_alive_)
  {
	if (bullet_ != nullptr && bullet_->IsLaunched())
	  bullet_->Render(render_window);
	render_window->draw(GetSprite());
  }
  animation_death_->Render(render_window);
  RenderObservers(render_window);
}
void Tank::Update(const float delta_time)
{
  current_movement_speed_ = movement_speed_;
  current_split_speed_ = split_speed_;
  if (is_alive_)
  {
	UpdateDirect();
	if (bullet_ != nullptr)
	  bullet_->Update(delta_time);
  }
  animation_death_->Update(delta_time);
}
Tank::Tank(const sf::Color color,
		   const KeyAssignments key_assignments)
	: color_(color),
	  key_assignments_(new KeyAssignments(key_assignments)), animation_death_(new AnimationDeath(color_))
{
  image_.loadFromFile(PATH_TILES);
  texture_.loadFromImage(image_);
  sprite_.setTexture(texture_);

  SetUpTextureRectByColor();
  SetUpSettings();
}
// Отдельный компонент
void Tank::SetUpTextureRectByColor()
{
  if (color_ == sf::Color::Red)
	sprite_.setTextureRect(sf::IntRect(250, 705, WIDTH_TANK, HEIGHT_TANK));
  else if (color_ == sf::Color::Yellow)
	sprite_.setTextureRect(sf::IntRect(250, 600, WIDTH_TANK, HEIGHT_TANK));
}
void Tank::SetUpSettings()
{
  sprite_.setScale(1, 1);
  sprite_.setOrigin(WIDTH_TANK / 2., HEIGHT_TANK / 2.);
}
void Tank::UpdateDirect()
{
  const auto kAngel = (sprite_.getRotation()) * M_PI / 180;
  direct_ = sf::Vector2f(sin(kAngel), cos(kAngel));
}
void Tank::Move(const sf::Vector2f &direct, const float delta_time)
{
  sprite_.move(direct * delta_time * current_movement_speed_);
}
void Tank::MoveUp(const float delta_time)
{
  Move(sf::Vector2f(direct_.x, -direct_.y), delta_time);
}
void Tank::MoveDown(const float delta_time)
{
  Move(sf::Vector2f(-direct_.x, direct_.y), delta_time);
}
void Tank::Spin(const float angle, const float delta_time)
{
  sprite_.rotate(angle * delta_time * current_split_speed_);
}
void Tank::SpinClockwise(const float delta_time)
{
  Spin(-angel_, delta_time);
}
void Tank::SpinAntiClockwise(const float delta_time)
{
  Spin(angel_, delta_time);
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
  if (auto now = clock_.getElapsedTime().asSeconds(); time_last_shoot_ == 0 || now - time_last_shoot_ >= duration_)
  {
	time_last_shoot_ = now;

	bullet_ = new SimpleBullet(sprite_.getPosition(),
							   sprite_.getRotation(), sf::Vector2f(direct_.x, -direct_.y));
	bullet_->SetIsLaunched(true);
  }
}
Bullet *Tank::GetBullet() const
{
  return bullet_;
}
const sf::Vector2f &Tank::GetDirect() const
{
  return direct_;
}
void Tank::Hit(unsigned int damage)
{
  if (health_ == 1)
  {
	is_alive_ = false;
	animation_death_->Run(sf::Vector2f(sprite_.getGlobalBounds().left, sprite_.getGlobalBounds().top));
  } else
	health_ -= damage;

  NotifyObservers();
}
void Tank::DeleteBullet()
{
  delete bullet_;
  bullet_ = nullptr;
}
bool Tank::IsAlive() const
{
  return is_alive_;
}
const float Tank::GetDuration() const
{
  return duration_;
}
void Tank::RemoveObserver(IObserver *observer)
{
  on_getting_damage_observers_.erase(std::remove(on_getting_damage_observers_.begin(),
												 on_getting_damage_observers_.end(), observer),
									 on_getting_damage_observers_.end());
}
void Tank::AddObserver(IObserver *observer)
{
  on_getting_damage_observers_.push_back(observer);
}
void Tank::NotifyObservers()
{
  std::for_each(on_getting_damage_observers_.begin(),
				on_getting_damage_observers_.end(),
				[&](IObserver *observer) { observer->Update(); });
}
void Tank::RenderObservers(sf::RenderWindow *render_window)
{
  for (auto &observer : on_getting_damage_observers_)
  {
	observer->Render(render_window);
  }
}
