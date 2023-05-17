//
// Created by Daniel on 04.05.2023.
//

#include <iostream>
#include "SimpleBullet.h"
#include "../../entities/Tank.h"
SimpleBullet::SimpleBullet(const sf::Vector2f &start_launch,
						   const float angel_launch,
						   const sf::Vector2f &direct) : Bullet(1,
																1000000,
																direct)
{
  image_.loadFromFile(PATH_TILES);
  texture_.loadFromImage(image_);
  sprite_.setTexture(texture_);
  sprite_.setTextureRect(sf::IntRect(520, 725, 24, 29));
  sprite_.setOrigin(sprite_.getLocalBounds().width / 2., sprite_.getLocalBounds().height / 2.);
  sprite_.setPosition(start_launch);
  sprite_.setRotation(angel_launch);
}
void SimpleBullet::Move(const sf::Vector2f &direct, float delta_time)
{
  sprite_.move(direct * delta_time * flight_speed_);
}
void SimpleBullet::Spin(const float angle, const float delta_time)
{
  sprite_.rotate(angle * delta_time);
}
void SimpleBullet::Render(sf::RenderWindow *const render_window)
{
  if (is_launched_)
  	render_window->draw(sprite_);
}
void SimpleBullet::ActionOnCollision(const sf::FloatRect &collided_object) {}
void SimpleBullet::ActionOnCollision(SolidBody *collided_object)
{
  if (Tank *tank = dynamic_cast<Tank *>(collided_object))
  {
	tank->Hit(GetDamage());
  }
}
void SimpleBullet::Update(const float delta_time)
{
  if (is_launched_)
	Move(direct_, delta_time);
}
