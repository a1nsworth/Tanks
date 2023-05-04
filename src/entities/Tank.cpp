//
// Created by Daniel on 30.04.2023.
//

#include <iostream>
#include "Tank.h"
void Tank::Render(sf::RenderWindow *const render_window)
{
  render_window->draw(GetSprite());
}
void Tank::Update()
{
  UpdateDirect();
}
Tank::Tank(const sf::Color color,
		   const KeyAssignments key_assignments)
	: health_(100),
	  lives_(5),
	  color_(color),
	  direct_(0, 0),
	  key_assignments_(new KeyAssignments(key_assignments))
{
  image_.loadFromFile(PATH_TILES);
  texture_.loadFromImage(image_);
  sprite_.setTexture(texture_);

  SetTextureRectByColor();
  SetSettings();
}
void Tank::SetTextureRectByColor()
{
  if (color_ == sf::Color::Red)
	sprite_.setTextureRect(sf::IntRect(250, 705, WIDTH_TANK, HEIGHT_TANK));
  else if (color_ == sf::Color::Yellow)
	sprite_.setTextureRect(sf::IntRect(250, 600, WIDTH_TANK, HEIGHT_TANK));
}
void Tank::SetSettings()
{
  sprite_.setScale(1.1, 1.1);
  sprite_.setOrigin(WIDTH_TANK / 2., HEIGHT_TANK / 2.);
}
void Tank::UpdateDirect()
{
  const auto kAngel = (sprite_.getRotation()) * M_PI / 180;
  direct_ = sf::Vector2f(sin(kAngel), cos(kAngel));
}
void Tank::Move(const sf::Vector2f &direct, const float delta_time)
{
  sprite_.move(direct * delta_time * movement_speed_);
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
  sprite_.rotate(angle * delta_time);
}
void Tank::SpinClockwise(const float delta_time)
{
  Spin(-angle_, delta_time);
}
void Tank::SpinAntiClockwise(const float delta_time)
{
  Spin(angle_, delta_time);
}
KeyAssignments *Tank::GetKeyAssignments() const
{
  return key_assignments_;
}
