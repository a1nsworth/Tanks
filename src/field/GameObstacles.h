//
// Created by Daniel on 05.05.2023.
//

#ifndef TANKS_SRC_FIELD_GAMEOBSTACLES_H_
#define TANKS_SRC_FIELD_GAMEOBSTACLES_H_

#include "Field.h"
#include "Obstacle.h"
#include "../interfaces/IRendered.h"
#include "../application/ApplicationConstants.h"

class GameObstacles : public Field, public IRendered
{
 protected:
  std::unique_ptr<std::vector<std::vector<Object *>>> CreateObstacles();
 public:
  GameObstacles();
  ~GameObstacles() override = default;

  void Render(sf::RenderWindow *render_window) override;

  bool IsCollide(const SolidBody *collided_object) override;
  void ActionOnCollision(SolidBody *collided_object) override;
  bool IsCollide(const sf::FloatRect &collided_object) override;
  void ActionOnCollision(const sf::FloatRect &collided_object) override;
};

#endif //TANKS_SRC_FIELD_GAMEOBSTACLES_H_
