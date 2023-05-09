//
// Created by Daniel on 04.05.2023.
//

#ifndef TANKS_SRC_GAME_STATES_GAME_H_
#define TANKS_SRC_GAME_STATES_GAME_H_

#include "../field/GameField.h"
#include "../entities/Tank.h"
#include "../control/MoveController.h"
#include "../application/Application.h"

class Game : public IApplicationState
{
 private:
  GameField *game_field_;

  Tank *tank_1_;
  Tank *tank_2_;

 public:
  Game();

  ~Game() = default;

  void Update(Application *application, float delta_time) override;
  void Render(Application *application) override;

  void UpdateEvents(Window *window, float delta_time);

  void UpdateTanks(float delta_time);
  void RenderTanks(Window *window);
  void RenderGameField(Window *window);

  void InitTanks();
  void InitGameField();
};

#endif //TANKS_SRC_GAME_STATES_GAME_H_
