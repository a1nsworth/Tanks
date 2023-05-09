//
// Created by Daniel on 03.05.2023.
//

#include "MoveController.h"
void MoveController::Processing(Tank *tank, float delta_time)
{
  if (tank->IsAlive())
  {
	if (sf::Keyboard::isKeyPressed(tank->GetKeyAssignments()->GetMoveUp()->GetKey()))
	  tank->GetKeyAssignments()->GetMoveUp()->Execute(tank, delta_time);
	if (sf::Keyboard::isKeyPressed(tank->GetKeyAssignments()->GetMoveDown()->GetKey()))
	  tank->GetKeyAssignments()->GetMoveDown()->Execute(tank, delta_time);
	if (sf::Keyboard::isKeyPressed(tank->GetKeyAssignments()->GetSpinAntiClockwise()->GetKey()))
	  tank->GetKeyAssignments()->GetSpinAntiClockwise()->Execute(tank, delta_time);
	if (sf::Keyboard::isKeyPressed(tank->GetKeyAssignments()->GetSpinClockwise()->GetKey()))
	  tank->GetKeyAssignments()->GetSpinClockwise()->Execute(tank, delta_time);
	if (sf::Keyboard::isKeyPressed(tank->GetKeyAssignments()->GetShot()->GetKey()))
	  tank->GetKeyAssignments()->GetShot()->Execute(tank, delta_time);
  }
}
