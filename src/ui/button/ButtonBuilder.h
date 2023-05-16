//
// Created by Daniel on 11.05.2023.
//

#ifndef TANKS_SRC_BUTTON_BUTTONBUILDER_H_
#define TANKS_SRC_BUTTON_BUTTONBUILDER_H_

#include "Button.h"

class ButtonBuilder
{
 private:
  Button *button_;

 public:
  ButtonBuilder();
  ~ButtonBuilder() = default;

  ButtonBuilder *SetRectangleSize(const sf::Vector2f &size);
  ButtonBuilder *SetRectanglePosition(const sf::Vector2f &position);
  ButtonBuilder *SetTextPosition(const sf::Vector2f &position);
  ButtonBuilder *SetFont(const sf::Font &font);
  ButtonBuilder *SetString(const std::string &string);
  ButtonBuilder *SetTextScale(const sf::Vector2f &scale);
  ButtonBuilder *SetIdleColor(const sf::Color &idle_color);
  ButtonBuilder *SetHoverColor(const sf::Color &hover_color);
  ButtonBuilder *SetActiveColor(const sf::Color &active_color);
  ButtonBuilder *SetCharacterSize(unsigned int size);
  ButtonBuilder *SetTextFillColor(const sf::Color &color);

  Button *Build();
};

#endif //TANKS_SRC_BUTTON_BUTTONBUILDER_H_
