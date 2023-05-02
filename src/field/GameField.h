//
// Created by Daniel on 30.04.2023.
//

#ifndef TANKS_SRC_GAME_ENTITIES_GAMEFIELD_H_
#define TANKS_SRC_GAME_ENTITIES_GAMEFIELD_H_

#include <vector>

#include "../interfaces/IRendered.h"
#include "BackGround.h"
#include "Obstacle.h"

class GameField : public IRendered
{
 private:
  BackGround *back_ground_;
  std::vector<Obstacle> obstacles_;

 public:
  GameField();
  ~GameField() = default;

  void Render(sf::RenderWindow *render_window) override;
};

#endif //TANKS_SRC_GAME_ENTITIES_GAMEFIELD_H_
