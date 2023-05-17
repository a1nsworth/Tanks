//
// Created by Daniel on 04.05.2023.
//

#include "Menu.h"
#include "Game.h"
void Menu::Update(Application *application, float delta_time) {}
void Menu::Render(Application *application)
{
  application->GetWindow()->GetRenderWindow()->clear();
  main_menu_->Render(application->GetWindow()->GetRenderWindow());
  //button_run_->Render(application->GetWindow()->GetRenderWindow());
  application->GetWindow()->GetRenderWindow()->display();
}
Menu::Menu()
{
  main_menu_ = new MainMenu();
};
void Menu::UpdateEvents(Application *application, float delta_time)
{
  sf::Event ev{};
  while (application->GetWindow()->GetRenderWindow()->pollEvent(ev))
  {
	if (ev.type == sf::Event::Closed)
	{
	  application->GetWindow()->GetRenderWindow()->close();
	}
  }

//  button_run_->Update(sf::Mouse::getPosition(*application->GetWindow()->GetRenderWindow()));
//
//  if (button_run_->GetState() == Button::State::ACTIVE)
//  {
//	application->SetState(new Game());
//  }
}
