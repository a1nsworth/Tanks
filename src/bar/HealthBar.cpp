//
// Created by Daniel on 09.05.2023.
//

#include "HealthBar.h"
void HealthBar::FillBars(const sf::Color &color, const sf::Vector2f &position)
{
  auto image = new sf::Image();
  image->loadFromFile(PATH_TILES);
  auto texture = new sf::Texture();
  texture->loadFromImage(*image);

  int left = 780;
  int top = 0;
  if (color == sf::Color::Yellow)
	top = 590;
  else if (color == sf::Color::Red)
	top = 205;

  const int kShift = 35;
  for (int i = 0; i < bars_.size(); ++i)
  {
	auto sprite = new sf::Sprite(*texture);
	sprite->setTextureRect(sf::IntRect(left, top + kShift * i, WIDTH_HEALTH_BAR, HEIGHT_HEALTH_BAR));
	sprite->setPosition(position);
	sprite->scale(1.3,1.3);

	bars_.at(i) = new Object(*image, *texture, *sprite);
  }
}
HealthBar::HealthBar(const sf::Color &color, const sf::Vector2f &position)
{
  FillBars(color, position);
  index_current_sprite_ = 0;
}
void HealthBar::Update()
{
  index_current_sprite_++;
}
void HealthBar::Render(sf::RenderWindow *render_window)
{
  render_window->draw(bars_.at(index_current_sprite_)->GetSprite());
}
