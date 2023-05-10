//
// Created by Daniel on 09.05.2023.
//

#ifndef TANKS_SRC_INTERFACES_IOBSERVABLE_H_
#define TANKS_SRC_INTERFACES_IOBSERVABLE_H_

#include "IObserver.h"

class IObservable
{
  virtual void AddObserver(IObserver *observer) = 0;
  virtual void RemoveObserver(IObserver *observer) = 0;
  virtual void NotifyObservers() = 0;
};

#endif //TANKS_SRC_INTERFACES_IOBSERVABLE_H_
