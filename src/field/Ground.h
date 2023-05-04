//
// Created by Daniel on 30.04.2023.
//

#ifndef TANKS_SRC_FIELD_GROUND_H_
#define TANKS_SRC_FIELD_GROUND_H_

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#include "../application/ApplicationConstants.h"
#include "../entities/Object.h"

class Ground : public Object
{
 public:
  Ground();
  ~Ground() = default;
};

#endif //TANKS_SRC_FIELD_GROUND_H_
