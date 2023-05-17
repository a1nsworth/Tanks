//
// Created by Daniel on 17.05.2023.
//

#include "MainMenu.h"
MainMenu::MainMenu() {
  SetUpFont();
  SetUpButtons();
}
void MainMenu::SetUpFont() {
  font_ = new sf::Font();
  font_->loadFromFile(PATH_FONT);
}
void MainMenu::SetUpButtons() {
  title_ = new sf::Text("Battle Tanks", *font_, 150);
  title_->setPosition(WIDTH_MAIN_WINDOW / 2., HEIGHT_MAIN_WINDOW / 2.);
  title_->setFillColor(sf::Color::Green);

  run_game_ = new ButtonWithPressedText();
  run_game_->text->setFont(*font_);
  run_game_->text->setString(std::string("Run Game"));
  run_game_->idle_color = sf::Color::White;
  run_game_->hover_color = sf::Color::Yellow;
  run_game_->active_color = sf::Color::Yellow;
  run_game_->text->setCharacterSize(60);
  run_game_->text
	  ->setPosition(sf::Vector2f(title_->getGlobalBounds().width / 2., title_->getGlobalBounds().height + 200));
  run_game_->text->setFillColor(sf::Color::White);
}
