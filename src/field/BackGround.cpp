//
// Created by Daniel on 30.04.2023.
//

#include "BackGround.h"
BackGround::BackGround() : grounds_(std::vector(HEIGHT_MAIN_WINDOW / WIDTH_GROUND,
												std::vector<Ground>(WIDTH_MAIN_WINDOW / WIDTH_GROUND, Ground())))
{
  image_.loadFromFile(PATH_TILES);
  texture_.loadFromImage(image_);
  sprite_.setTexture(texture_);
}
void BackGround::Render(sf::RenderWindow *render_window)
{
  for (auto i = 0; i < grounds_.size(); ++i)
	for (auto j = 0; j < grounds_[0].size(); ++j)
	{
	  sprite_.setTextureRect(sf::IntRect(290, 105, WIDTH_GROUND, WIDTH_GROUND));
	  sprite_.setPosition(j * WIDTH_GROUND, i * WIDTH_GROUND);

	  render_window->draw(sprite_);
	}
}
