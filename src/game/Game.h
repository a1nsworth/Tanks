//
// Created by Daniel on 29.04.2023.
//

#ifndef _GAME_H_
#define _GAME_H_

#include "../interfaces/IRendered.h"
#include "../interfaces/IUpdatable.h"
#include "../window/MainWindow.h"
#include "../field/GameField.h"

#include "GameConstants.h"

class Game : public IRendered, public IUpdatable
{
 private:
  MainWindow *main_window_;
  GameField *game_field_;

  sf::Clock delta_clock_;
  float delta_time_;

  Game()
  {
	main_window_ = new MainWindow();
	game_field_ = new GameField();
  }

  ~Game() = default;

  Game(const Game &) = delete;
  Game &operator=(const Game &) = delete;

  void Render(sf::RenderWindow *render_window) override
  {
	render_window->clear();
	game_field_->Render(render_window);
	render_window->display();
  }

  void Update() override
  {
	UpdateEvents();
  }

  void UpdateDeltaTime()
  {
	delta_time_ = delta_clock_.restart().asSeconds() / TICK;
  }

  void UpdateEvents()
  {
	sf::Event ev{};
	while (main_window_->GetRenderWindow()->pollEvent(ev))
	{
	  if (ev.type == sf::Event::Closed)
	  {
		main_window_->GetRenderWindow()->close();
	  }
	}

  }
 public:
  static Game &Instance()
  {
	static Game *game = new Game();
	return *game;
  }

  void Run()
  {
	while (main_window_->GetRenderWindow()->isOpen())
	{
	  UpdateDeltaTime();
	  Update();
	  Render(main_window_->GetRenderWindow());
	}
  }
};

#endif //_GAME_H_
