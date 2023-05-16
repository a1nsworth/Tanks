//
// Created by Daniel on 12.05.2023.
//

#include "PauseMenu.h"
PauseMenu::PauseMenu(const sf::Vector2f &position) : position_(position)
{
  SetUpFont();
  SetUpButtons();
}
void PauseMenu::SetUpFont()
{
  font_ = new sf::Font();
  font_->loadFromFile(PATH_FONT);
}
void PauseMenu::SetUpButtons()
{
  resume_ = new ButtonWithPressedText();
  resume_->text->setFont(*font_);
  resume_->text->setString(std::string("Resume"));
  resume_->idle_color = sf::Color::White;
  resume_->hover_color = sf::Color::Yellow;
  resume_->active_color = sf::Color::Yellow;
  resume_->text->setCharacterSize(40);
  resume_->text->setPosition(sf::Vector2f(position_.x + left_margin_, position_.y + up_margin_));
  resume_->text->setFillColor(sf::Color::White);

  new_game_ = new ButtonWithPressedText();
  new_game_->text->setFont(*font_);
  new_game_->text->setString(std::string("New Game"));
  new_game_->idle_color = sf::Color::White;
  new_game_->hover_color = sf::Color::Yellow;
  new_game_->active_color = sf::Color::Yellow;
  new_game_->text->setCharacterSize(40);
  new_game_->text->setPosition(sf::Vector2f(position_.x + left_margin_,
											resume_->text->getGlobalBounds().height
												+ resume_->text->getGlobalBounds().top
												+ distance_between_buttons_));
  new_game_->text->setFillColor(sf::Color::White);

  main_menu_ = new ButtonWithPressedText();
  main_menu_->text->setFont(*font_);
  main_menu_->text->setString(std::string("Main Menu"));
  main_menu_->idle_color = sf::Color::White;
  main_menu_->hover_color = sf::Color::Yellow;
  main_menu_->active_color = sf::Color::Yellow;
  main_menu_->text->setCharacterSize(40);
  main_menu_->text->setPosition(sf::Vector2f(position_.x + left_margin_,
											 resume_->text->getGlobalBounds().height + new_game_->text->getGlobalBounds().top
												 + distance_between_buttons_));
  main_menu_->text->setFillColor(sf::Color::White);
}
void PauseMenu::RenderAllButtons(sf::RenderWindow *render_window)
{
  main_menu_->Render(render_window);
  resume_->Render(render_window);
  new_game_->Render(render_window);
}
void PauseMenu::UpdateAllButtons(const sf::Vector2i &mouse_position)
{
  main_menu_->Update(mouse_position);
  resume_->Update(mouse_position);
  new_game_->Update(mouse_position);
}
void PauseMenu::Render(sf::RenderWindow *render_window)
{
  RenderAllButtons(render_window);
}
void PauseMenu::Update(const sf::Vector2i &mouse_position)
{
  UpdateAllButtons(mouse_position);
}
Button *PauseMenu::GetResume() const
{
  return resume_;
}
Button *PauseMenu::GetMainMenu() const
{
  return main_menu_;
}
Button *PauseMenu::GetNewGame() const
{
  return new_game_;
}
