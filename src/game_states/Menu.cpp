//
// Created by Daniel on 04.05.2023.
//

#include "Menu.h"
#include "Game.h"
void Menu::Update(Application *application, float delta_time) {}
void Menu::Render(Application *application)
{
  application->GetWindow()->GetRenderWindow()->clear();
  application->GetWindow()->GetRenderWindow()->draw(background_->GetLinkSprite());
  button_run_->Render(application->GetWindow()->GetRenderWindow());
  application->GetWindow()->GetRenderWindow()->display();
}
Menu::Menu()
{
  font_ = new sf::Font();
  font_->loadFromFile(PATH_FONT);

  SetUpBackground();
  SetUpButtonRun();
}
void Menu::SetUpBackground()
{
  background_ = new Object();

  background_->GetLinkImage().loadFromFile(PATH_BACKGROUND);
  background_->GetLinkTexture().loadFromImage(background_->GetLinkImage());
  background_->GetLinkSprite().setTexture(background_->GetLinkTexture());
  background_->GetLinkSprite().setScale(5.5, 5.5);
}
void Menu::SetUpButtonRun()
{

  sf::Text text = sf::Text("Start Game", *font_);
  text.setCharacterSize(19);
  sf::RectangleShape rectangle_shape = sf::RectangleShape();
  rectangle_shape.setSize(sf::Vector2f(130, 50));
  rectangle_shape.setPosition(WIDTH_MAIN_WINDOW / 2., HEIGHT_MAIN_WINDOW / 2.);

  button_run_ = Button::CreateBuilder()
	  ->SetString(std::string("Start Game"))
	  ->SetRectangleSize(rectangle_shape.getSize())
	  ->SetRectanglePosition(rectangle_shape.getPosition())
	  ->SetActiveColor(sf::Color::Red)
	  ->SetHoverColor(sf::Color::Yellow)
	  ->SetIdleColor(sf::Color::Cyan)
	  ->SetCharacterSize(text.getCharacterSize())
	  ->SetTextPosition(sf::Vector2f(rectangle_shape.getPosition().x + rectangle_shape.getGlobalBounds().width / 2.
										 - text.getGlobalBounds().width / 2.,
									 rectangle_shape.getPosition().y + rectangle_shape.getGlobalBounds().height / 2.
										 - text.getGlobalBounds().height / 2.))
	  ->SetTextFillColor(sf::Color::Black)
	  ->SetFont(*font_)
	  ->Build();
}
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

  button_run_->Update(sf::Mouse::getPosition(*application->GetWindow()->GetRenderWindow()));

  if (button_run_->GetState() == Button::State::ACTIVE)
  {
	application->SetState(new Game());
  }
}
