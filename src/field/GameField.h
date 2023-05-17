//
// Created by Daniel on 30.04.2023.
//

#ifndef TANKS_SRC_FIELD_GAMEFIELD_H_
#define TANKS_SRC_FIELD_GAMEFIELD_H_

#include <vector>

#include "BackGround.h"
#include "BackObstacles.h"
#include "GameObstacles.h"

class GameField : public IRendered
{
 private:
  BackGround *back_ground_;
  BackObstacles *back_obstacles_;

 public:
  GameField();
  ~GameField() = default;

  [[nodiscard]] BackGround *GetBackGround() const;
  [[nodiscard]] BackObstacles *GetBackObstacles() const;

  void Render(sf::RenderWindow *render_window) override;
};

#endif //TANKS_SRC_FIELD_GAMEFIELD_H_
