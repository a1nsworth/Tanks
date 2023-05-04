//
// Created by Daniel on 03.05.2023.
//

#include "SpinClockwiseCommand.h"
SpinClockwiseCommand::SpinClockwiseCommand(const sf::Keyboard::Key key) : Command(key) {}
void SpinClockwiseCommand::Execute(Tank *const tank, const float delta_time) {
  tank->SpinClockwise(delta_time);
}
