//
// Created by Daniel on 29.04.2023.
//

#include "Application.h"

Application::Application()
{
  InitMainWindow();
  state_ = new Game();
}
void Application::UpdateDeltaTime()
{
  delta_time_ = delta_clock_.restart().asSeconds() / TICK;
}
void Application::InitMainWindow()
{
  main_window_ = new MainWindow(FPS, true);
}
Application &Application::Instance()
{
  static Application *game = new Application();
  return *game;
}
void Application::Run()
{
  while (main_window_->GetRenderWindow()->isOpen())
  {
	UpdateDeltaTime();
	state_->Update(this, delta_time_);
	state_->Render(this);
  }
}
MainWindow *Application::GetWindow()
{
  return main_window_;
}
