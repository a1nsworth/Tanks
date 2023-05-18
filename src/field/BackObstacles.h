//
// Created by Daniel on 02.05.2023.
//

#ifndef TANKS_SRC_FIELD_BACKOBSTACLES_H_
#define TANKS_SRC_FIELD_BACKOBSTACLES_H_

#include "Field.h"
#include "../interfaces/IRendered.h"
#include "Obstacle.h"

class BackObstacles : public Field, public IRendered
{
 private:
  std::vector<std::pair<int, int>> filled_cells_;

  sf::FloatRect float_rect_ = sf::FloatRect(WIDTH_GROUND,
											HEIGHT_GROUND,
											WIDTH_MAIN_WINDOW - (WIDTH_GROUND << 1),
											HEIGHT_MAIN_WINDOW - (HEIGHT_GROUND << 1));

  std::unique_ptr<std::vector<std::vector<Object *>>> CreateObstacles();

  void RandomFill(unsigned int count);
 public:
  BackObstacles();
  ~BackObstacles() override = default;

  [[nodiscard]] const sf::FloatRect &GetFloatRect() const;

  void Render(sf::RenderWindow *render_window) override;
  bool IsCollide(const SolidBody *collided_object) override;
  void ActionOnCollision(SolidBody *collided_object) override;
  bool IsCollide(const sf::FloatRect &collided_object) override;
  void ActionOnCollision(const sf::FloatRect &collided_object) override;

  Obstacle *GetIndexCollide(const SolidBody *collided_object);
  Obstacle *GetIndexCollide(const sf::FloatRect &collided_object);
};

#endif //TANKS_SRC_FIELD_BACKOBSTACLES_H_
