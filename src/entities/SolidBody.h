//
// Created by Daniel on 30.04.2023.
//

#ifndef TANKS_SRC_ENTITIES_SOLIDBODY_H_
#define TANKS_SRC_ENTITIES_SOLIDBODY_H_

#include "Object.h"
#include "../interfaces/ICollided.h"

class SolidBody : public Object, public ICollided
{
 public:
  bool IsCollide(const SolidBody *collided_object) override;
  bool IsCollide(const sf::FloatRect &collided_object) override;
};

#endif //TANKS_SRC_ENTITIES_SOLIDBODY_H_
