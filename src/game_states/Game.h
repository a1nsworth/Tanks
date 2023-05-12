//
// Created by Daniel on 04.05.2023.
//

#ifndef TANKS_SRC_GAME_STATES_GAME_H_
#define TANKS_SRC_GAME_STATES_GAME_H_

#include "../field/GameField.h"
#include "../entities/Tank.h"
#include "../control/MoveController.h"
#include "../application/Application.h"
#include "../bar/HealthBar.h"

class Game : public IApplicationState
{
 private:
  GameField *game_field_;

  Tank *tank_1_;
  Tank *tank_2_;

  bool is_paused_ = false;

 public:
  Game();
  ~Game() = default;

  bool IsPaused() const;
  void SetIsPaused(bool is_paused);

  void Update(Application *application, float delta_time) override;
  void Render(Application *application) override;
  void UpdateEvents(Application *application, float delta_time) override;

  void UpdateTanks(float delta_time);
  void RenderTanks(Window *window);
  void RenderGameField(Window *window);

  void InitTanks();
  void InitGameField();
};

#endif //TANKS_SRC_GAME_STATES_GAME_H_
