//
// Created by Daniel on 17.05.2023.
//

#ifndef TANKS_SRC_UI_MENU_MAINMENU_H_
#define TANKS_SRC_UI_MENU_MAINMENU_H_

#include "../button/ButtonWithPressedText.h"
#include "../../application/ApplicationConstants.h"

class MainMenu : public IRendered
{
 private:
  sf::Font *font_;

  sf::Text *title_;
  ButtonWithPressedText *run_game_;

  void SetUpButtons();
  void SetUpFont();
 public:
  MainMenu();
  ~MainMenu() = default;

  void Render(sf::RenderWindow *render_window) override
  {
	render_window->draw(*title_);
	run_game_->Render(render_window);
  }
};

#endif //TANKS_SRC_UI_MENU_MAINMENU_H_
