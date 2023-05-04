//
// Created by Daniel on 02.05.2023.
//

#ifndef TANKS_SRC_FIELD_BACKOBSTACLES_H_
#define TANKS_SRC_FIELD_BACKOBSTACLES_H_

#include "../interfaces/IRendered.h"
#include "Obstacle.h"

class BackObstacles : public IRendered
{
 private:
  std::vector<std::vector<Obstacle *>> obstacles_;

  std::vector<std::vector<Obstacle *>> CreateObstacles();
 public:
  BackObstacles();
  ~BackObstacles() = default;

  void Render(sf::RenderWindow *render_window) override;

  const std::vector<std::vector<Obstacle *>> &GetObstacles() const;
};

#endif //TANKS_SRC_FIELD_BACKOBSTACLES_H_
