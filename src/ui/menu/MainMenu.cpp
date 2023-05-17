//
// Created by Daniel on 17.05.2023.
//

#include "MainMenu.h"
MainMenu::MainMenu()
{
  SetUpBackGround();
  SetUpFont();
  SetUpButtons();
}
void MainMenu::SetUpFont()
{
  font_ = new sf::Font();
  font_->loadFromFile(PATH_FONT);
}
void MainMenu::SetUpButtons()
{
  title_ = new sf::Text("Battle   Tanks", *font_, 200);
  title_->setOrigin(title_->getGlobalBounds().width / 2.f, title_->getGlobalBounds().height / 2.f);
  title_->setPosition(WIDTH_MAIN_WINDOW / 2., 150);
  title_->setFillColor(sf::Color::Green);

  run_game_ = new ButtonWithPressedText();
  run_game_->text->setFont(*font_);
  run_game_->text->setString(std::string("Run Game"));
  run_game_->idle_color = sf::Color(72, 61, 139);
  run_game_->hover_color = sf::Color::Yellow;
  run_game_->active_color = sf::Color::Yellow;
  run_game_->text->setOrigin(run_game_->text->getGlobalBounds().width / 2.f, run_game_->text->getGlobalBounds().height / 2.f);
  run_game_->text->setCharacterSize(60);
  run_game_->text
	  ->setPosition(sf::Vector2f(WIDTH_MAIN_WINDOW / 2., HEIGHT_MAIN_WINDOW / 2. + 100));
  run_game_->text->setFillColor(sf::Color(123, 104, 238));
}
void MainMenu::SetUpBackGround()
{
  background_ = new Object();

  background_->GetLinkImage().loadFromFile(PATH_BACKGROUND);
  background_->GetLinkTexture().loadFromImage(background_->GetLinkImage());
  background_->GetLinkSprite().setTexture(background_->GetLinkTexture());
  background_->GetLinkSprite().setScale(5.5, 5.5);
}
void MainMenu::Render(sf::RenderWindow *render_window) {
  render_window->draw(background_->GetSprite());
  render_window->draw(*title_);
  run_game_->Render(render_window);
}
void MainMenu::Update(const sf::Vector2i &mouse_position) {
  run_game_->Update(mouse_position);
}
sf::Font *MainMenu::GetFont() const
{
  return font_;
}
sf::Text *MainMenu::GetTitle() const
{
  return title_;
}
Object *MainMenu::GetBackground() const
{
  return background_;
}
ButtonWithPressedText *MainMenu::GetRunGame() const
{
  return run_game_;
}
