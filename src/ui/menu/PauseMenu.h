//
// Created by Daniel on 12.05.2023.
//

#ifndef TANKS_SRC_UI_MENU_PAUSEMENU_H_
#define TANKS_SRC_UI_MENU_PAUSEMENU_H_

#include "../button/ButtonBuilder.h"
#include "../button/ButtonWithPressedText.h"
#include "../../application/ApplicationConstants.h"
#include "../../event_system/Event.h"

class PauseMenu : public IRendered
{
 private:
  float distance_between_buttons_ = 10;
  float left_margin_ = 10;
  float up_margin_ = 10;

  ButtonWithPressedText *resume_;
  ButtonWithPressedText *main_menu_;
  ButtonWithPressedText *new_game_;
  sf::Font *font_;
  sf::Vector2f position_;

  void SetUpFont();
  void SetUpButtons();
 public:
  [[nodiscard]] Button *GetResume() const;
  [[nodiscard]] Button *GetMainMenu() const;
  [[nodiscard]] Button *GetNewGame() const;

  explicit PauseMenu(const sf::Vector2f &position);
  ~PauseMenu() = default;

  void RenderAllButtons(sf::RenderWindow *render_window);
  void UpdateAllButtons(const sf::Vector2i &mouse_position);
  void Render(sf::RenderWindow *render_window) override;
  void Update(const sf::Vector2i &mouse_position);

};

#endif //TANKS_SRC_UI_MENU_PAUSEMENU_H_
