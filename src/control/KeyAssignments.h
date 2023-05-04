//
// Created by Daniel on 03.05.2023.
//

#ifndef TANKS_SRC_CONTROL_KEYASSIGNMENTS_H_
#define TANKS_SRC_CONTROL_KEYASSIGNMENTS_H_

#include "SFML/Window.hpp"

class Command;

class KeyAssignments
{
 private:
  Command *move_up_;
  Command *move_down_;
  Command *spin_clockwise_;
  Command *spin_anti_clockwise_;

 public:
  KeyAssignments(sf::Keyboard::Key move_up,
				 sf::Keyboard::Key move_down,
				 sf::Keyboard::Key spin_clockwise,
				 sf::Keyboard::Key spin_anti_clockwise);
  ~KeyAssignments() = default;

  Command *GetMoveDown() const;
  void SetMoveDown(Command *move_down);

  Command *GetMoveUp() const;
  void SetMoveUp(Command *move_up);

  Command *GetSpinClockwise() const;
  void SetSpinClockwise(Command *spin_clockwise);

  Command *GetSpinAntiClockwise() const;
  void SetSpinAntiClockwise(Command *spin_anti_clockwise);

  Command *GetCommandByKey(sf::Keyboard::Key key);
};

#endif //TANKS_SRC_CONTROL_KEYASSIGNMENTS_H_
