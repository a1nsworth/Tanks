//
// Created by Daniel on 29.04.2023.
//

#ifndef TANKS_SRC_APPLICATION_APPLICATION_H_
#define TANKS_SRC_APPLICATION_APPLICATION_H_

#include "../window/MainWindow.h"
#include "../interfaces/IApplicationState.h"
#include "../game_states/Menu.h"
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

  void SetUpMainWindow();
 public:
  MainWindow *GetWindow();
  IApplicationState *GetState() const;
  void SetState(IApplicationState *state);

  Application(const Application &) = delete;
  Application &operator=(const Application &) = delete;

  static Application &Instance();

  void Run();
};

#endif //TANKS_SRC_APPLICATION_APPLICATION_H_
