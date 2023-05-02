//
// Created by Daniel on 30.04.2023.
//

#include "GameField.h"
GameField::GameField()
{
  back_ground_ = new BackGround();
}
void GameField::Render(sf::RenderWindow *render_window)
{
  back_ground_->Render(render_window);
}
