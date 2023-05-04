//
// Created by Daniel on 03.05.2023.
//

#ifndef TANKS_SRC_CONTROL_MOVEDOWNCOMMAND_H_
#define TANKS_SRC_CONTROL_MOVEDOWNCOMMAND_H_

#include "Command.h"

class MoveDownCommand : public Command
{
 public:
  explicit MoveDownCommand(sf::Keyboard::Key key);

  void Execute(Tank *tank, float delta_time) override;
};

#endif //TANKS_SRC_CONTROL_MOVEDOWNCOMMAND_H_
