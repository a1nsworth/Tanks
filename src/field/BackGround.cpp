//
// Created by Daniel on 30.04.2023.
//

#include "BackGround.h"
BackGround::BackGround()
{
  field_ = FillField();
}
void BackGround::Render(sf::RenderWindow *const render_window)
{
  for (const auto &kRow : *field_)
	for (const auto &kObject : kRow)
	  render_window->draw(kObject->GetSprite());
}
std::unique_ptr<std::vector<std::vector<Object *>>> BackGround::FillField()
{
  auto field = std::make_unique<std::vector<std::vector<Object *>>>(std::vector<std::vector<Object *>>(
	  HEIGHT_MAIN_WINDOW / HEIGHT_GROUND,
	  std::vector<Object *>(WIDTH_MAIN_WINDOW / WIDTH_GROUND,
							nullptr)));

  for (int i = 0; i < field->size(); ++i)
	for (int j = 0; j < field->begin()->size(); ++j)
	{
	  field.get()->at(i).at(j) = new Ground();
	  field.get()->at(i).at(j)->GetLinkSprite().setPosition(j * WIDTH_GROUND, i * HEIGHT_GROUND);
	}

  return field;
}
bool BackGround::IsCollide(const SolidBody *collided_object)
{
  return IsCollide(collided_object->GetSprite().getGlobalBounds());
}
bool BackGround::IsCollide(const sf::FloatRect &collided_object)
{
  for (const auto &kRow : *field_)
	for (const auto &kObject : kRow)
	  if (kObject->GetSprite().getGlobalBounds().intersects(collided_object))
		return true;

  return false;
}
void BackGround::ActionOnCollision(const sf::FloatRect &collided_object) {}
void BackGround::ActionOnCollision(SolidBody *collided_object) {}
