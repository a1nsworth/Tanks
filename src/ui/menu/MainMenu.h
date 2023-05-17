//
// Created by Daniel on 17.05.2023.
//

#ifndef TANKS_SRC_UI_MENU_MAINMENU_H_
#define TANKS_SRC_UI_MENU_MAINMENU_H_

#include "../button/ButtonWithPressedText.h"
#include "../../application/ApplicationConstants.h"
#include "../../entities/Object.h"

class MainMenu : public IRendered
{
 private:
  sf::Font *font_;

  sf::Text *title_;
  Object *background_;
  ButtonWithPressedText *run_game_;

  void SetUpButtons();
  void SetUpBackGround();
  void SetUpFont();
 public:
  MainMenu();
  ~MainMenu() = default;

  [[nodiscard]] sf::Font *GetFont() const;
  [[nodiscard]] sf::Text *GetTitle() const;
  [[nodiscard]] Object *GetBackground() const;
  [[nodiscard]] ButtonWithPressedText *GetRunGame() const;

  void Render(sf::RenderWindow *render_window) override;
  void Update(const sf::Vector2i &mouse_position);
};

#endif //TANKS_SRC_UI_MENU_MAINMENU_H_
