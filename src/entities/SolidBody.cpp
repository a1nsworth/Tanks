//
// Created by Daniel on 30.04.2023.
//

#include <iostream>
#include "SolidBody.h"

bool SolidBody::IsCollide(const SolidBody *const collided_object)
{
  return GetSprite().getGlobalBounds().intersects(collided_object->GetSprite().getGlobalBounds());
}
void SolidBody::ActionOnCollision(const SolidBody *collided_object)
{
  if (IsCollide(collided_object))
  {
#pragma region Коллизия слева
	if (const auto kX = GetSprite().getPosition().x - GetSprite().getOrigin().x; kX
		< collided_object->GetSprite().getGlobalBounds().top)
	{
	  GetLinkSprite().setPosition(collided_object->GetSprite().getGlobalBounds().top + GetSprite().getOrigin().x,
								  GetSprite().getPosition().y);
	}
#pragma endregion
#pragma region Коллизия слева-сверху
	if (const auto kY = GetSprite().getPosition().y - GetSprite().getOrigin().y; kY
		< collided_object->GetSprite().getGlobalBounds().left)
	{
	  GetLinkSprite().setPosition(GetSprite().getPosition().x,
								  collided_object->GetSprite().getGlobalBounds().left + GetSprite().getOrigin().y);
	}
#pragma endregion
#pragma region Коллизия справа
	if (const auto kX = GetSprite().getPosition().x + GetSprite().getOrigin().x; kX
		> collided_object->GetSprite().getGlobalBounds().width + collided_object->GetSprite().getGlobalBounds().left)
	{
	  GetLinkSprite().setPosition(
		  collided_object->GetSprite().getGlobalBounds().width + collided_object->GetSprite().getGlobalBounds().left
			  - GetSprite().getOrigin().x,
		  GetSprite().getPosition().y);
	}
#pragma endregion
#pragma region Коолизия справа-снизу
	if (const auto kY = GetSprite().getPosition().y + GetSprite().getOrigin().y; kY
		> collided_object->GetSprite().getGlobalBounds().height + collided_object->GetSprite().getGlobalBounds().top)
	{
	  GetLinkSprite().setPosition(GetSprite().getPosition().x,
								  collided_object->GetSprite().getGlobalBounds().height
									  + collided_object->GetSprite().getGlobalBounds().top - GetSprite().getOrigin().y);
	}
#pragma endregion
  }
}
