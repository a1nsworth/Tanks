//
// Created by Daniel on 09.05.2023.
//

#include "AnimationDeath.h"
Object *AnimationDeath::CreateObject(const sf::Color &color)
{
  auto image = new sf::Image();
  image->loadFromFile(PATH_TILES);
  auto texture = new sf::Texture();
  texture->loadFromImage(*image);
  auto *sprite = new sf::Sprite();
  sprite->setTexture(*texture);

  if (color == sf::Color::Yellow)
	sprite->setTextureRect(sf::IntRect(375, 485, WIDTH_DIE_ANIMATION, HEIGHT_DIE_ANIMATION));
  else if (color == sf::Color::Red)
	sprite->setTextureRect(sf::IntRect(10, 485, WIDTH_DIE_ANIMATION, HEIGHT_DIE_ANIMATION));
  else
	throw std::invalid_argument("There is no such color");

  return new Object(*image, *texture, *sprite);
}
AnimationDeath::AnimationDeath(const sf::Color &color) : Animation(1)
{
  is_finished_ = false;
  is_started_ = false;
  animations_.push_back(CreateObject(color));
}
bool AnimationDeath::IsFinished() const
{
  return is_finished_;
}
bool AnimationDeath::IsStarted() const
{
  return is_started_;
}
void AnimationDeath::Run(const sf::Vector2f &appearance_position)
{
  is_started_ = true;
  animations_.at(0)->GetLinkSprite().setPosition(appearance_position);
}
void AnimationDeath::Render(sf::RenderWindow *render_window)
{
  if (is_started_ && !is_finished_)
	render_window->draw(animations_.at(0)->GetSprite());
}
void AnimationDeath::Update(float delta_time)
{
  static int n = 0;
  if (n == count_animations_)
	is_finished_ = true;
  if (is_started_ && !is_finished_)
  {
	MoveUp(delta_time);
	ReScaling();
	n++;
  }
}
void AnimationDeath::MoveUp(const float delta_time)
{
  Move(sf::Vector2f(1, -animations_.at(0)->GetLinkSprite().getPosition().y), delta_time);
}
void AnimationDeath::Move(const sf::Vector2f &direct, float delta_time)
{
  animations_.at(0)->GetLinkSprite().move(direct * delta_time * movement_speed_y_);
}
