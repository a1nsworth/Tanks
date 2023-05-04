//
// Created by Daniel on 03.05.2023.
//

#include "KeyAssignments.h"

#include "MoveDownCommand.h"
#include "MoveUpCommand.h"
#include "SpinClockwiseCommand.h"
#include "SpinAntiClockwiseCommand.h"

Command *KeyAssignments::GetMoveDown() const
{
  return move_down_;
}
void KeyAssignments::SetMoveDown(Command *move_down)
{
  move_down_ = move_down;
}
Command *KeyAssignments::GetMoveUp() const
{
  return move_up_;
}
void KeyAssignments::SetMoveUp(Command *move_up)
{
  move_up_ = move_up;
}
Command *KeyAssignments::GetSpinClockwise() const
{
  return spin_clockwise_;
}
void KeyAssignments::SetSpinClockwise(Command *spin_clockwise)
{
  spin_clockwise_ = spin_clockwise;
}
Command *KeyAssignments::GetSpinAntiClockwise() const
{
  return spin_anti_clockwise_;
}
void KeyAssignments::SetSpinAntiClockwise(Command *spin_anti_clockwise)
{
  spin_anti_clockwise_ = spin_anti_clockwise;
}
KeyAssignments::KeyAssignments(const sf::Keyboard::Key move_up,
							   const sf::Keyboard::Key move_down,
							   const sf::Keyboard::Key spin_clockwise,
							   const sf::Keyboard::Key spin_anti_clockwise)
{
  move_up_ = new MoveUpCommand(move_up);
  move_down_ = new MoveDownCommand(move_down);
  spin_clockwise_ = new SpinClockwiseCommand(spin_clockwise);
  spin_anti_clockwise_ = new SpinAntiClockwiseCommand(spin_anti_clockwise);
}
Command *KeyAssignments::GetCommandByKey(const sf::Keyboard::Key key)
{
  if (key == move_up_->GetKey())
	return move_up_;
  else if (key == move_down_->GetKey())
	return move_down_;
  else if (key == spin_clockwise_->GetKey())
	return spin_clockwise_;
  else if (key == spin_anti_clockwise_->GetKey())
	return spin_anti_clockwise_;
  else
	return nullptr;
}
