//
// Created by Daniel on 09.05.2023.
//

#ifndef TANKS_SRC_BAR_HEALTHBAR_H_
#define TANKS_SRC_BAR_HEALTHBAR_H_

#include "../entities/Object.h"
#include "../interfaces/IObserver.h"
#include "../interfaces/IRendered.h"
#include "../application/ApplicationConstants.h"

class HealthBar : public IObserver
{
 private:
  static const int count_health_ = 5;
  std::vector<Object *> bars_ = std::vector<Object *>(count_health_);

  int index_current_sprite_;

  void FillBars(const sf::Color &color, const sf::Vector2f &position);
 public:
  HealthBar(const sf::Color &color, const sf::Vector2f &position);
  ~HealthBar()  = default;

  void Update() override;
  void Render(sf::RenderWindow *render_window) override;
};

#endif //TANKS_SRC_BAR_HEALTHBAR_H_
