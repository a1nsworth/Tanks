//
// Created by Daniel on 09.05.2023.
//

#ifndef TANKS_SRC_ANIMATION_ANIMATION_H_
#define TANKS_SRC_ANIMATION_ANIMATION_H_

#include <vector>
#include "../entities/Object.h"
#include "../interfaces/IUpdatable.h"
#include "../interfaces/IRendered.h"

// 11 485
class Animation : public IRendered, public IUpdatable
{
 protected:
  float speed_animation_;
  std::vector<Object *> animations_;

 public:
  explicit Animation(float speed_animation);
  ~Animation() = default;
};

#endif //TANKS_SRC_ANIMATION_ANIMATION_H_
