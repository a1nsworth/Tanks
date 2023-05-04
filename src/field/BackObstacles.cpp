//
// Created by Daniel on 02.05.2023.
//

#include <iostream>
#include "BackObstacles.h"
BackObstacles::BackObstacles()
{
  obstacles_ = CreateObstacles();
}
void BackObstacles::Render(sf::RenderWindow *const render_window)
{
  for (const auto &kRow : obstacles_)
	for (const auto &kObstacle : kRow)
	  if (kObstacle != nullptr)
		render_window->draw(kObstacle->GetSprite());
}
std::vector<std::vector<Obstacle *>> BackObstacles::CreateObstacles()
{
  auto field = std::vector<std::vector<Obstacle *>>(HEIGHT_MAIN_WINDOW / HEIGHT_GROUND,
													std::vector<Obstacle *>(WIDTH_MAIN_WINDOW / WIDTH_GROUND,
																			nullptr));
#pragma region Заполнение верха
  size_t k = 0;
  for (auto j = 0; j < field.at(0).size(); ++j)
  {
	field[k][j] = new Obstacle();
	field[k][j]->GetLinkSprite().setPosition(j * WIDTH_GROUND, k * WIDTH_GROUND);
	std::cout << "left: " << field[k][j]->GetLinkSprite().getGlobalBounds().left << " | "
			  << "top: " << field[k][j]->GetLinkSprite().getGlobalBounds().top << " | " <<
			  "width: " << field[k][j]->GetLinkSprite().getGlobalBounds().width << " | " <<
			  "height: " << field[k][j]->GetLinkSprite().getGlobalBounds().height << " | " << '\n';
  }
#pragma endregion
#pragma region Заполненние низа
  k = field.size() - 1;
  for (auto j = 0; j < field.at(0).size(); ++j)
  {
	field[k][j] = new Obstacle();
	field[k][j]->GetLinkSprite().setPosition(j * WIDTH_GROUND, k * HEIGHT_GROUND);
	std::cout << "left: " << field[k][j]->GetLinkSprite().getGlobalBounds().left << " | "
			  << "top: " << field[k][j]->GetLinkSprite().getGlobalBounds().top << " | " <<
			  "width: " << field[k][j]->GetLinkSprite().getGlobalBounds().width << " | " <<
			  "height: " << field[k][j]->GetLinkSprite().getGlobalBounds().height << " | " << '\n';
  }
#pragma endregion
#pragma region Заполнение слева
  k = 0;
  for (auto i = 1; i < field.size() - 1; ++i)
  {
	field[i][k] = new Obstacle();
	field[i][k]->GetLinkSprite().setPosition(k * WIDTH_GROUND, i * HEIGHT_GROUND);
	std::cout << "left: " << field[i][k]->GetLinkSprite().getGlobalBounds().left << " | "
			  << "top: " << field[i][k]->GetLinkSprite().getGlobalBounds().top << " | " <<
			  "width: " << field[i][k]->GetLinkSprite().getGlobalBounds().width << " | " <<
			  "height: " << field[i][k]->GetLinkSprite().getGlobalBounds().height << " | " << '\n';
  }
#pragma endregion
#pragma region Заполнение справа
  k = field.at(0).size() - 1;
  for (auto i = 1; i < field.size() - 1; ++i)
  {
	field[i][k] = new Obstacle();
	field[i][k]->GetLinkSprite().setPosition(k * WIDTH_GROUND, i * HEIGHT_GROUND);
	std::cout << "left: " << field[i][k]->GetLinkSprite().getGlobalBounds().left << " | "
			  << "top: " << field[i][k]->GetLinkSprite().getGlobalBounds().top << " | " <<
			  "width: " << field[i][k]->GetLinkSprite().getGlobalBounds().width << " | " <<
			  "height: " << field[i][k]->GetLinkSprite().getGlobalBounds().height << " | " << '\n';
  }
#pragma endregion

  return field;
}
const std::vector<std::vector<Obstacle *>> &BackObstacles::GetObstacles() const
{
  return obstacles_;
}
