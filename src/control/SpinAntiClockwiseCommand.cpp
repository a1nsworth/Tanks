//
// Created by Daniel on 03.05.2023.
//

#include "SpinAntiClockwiseCommand.h"
SpinAntiClockwiseCommand::SpinAntiClockwiseCommand(const sf::Keyboard::Key key) : Command(key) {}
void SpinAntiClockwiseCommand::Execute(Tank *const tank, const float delta_time) {
  tank->SpinAntiClockwise(delta_time);
}
