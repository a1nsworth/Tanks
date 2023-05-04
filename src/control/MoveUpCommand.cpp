//
// Created by Daniel on 03.05.2023.
//

#include "MoveUpCommand.h"
MoveUpCommand::MoveUpCommand(const sf::Keyboard::Key key) : Command(key) {}
void MoveUpCommand::Execute(Tank *const tank, const float delta_time) {
  tank->MoveUp(delta_time);
}
