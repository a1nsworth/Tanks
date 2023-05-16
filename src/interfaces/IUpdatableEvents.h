//
// Created by Daniel on 12.05.2023.
//

#ifndef TANKS_SRC_INTERFACES_IUPDATABLEEVENTS_H_
#define TANKS_SRC_INTERFACES_IUPDATABLEEVENTS_H_

#include <SFML/Graphics.hpp>

class IUpdatableEvents
{
 public:
  virtual void UpdateEvents(sf::RenderWindow *render_window, float delta_time) = 0;
};

#endif //TANKS_SRC_INTERFACES_IUPDATABLEEVENTS_H_
