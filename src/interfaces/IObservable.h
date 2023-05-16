//
// Created by Daniel on 09.05.2023.
//

#ifndef TANKS_SRC_INTERFACES_IOBSERVABLE_H_
#define TANKS_SRC_INTERFACES_IOBSERVABLE_H_

#include "IObserver.h"

class IObservable
{
 public:
  virtual void Add(IObserver *observer) = 0;
  virtual void Remove(IObserver *observer) = 0;
  virtual void Notify() = 0;
};

#endif //TANKS_SRC_INTERFACES_IOBSERVABLE_H_
