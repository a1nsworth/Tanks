//
// Created by Daniel on 05.05.2023.
//

#ifndef TANKS_SRC_FIELD_FIELD_H_
#define TANKS_SRC_FIELD_FIELD_H_

#include <vector>

#include "../entities/Object.h"
#include "../interfaces/ICollided.h"

class Field : public ICollided
{
 protected:
  std::unique_ptr<std::vector<std::vector<Object *>>> field_;

  virtual ~Field() = default;
};

#endif //TANKS_SRC_FIELD_FIELD_H_
