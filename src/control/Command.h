//
// Created by Daniel on 03.05.2023.
//

#ifndef TANKS_SRC_CONTROL_COMMAND_H_
#define TANKS_SRC_CONTROL_COMMAND_H_

#include "../entities/Tank.h"

class Command
{
 protected:
  sf::Keyboard::Key key_;

  explicit Command(sf::Keyboard::Key key);
  virtual ~Command() = default;
 public:
  virtual void Execute(Tank *tank, float delta_time) = 0;

  sf::Keyboard::Key GetKey() const;
};

#endif //TANKS_SRC_CONTROL_COMMAND_H_
