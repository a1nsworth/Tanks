//
// Created by Daniel on 04.05.2023.
//

#ifndef TANKS_SRC_INTERFACES_ISHOOTABLE_H_
#define TANKS_SRC_INTERFACES_ISHOOTABLE_H_

class IShootable
{
 public:
  virtual void Shot(float delta_time) = 0;
};

#endif //TANKS_SRC_INTERFACES_ISHOOTABLE_H_
