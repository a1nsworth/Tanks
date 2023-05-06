//
// Created by Daniel on 05.05.2023.
//

#include "GameObstacles.h"
std::unique_ptr<std::vector<std::vector<Object *>>> GameObstacles::CreateObstacles()
{
  auto field = std::make_unique<std::vector<std::vector<Object *>>>(std::vector<std::vector<Object *>>(
	  HEIGHT_MAIN_WINDOW / HEIGHT_GROUND - 2,
	  std::vector<Object *>(WIDTH_MAIN_WINDOW / WIDTH_GROUND - 2,
							nullptr)));
  field.get()->at(1).at(4) = new Obstacle();
  field.get()->at(1).at(4)->GetLinkSprite().setPosition(10 * HEIGHT_GROUND, 4 * WIDTH_GROUND);
  field.get()->at(9).at(9) = new Obstacle();
  field.get()->at(9).at(9)->GetLinkSprite().setPosition(10 * HEIGHT_GROUND, 9 * WIDTH_GROUND);

  return field;
}
void GameObstacles::Render(sf::RenderWindow *render_window)
{

}
void GameObstacles::ActionOnCollision(SolidBody *collided_object)
{

}
bool GameObstacles::IsCollide(const sf::FloatRect &collided_object)
{
  return false;
}
void GameObstacles::ActionOnCollision(const sf::FloatRect &collided_object)
{

}
bool GameObstacles::IsCollide(const SolidBody *collided_object)
{
  return false;
}
GameObstacles::GameObstacles()
{
  field_ = CreateObstacles();
}
