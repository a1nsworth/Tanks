//
// Created by Daniel on 30.04.2023.
//

#include "GameField.h"
GameField::GameField()
{
  back_ground_ = new BackGround();
  back_obstacles_ = new BackObstacles();
}
void GameField::Render(sf::RenderWindow *const render_window)
{
  back_ground_->Render(render_window);
  back_obstacles_->Render(render_window);
}
BackGround *GameField::GetBackGround() const
{
  return back_ground_;
}
BackObstacles *GameField::GetBackObstacles() const
{
  return back_obstacles_;
}
