//
// Created by Daniel on 04.05.2023.
//

#ifndef TANKS_SRC_INTERFACES_ISPINNABLE_H_
#define TANKS_SRC_INTERFACES_ISPINNABLE_H_

class ISpinnable
{
  virtual void Spin(float angle, float delta_time) = 0;
};

#endif //TANKS_SRC_INTERFACES_ISPINNABLE_H_
