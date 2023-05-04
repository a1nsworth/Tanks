//
// Created by Daniel on 30.04.2023.
//

#ifndef TANKS_SRC_GAME_ENTITIES_GAMEFIELD_H_
#define TANKS_SRC_GAME_ENTITIES_GAMEFIELD_H_

#include <vector>

#include "BackGround.h"
#include "BackObstacles.h"

class GameField : public IRendered
{
 private:
  BackGround *back_ground_;
  BackObstacles *back_obstacles_;

 public:
  GameField();
  ~GameField() = default;

  void Render(sf::RenderWindow *render_window) override;

  BackGround *GetBackGround() const;
  BackObstacles *GetBackObstacles() const;
};

#endif //TANKS_SRC_GAME_ENTITIES_GAMEFIELD_H_
