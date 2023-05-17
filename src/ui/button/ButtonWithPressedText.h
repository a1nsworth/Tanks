//
// Created by Daniel on 12.05.2023.
//

#ifndef TANKS_SRC_UI_BUTTON_BUTTONWITHPRESSEDTEXT_H_
#define TANKS_SRC_UI_BUTTON_BUTTONWITHPRESSEDTEXT_H_

#include "Button.h"

class ButtonWithPressedText : public Button
{
 public:
  void Render(sf::RenderWindow *render_window) override;
  void Update(const sf::Vector2i &mouse_position) override;
};

#endif //TANKS_SRC_UI_BUTTON_BUTTONWITHPRESSEDTEXT_H_
