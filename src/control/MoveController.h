//
// Created by Daniel on 03.05.2023.
//

#ifndef TANKS_SRC_CONTROL_MOVECONTROLLER_H_
#define TANKS_SRC_CONTROL_MOVECONTROLLER_H_

#include <iostream>
#include "Command.h"

class MoveController
{
 public:
  static void Processing(Tank *tank, float delta_time);
};

#endif //TANKS_SRC_CONTROL_MOVECONTROLLER_H_
