//
// Created by Daniel on 09.05.2023.
//

#ifndef TANKS_SRC_INTERFACES_IOBSERVER_H_
#define TANKS_SRC_INTERFACES_IOBSERVER_H_

#include "IRendered.h"

class IObserver : public IRendered
{
 public:
  virtual void Update() = 0;
};

#endif //TANKS_SRC_INTERFACES_IOBSERVER_H_
