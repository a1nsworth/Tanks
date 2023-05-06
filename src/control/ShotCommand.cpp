//
// Created by Daniel on 04.05.2023.
//

#include "ShotCommand.h"
void ShotCommand::Execute(Tank *tank, float delta_time)
{
  tank->Shot(delta_time);
}
ShotCommand::ShotCommand(sf::Keyboard::Key key) : Command(key) {}
