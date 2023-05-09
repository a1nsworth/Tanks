//
// Created by Daniel on 29.04.2023.
//

#ifndef _GAME_H_
#define _GAME_H_

#include "../window/MainWindow.h"
#include "../interfaces/IApplicationState.h"
#include "../game_states/Game.h"
#include "ApplicationConstants.h"

class Application
{
 private:
  MainWindow *main_window_;

  sf::Clock delta_clock_;
  float delta_time_;

  IApplicationState *state_;

  Application();
  ~Application() = default;

  void UpdateDeltaTime();

  void InitMainWindow();
 public:
  MainWindow *GetWindow();

  Application(const Application &) = delete;
  Application &operator=(const Application &) = delete;

  static Application &Instance();

  void Run();
};

#endif //_GAME_H_
