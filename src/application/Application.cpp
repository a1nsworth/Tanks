//
// Created by Daniel on 29.04.2023.
//

#include "Application.h"

Application::Application()
{
  SetUpMainWindow();
  state_ = new Menu();
}
void Application::UpdateDeltaTime()
{
  delta_time_ = delta_clock_.restart().asSeconds() / TICK;
}
void Application::SetUpMainWindow()
{
  main_window_ = new MainWindow(FPS, true);
}
Application &Application::Instance()
{
  static auto *game = new Application();
  return *game;
}
void Application::Run()
{
  while (main_window_->GetRenderWindow()->isOpen())
  {
	UpdateDeltaTime();
	state_->UpdateEvents(this, delta_time_);
	state_->Update(this, delta_time_);
	state_->Render(this);
  }
}
MainWindow *Application::GetWindow()
{
  return main_window_;
}
IApplicationState *Application::GetState() const
{
  return state_;
}
void Application::SetState(IApplicationState *state)
{
  state_ = state;
}
