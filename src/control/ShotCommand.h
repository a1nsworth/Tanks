//
// Created by Daniel on 04.05.2023.
//

#ifndef TANKS_SRC_CONTROL_SHOTCOMMAND_H_
#define TANKS_SRC_CONTROL_SHOTCOMMAND_H_

#include "Command.h"

class ShotCommand : public Command
{
 public:
  explicit ShotCommand(sf::Keyboard::Key key);

  void Execute(Tank *tank, float delta_time) override;
};

#endif //TANKS_SRC_CONTROL_SHOTCOMMAND_H_
