//
// Created by Daniel on 29.04.2023.
//

#ifndef _GAME_H_
#define _GAME_H_

#include "../interfaces/IRendered.h"
#include "../interfaces/IUpdatable.h"
#include "../window/MainWindow.h"
#include "../field/GameField.h"
#include "../entities/Tank.h"
#include "../control/MoveController.h"

#include "ApplicationConstants.h"

class Application : public IRendered, public IUpdatable
{
 private:
  MainWindow *main_window_;
  GameField *game_field_;
  Tank *tank_1_;
  Tank *tank_2_;

  sf::Clock delta_clock_;
  float delta_time_;

  Application();
  ~Application() = default;

  void Render(sf::RenderWindow *render_window) override;
  void Update(float delta_time) override;
  void UpdateDeltaTime();
  void UpdateEvents();
  void UpdateTanks();
  void RenderTanks(sf::RenderWindow *render_window);

  void InitTanks();
  void InitGameField();
  void InitMainWindow();
 public:
  Application(const Application &) = delete;
  Application &operator=(const Application &) = delete;

  static Application &Instance();

  void Run();
};

#endif //_GAME_H_
