//
// Created by Daniel on 04.05.2023.
//

#ifndef TANKS_SRC_INTERFACES_ICOLLIDED_H_
#define TANKS_SRC_INTERFACES_ICOLLIDED_H_

class SolidBody;

class ICollided
{
 public:
  virtual bool IsCollide(const SolidBody *collided_object) = 0;
  virtual void ActionOnCollision(const SolidBody *collided_object) = 0;
};

#endif //TANKS_SRC_INTERFACES_ICOLLIDED_H_
