//
// Created by Daniel on 16.05.2023.
//

#ifndef TANKS_SRC_ENTITIES_COMPONENTS_TANKSPINCOMPONENT_H_
#define TANKS_SRC_ENTITIES_COMPONENTS_TANKSPINCOMPONENT_H_

#include <SFML/Graphics.hpp>
#include "../interfaces/ISpinnable.h"

class TankSpinComponent : public ISpinnable
{
 private:
  sf::Sprite *sprite_;
  float angel_;

  void Spin(float angle, float delta_time) override;
 public:
  TankSpinComponent(sf::Sprite *const sprite, float angel);
  ~TankSpinComponent() = default;

  void SpinClockwise(float delta_time);
  void SpinAntiClockwise(float delta_time);

  [[nodiscard]] sf::Sprite *GetSprite() const;
  [[nodiscard]]  float GetAngle() const;
  void SetAngel(float angel);
};

#endif //TANKS_SRC_ENTITIES_COMPONENTS_TANKSPINCOMPONENT_H_
