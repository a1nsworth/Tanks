//
// Created by Daniel on 04.05.2023.
//

#include "Game.h"
void Game::Update(Application *application, float delta_time)
{
  if (!is_paused_)
  {
	UpdateTanks(delta_time);
  } else
  {
	pause_menu_->Update(sf::Mouse::getPosition(*application->GetWindow()->GetRenderWindow()));

	if (pause_menu_->GetMainMenu()->GetState() == Button::State::ACTIVE)
	{
	  OnClickedMainMenu(application);
	} else if (pause_menu_->GetNewGame()->GetState() == Button::State::ACTIVE)
	{
	  OnClickedNewGame(application);
	} else if (pause_menu_->GetResume()->GetState() == Button::State::ACTIVE)
	{
	  OnClickedResume();
	}
  }
  UpdateEvents(application, delta_time);
}
void Game::Render(Application *application)
{
  application->GetWindow()->GetRenderWindow()->clear();
  RenderGameField(application->GetWindow());
  RenderHealthBars(application->GetWindow());
  RenderTanks(application->GetWindow());
  RenderPauseMenu(application->GetWindow());
  application->GetWindow()->GetRenderWindow()->display();
}
void Game::UpdateEvents(Application *application, const float delta_time)
{
  sf::Event ev{};
  while (application->GetWindow()->GetRenderWindow()->pollEvent(ev))
  {
	if (ev.type == sf::Event::Closed)
	{
	  application->GetWindow()->GetRenderWindow()->close();
	}
	if (ev.type == sf::Event::KeyPressed)
	{
	  if (ev.key.code == sf::Keyboard::Escape)
	  {
		is_paused_ = !is_paused_;
	  }
	}
  }

#pragma region Обработка нажатий клавиш
  if (!is_paused_)
  {
	MoveController::Processing(tank_1_, delta_time);
	MoveController::Processing(tank_2_, delta_time);
  }
#pragma endregion
}
void Game::UpdateTanks(const float delta_time)
{
  tank_1_->Update(delta_time);

  // Коллизия с картой
  if (const auto kObstacle = game_field_->GetBackObstacles()->GetIndexCollide(tank_1_); kObstacle != nullptr)
  {
	tank_1_->ActionOnCollision(kObstacle);
  }
  if (const auto kBullet = tank_1_->GetBullet(); kBullet != nullptr && kBullet->IsLaunched())
  {
	// Коллизия пули со стеной
	// Коллизия пули с врагом
	if (tank_2_->IsAlive() && kBullet->IsCollide(tank_2_) || game_field_->GetBackObstacles()->IsCollide(kBullet))
	{
	  if (tank_2_->IsAlive() && kBullet->IsCollide(tank_2_))
		kBullet->ActionOnCollision(tank_2_);
	  tank_1_->DeleteBullet();
	}
  }

  tank_2_->Update(delta_time);

  // Коллизия с картой
  if (const auto kObstacle = game_field_->GetBackObstacles()->GetIndexCollide(tank_2_); kObstacle != nullptr)
  {
	tank_2_->ActionOnCollision(kObstacle);
  }
  if (const auto kBullet = tank_2_->GetBullet(); kBullet != nullptr && kBullet->IsLaunched())
  {
	// Коллизия пули со стеной
	// Коллизия пули с врагом
	if (tank_2_->IsAlive() && kBullet->IsCollide(tank_1_) || game_field_->GetBackObstacles()->IsCollide(kBullet))
	{
	  if (tank_1_->IsAlive() && kBullet->IsCollide(tank_1_))
		kBullet->ActionOnCollision(tank_1_);
	  tank_2_->DeleteBullet();
	}
  }
}
void Game::RenderTanks(Window *window)
{
  tank_1_->Render(window->GetRenderWindow());
  tank_2_->Render(window->GetRenderWindow());
}
void Game::RenderGameField(Window *window)
{
  if (game_field_ != nullptr)
	game_field_->Render(window->GetRenderWindow());
}
void Game::InitGameField()
{
  game_field_ = new GameField();
}
void Game::InitTanks()
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

  tank_1_->on_getting_damage.Add(health_bar_1_);
  tank_2_->on_getting_damage.Add(health_bar_2_);
}
Game::Game()
{
  InitHealthBars();
  InitGameField();
  InitPauseMenu();
  InitTanks();
}
bool Game::IsPaused() const
{
  return is_paused_;
}
void Game::SetIsPaused(bool is_paused)
{
  is_paused_ = is_paused;
}
void Game::InitHealthBars()
{
  health_bar_1_ = new HealthBar(sf::Color::Red,
								sf::Vector2f(WIDTH_MAIN_WINDOW - (WIDTH_HEALTH_BAR << 1),
											 HEIGHT_HEALTH_BAR));
  health_bar_2_ = new HealthBar(sf::Color::Yellow,
								sf::Vector2f(WIDTH_HEALTH_BAR >> 1, HEIGHT_HEALTH_BAR));
}
void Game::RenderHealthBars(Window *window)
{
  health_bar_1_->Render(window->GetRenderWindow());
  health_bar_2_->Render(window->GetRenderWindow());
}
void Game::InitPauseMenu()
{
  pause_menu_ = new PauseMenu(sf::Vector2f(game_field_->GetBackObstacles()->GetFloatRect().width / 2., game_field_->GetBackObstacles()->GetFloatRect().height / 2.));
}
void Game::RenderPauseMenu(Window *window)
{
  if (is_paused_)
	pause_menu_->Render(window->GetRenderWindow());
}
