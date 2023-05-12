//
// Created by Daniel on 07.05.2023.
//

#ifndef TANKS_SRC_INTERFACES_IAPPLICATIONSTATE_H_
#define TANKS_SRC_INTERFACES_IAPPLICATIONSTATE_H_

#include <SFML/Graphics.hpp>
#include "../window/Window.h"

class Application;

class IApplicationState
{
 public:
  virtual void UpdateEvents(Application *application, float delta_time) = 0;
  virtual void Update(Application *application, float delta_time) = 0;
  virtual void Render(Application *application) = 0;
};

#endif //TANKS_SRC_INTERFACES_IAPPLICATIONSTATE_H_
