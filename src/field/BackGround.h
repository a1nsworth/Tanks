//
// Created by Daniel on 30.04.2023.
//

#ifndef TANKS_SRC_FIELD_BACKGROUND_H_
#define TANKS_SRC_FIELD_BACKGROUND_H_

#include <memory>

#include "../interfaces/IRendered.h"
#include "Field.h"
#include "Obstacle.h"
#include "Ground.h"

class BackGround : public Field, public IRendered
{
 private:
  std::unique_ptr<std::vector<std::vector<Object *>>> FillField();
 public:
  BackGround();
  ~BackGround() override = default;

  void Render(sf::RenderWindow *render_window) override;
  bool IsCollide(const SolidBody *collided_object) override;
  bool IsCollide(const sf::FloatRect &collided_object) override;
  void ActionOnCollision(SolidBody *collided_object) override;
  void ActionOnCollision(const sf::FloatRect &collided_object) override;
};

#endif //TANKS_SRC_FIELD_BACKGROUND_H_
