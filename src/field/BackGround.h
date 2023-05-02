//
// Created by Daniel on 30.04.2023.
//

#ifndef TANKS_SRC_FIELD_BACKGROUND_H_
#define TANKS_SRC_FIELD_BACKGROUND_H_

#include "../interfaces/IRendered.h"
#include "Obstacle.h"
#include "Ground.h"

class BackGround : public Object, public IRendered
{
 private:
  std::vector<std::vector<Ground>> grounds_;
  std::vector<std::vector<Obstacle>> obstacles_;
 public:
  BackGround();
  ~BackGround() = default;

  void Render(sf::RenderWindow *render_window) override;
};

#endif //TANKS_SRC_FIELD_BACKGROUND_H_
