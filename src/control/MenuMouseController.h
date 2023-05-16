//
// Created by Daniel on 12.05.2023.
//

#ifndef TANKS_SRC_CONTROL_MENUMOUSECONTROLLER_H_
#define TANKS_SRC_CONTROL_MENUMOUSECONTROLLER_H_

#include "../ui/button/Button.h"

class MenuMouseController
{
 public:
  static void Processing(const sf::Vector2f &mouse_position, Button *button);
};

#endif //TANKS_SRC_CONTROL_MENUMOUSECONTROLLER_H_
