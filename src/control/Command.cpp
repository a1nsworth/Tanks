//
// Created by Daniel on 03.05.2023.
//

#include "Command.h"
Command::Command(const sf::Keyboard::Key key) : key_(key) {}
sf::Keyboard::Key Command::GetKey() const
{
  return key_;
}
