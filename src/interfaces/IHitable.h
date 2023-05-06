//
// Created by Daniel on 05.05.2023.
//

#ifndef TANKS_SRC_INTERFACES_IHITABLE_H_
#define TANKS_SRC_INTERFACES_IHITABLE_H_

class IHitable
{
 public:
  virtual void Hit(unsigned int damage) = 0;
};

#endif //TANKS_SRC_INTERFACES_IHITABLE_H_
