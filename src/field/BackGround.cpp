//
// Created by Daniel on 30.04.2023.
//

#include "BackGround.h"
BackGround::BackGround()
{
  ground_ = new Ground();
  sprite_ = new sf::Sprite(ground_->GetSprite());
}
void BackGround::Render(sf::RenderWindow *const render_window)
{
  for (auto i = 0; i < HEIGHT_MAIN_WINDOW / HEIGHT_GROUND; ++i)
	for (auto j = 0; j < WIDTH_MAIN_WINDOW / WIDTH_GROUND; ++j)
	{
	  sprite_->setPosition(j * WIDTH_GROUND, i * HEIGHT_GROUND);
	  render_window->draw(*sprite_);
	}
}
