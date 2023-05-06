//
// Created by Daniel on 02.05.2023.
//

#include <iostream>
#include "BackObstacles.h"
BackObstacles::BackObstacles()
{
  field_ = CreateObstacles();
  RandomFill(10);
}
void BackObstacles::Render(sf::RenderWindow *const render_window)
{
  for (const auto &kRow : *field_)
	for (const auto &kObstacle : kRow)
	  if (kObstacle != nullptr)
		render_window->draw(kObstacle->GetSprite());
}
std::unique_ptr<std::vector<std::vector<Object *>>> BackObstacles::CreateObstacles()
{
  auto field = std::make_unique<std::vector<std::vector<Object *>>>(std::vector<std::vector<Object *>>(
	  HEIGHT_MAIN_WINDOW / HEIGHT_GROUND,
	  std::vector<Object *>(WIDTH_MAIN_WINDOW / WIDTH_GROUND,
							nullptr)));
#pragma region Заполнение верха
  size_t k = 0;
  for (auto j = 0; j < field->at(0).size(); ++j)
  {
	field->at(k).at(j) = new Obstacle();
	field->at(k).at(j)->GetLinkSprite().setPosition(j * WIDTH_GROUND, k * WIDTH_GROUND);
	filled_cells_.emplace_back(k, j);
  }
#pragma endregion
#pragma region Заполненние низа
  k = field->size() - 1;
  for (auto j = 0; j < field->at(0).size(); ++j)
  {
	field->at(k).at(j) = new Obstacle();
	field->at(k).at(j)->GetLinkSprite().setPosition(j * WIDTH_GROUND, k * HEIGHT_GROUND);
	filled_cells_.emplace_back(k, j);
  }
#pragma endregion
#pragma region Заполнение слева
  k = 0;
  for (auto i = 1; i < field->size() - 1; ++i)
  {
	field->at(i).at(k) = new Obstacle();
	field->at(i).at(k)->GetLinkSprite().setPosition(k * WIDTH_GROUND, i * HEIGHT_GROUND);
	filled_cells_.emplace_back(i, k);
  }
#pragma endregion
#pragma region Заполнение справа
  k = field->at(0).size() - 1;
  for (auto i = 1; i < field->size() - 1; ++i)
  {
	field->at(i).at(k) = new Obstacle();
	field->at(i).at(k)->GetLinkSprite().setPosition(k * WIDTH_GROUND, i * HEIGHT_GROUND);
	filled_cells_.emplace_back(i, k);
  }
#pragma endregion

  return field;
}
const sf::FloatRect &BackObstacles::GetFloatRect() const
{
  return float_rect_;
}
bool BackObstacles::IsCollide(const SolidBody *collided_object)
{
  return IsCollide(collided_object->GetSprite().getGlobalBounds());
}
void BackObstacles::ActionOnCollision(SolidBody *collided_object) {}
bool BackObstacles::IsCollide(const sf::FloatRect &collided_object)
{
  return std::any_of(filled_cells_.begin(),
					 filled_cells_.end(),
					 [&](const std::pair<int, int>& pair)
					 {
					   return field_->at(pair.first).at(pair.second)->GetSprite().getGlobalBounds()
						   .intersects(collided_object);
					 });
}
void BackObstacles::ActionOnCollision(const sf::FloatRect &collided_object) {}
void BackObstacles::RandomFill(const unsigned int count)
{
  srand(time(NULL));
  auto n = count;
  while (n > 0)
  {
	const auto kI = rand() % (field_->size() - 1) + 1;
	const auto kJ = rand() % (field_->at(0).size() - 1) + 1;

	if (field_->at(kI).at(kJ) == nullptr)
	{
	  field_->at(kI).at(kJ) = new Obstacle();
	  field_->at(kI).at(kJ)->GetLinkSprite().setPosition(kJ * WIDTH_GROUND, kI * HEIGHT_GROUND);
	  filled_cells_.emplace_back(kI, kJ);
	  n--;
	}
  }
}
Obstacle *BackObstacles::GetIndexCollide(const SolidBody *collided_object)
{
  return GetIndexCollide(collided_object->GetSprite().getGlobalBounds());
}
Obstacle *BackObstacles::GetIndexCollide(const sf::FloatRect &collided_object)
{
  for (const auto &[kI, kJ] : filled_cells_)
	if (auto obstacle = field_->at(kI).at(kJ); obstacle->GetSprite().getGlobalBounds().intersects(collided_object))
	  return dynamic_cast<Obstacle *>(obstacle);

  return nullptr;
}
