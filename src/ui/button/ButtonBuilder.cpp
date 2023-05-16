//
// Created by Daniel on 11.05.2023.
//

#include "ButtonBuilder.h"
Button *ButtonBuilder::Build()
{
  return button_;
}
ButtonBuilder::ButtonBuilder()
{
  button_ = new Button();
}
ButtonBuilder *ButtonBuilder::SetRectangleSize(const sf::Vector2f &size)
{
  button_->rectangle_shape->setSize(size);
  return this;
}
ButtonBuilder *ButtonBuilder::SetRectanglePosition(const sf::Vector2f &position)
{
  button_->rectangle_shape->setPosition(position);
  return this;
}
ButtonBuilder *ButtonBuilder::SetTextPosition(const sf::Vector2f &position)
{
  button_->text->setPosition(position);
  return this;
}
ButtonBuilder *ButtonBuilder::SetFont(const sf::Font &font)
{
  button_->text->setFont(font);
  return this;
}
ButtonBuilder *ButtonBuilder::SetString(const std::string &string)
{
  button_->text->setString(string);
  return this;
}
ButtonBuilder *ButtonBuilder::SetIdleColor(const sf::Color &idle_color)
{
  button_->idle_color = idle_color;
  button_->rectangle_shape->setFillColor(idle_color);
  return this;
}
ButtonBuilder *ButtonBuilder::SetHoverColor(const sf::Color &hover_color)
{
  button_->hover_color = hover_color;
  return this;
}
ButtonBuilder *ButtonBuilder::SetActiveColor(const sf::Color &active_color)
{
  button_->active_color = active_color;
  return this;
}
ButtonBuilder *ButtonBuilder::SetTextScale(const sf::Vector2f &scale)
{
  button_->text->setScale(scale);
  return this;
}
ButtonBuilder *ButtonBuilder::SetCharacterSize(const unsigned int size)
{
  button_->text->setCharacterSize(size);
  return this;
}
ButtonBuilder *ButtonBuilder::SetTextFillColor(const sf::Color &color)
{
  button_->text->setFillColor(color);
  return this;
}
