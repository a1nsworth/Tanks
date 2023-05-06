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
void Application::Update(const float delta_time)
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

#pragma region Обработка нажатий клавиш
  if (tank_1_ != nullptr)
	MoveController::Processing(tank_1_, delta_time_);
  if (tank_2_ != nullptr)
	MoveController::Processing(tank_2_, delta_time_);
#pragma endregion
}
void Application::RenderTanks(sf::RenderWindow *render_window)
{
  if (tank_1_ != nullptr)
	tank_1_->Render(render_window);
  if (tank_2_ != nullptr)
	tank_2_->Render(render_window);
}
void Application::InitTanks()
{
  tank_1_ = new Tank(sf::Color::Red,
					 KeyAssignments(sf::Keyboard::Key::W,
									sf::Keyboard::Key::S,
									sf::Keyboard::Key::A,
									sf::Keyboard::Key::D,
									sf::Keyboard::Key::C));
  tank_2_ = new Tank(sf::Color::Yellow,
					 KeyAssignments(sf::Keyboard::Key::Up,
									sf::Keyboard::Key::Down,
									sf::Keyboard::Key::Left,
									sf::Keyboard::Key::Right,
									sf::Keyboard::Key::M));

  tank_1_->GetLinkSprite().setPosition(WIDTH_MAIN_WINDOW / 2., HEIGHT_MAIN_WINDOW / 2.);
  tank_2_->GetLinkSprite().setPosition(WIDTH_MAIN_WINDOW / 4., HEIGHT_MAIN_WINDOW / 4.);
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
	Update(delta_time_);
	Render(main_window_->GetRenderWindow());
  }
}
void Application::UpdateTanks()
{
  if (tank_1_ != nullptr && tank_1_->IsAlive())
  {
	std::cout << tank_1_->GetSprite().getGlobalBounds().left << "|" << tank_1_->GetSprite().getGlobalBounds().top
			  << '\n';
	tank_1_->Update(delta_time_);

	// Коллизия с краями карты
	tank_1_->ActionOnCollision(game_field_->GetBackObstacles()->GetFloatRect());
	if (tank_2_ != nullptr)
	{
	  if (const auto kObstacle = game_field_->GetBackObstacles()->GetIndexCollide(tank_2_); kObstacle != nullptr)
	  {
		tank_2_->ActionOnCollision(kObstacle);
	  }

	  if (const auto kBullet = tank_1_->GetBullet(); kBullet != nullptr && kBullet->IsLaunched())
	  {
		if (tank_2_ != nullptr && kBullet->IsCollide(tank_2_))
		{
		  kBullet->ActionOnCollision(tank_1_);
		  tank_1_->DeleteBullet();
		}
		if (game_field_->GetBackObstacles()->IsCollide(kBullet))
		{
		  tank_1_->DeleteBullet();
		}
	  }
	}
  } else if (tank_1_ != nullptr)
  {
	delete tank_1_;
	tank_1_ = nullptr;
  }
  if (tank_2_ != nullptr && tank_2_->IsAlive())
  {
	tank_2_->Update(delta_time_);

	// Коллизия с краями карты
	tank_2_->ActionOnCollision(game_field_->GetBackObstacles()->GetFloatRect());
	if (tank_2_ != nullptr)
	{
	  if (const auto kObstacle = game_field_->GetBackObstacles()->GetIndexCollide(tank_2_); kObstacle != nullptr)
	  {
		tank_2_->ActionOnCollision(kObstacle);
	  }

	  if (const auto kBullet = tank_2_->GetBullet(); kBullet != nullptr && kBullet->IsLaunched())
	  {
		if (tank_1_ != nullptr && kBullet->IsCollide(tank_1_))
		{
		  kBullet->ActionOnCollision(tank_2_);
		  tank_2_->DeleteBullet();
		}
		if (game_field_->GetBackObstacles()->IsCollide(kBullet))
		{
		  tank_2_->DeleteBullet();
		}
	  }
	}
  } else if (tank_2_ != nullptr)
  {
	delete tank_2_;
	tank_2_ = nullptr;
  }
}
