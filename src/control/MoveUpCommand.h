//
// Created by Daniel on 03.05.2023.
//

#ifndef TANKS_SRC_CONTROL_MOVEUPCOMMAND_H_
#define TANKS_SRC_CONTROL_MOVEUPCOMMAND_H_

#include "Command.h"

class MoveUpCommand : public Command
{
 public:
  explicit MoveUpCommand(sf::Keyboard::Key key);

  void Execute(Tank *tank, float delta_time) override;
};

#endif //TANKS_SRC_CONTROL_MOVEUPCOMMAND_H_
