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
#include "../ui/menu/PauseMenu.h"
#include "boost/bind.hpp"

class Game : public IApplicationState
{
 private:

  GameField *game_field_;

  Tank *tank_1_;
  Tank *tank_2_;
  HealthBar *health_bar_1_;
  HealthBar *health_bar_2_;

  PauseMenu *pause_menu_;

  bool is_paused_ = false;

  void UpdateTanks(float delta_time);
  void RenderTanks(Window *window);
  void RenderHealthBars(Window *window);
  void RenderGameField(Window *window);
  void RenderPauseMenu(Window *window);

  void InitPauseMenu();
  void InitTanks();
  void InitGameField();
  void InitHealthBars();

  void OnClickedResume()
  {
	is_paused_ = false;
  }

  void OnClickedMainMenu(Application *application)
  {
	//application->SetState(new Menu());
  }

  void OnClickedNewGame(Application *application)
  {
	//application->SetState(new Game());
  }
 public:
  Game();
  ~Game() = default;

  bool IsPaused() const;
  void SetIsPaused(bool is_paused);

  void Update(Application *application, float delta_time) override;
  void Render(Application *application) override;
  void UpdateEvents(Application *application, float delta_time) override;
};

#endif //TANKS_SRC_GAME_STATES_GAME_H_
