//
// Created by Daniel on 03.05.2023.
//

#include "MoveDownCommand.h"
MoveDownCommand::MoveDownCommand(const sf::Keyboard::Key key) : Command(key) {}
void MoveDownCommand::Execute(Tank *const tank, const float delta_time) {
  tank->MoveDown(delta_time);
}
