//
// Created by Daniel on 29.04.2023.
//

#include "Application.h"

Application::Application()
{
  InitGameField();
  InitMainWindow();
  InitTanks();
}
void Application::Render(sf::RenderWindow *const render_window)
{
  render_window->clear();
  game_field_->Render(render_window);
  RenderTanks(render_window);
  render_window->display();
}
void Application::Update()
{
  UpdateEvents();
  UpdateTanks();
}
void Application::UpdateDeltaTime()
{
  delta_time_ = delta_clock_.restart().asSeconds() / TICK;
}
void Application::UpdateEvents()
{
  sf::Event ev{};
  while (main_window_->GetRenderWindow()->pollEvent(ev))
  {
	if (ev.type == sf::Event::Closed)
	{
	  main_window_->GetRenderWindow()->close();
	}
  }

  MoveController::Processing(tank_1_, delta_time_);
  MoveController::Processing(tank_2_, delta_time_);
}
void Application::RenderTanks(sf::RenderWindow *render_window)
{
  tank_1_->Render(render_window);
  tank_2_->Render(render_window);
}
void Application::InitTanks()
{
  tank_1_ = new Tank(sf::Color::Red,
					 KeyAssignments(sf::Keyboard::Key::W,
									sf::Keyboard::Key::S,
									sf::Keyboard::Key::A,
									sf::Keyboard::Key::D));
  tank_2_ = new Tank(sf::Color::Yellow,
					 KeyAssignments(sf::Keyboard::Key::Up,
									sf::Keyboard::Key::Down,
									sf::Keyboard::Key::Left,
									sf::Keyboard::Key::Right));

  tank_1_->GetLinkSprite().setPosition(WIDTH_MAIN_WINDOW / 2, HEIGHT_MAIN_WINDOW / 2);
  tank_2_->GetLinkSprite().setPosition(WIDTH_MAIN_WINDOW / 4, HEIGHT_MAIN_WINDOW / 4);
}
void Application::InitGameField()
{
  game_field_ = new GameField();
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
	Update();
	Render(main_window_->GetRenderWindow());
  }
}
void Application::UpdateTanks()
{
  tank_1_->Update();
  tank_2_->Update();
  for (const auto &kRow : game_field_->GetBackObstacles()->GetObstacles())
  {
	for (const auto &kObstacle : kRow)
	{
	  if (kObstacle != nullptr)
	  {
		if (tank_1_->IsCollide(kObstacle)) { tank_1_->ActionOnCollision(kObstacle); }
		if (tank_2_->IsCollide(kObstacle)) { tank_2_->ActionOnCollision(kObstacle); }
	  }
	}
  }

  std::cout << "left: " << tank_1_->GetSprite().getGlobalBounds().left << " | "
			<< "top: " << tank_1_->GetSprite().getGlobalBounds().top << " | " <<
			"width: " << tank_1_->GetSprite().getGlobalBounds().width << " | " <<
			"height: " << tank_1_->GetSprite().getGlobalBounds().height << " | " << '\n';

}
