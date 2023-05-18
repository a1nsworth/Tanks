//
// Created by Daniel on 04.05.2023.
//

#ifndef TANKS_SRC_SHOOTING_BULLETS_BULLET_H_
#define TANKS_SRC_SHOOTING_BULLETS_BULLET_H_

#include "../../entities/SolidBody.h"
#include "../../interfaces/IMovable.h"
#include "../../interfaces/ISpinnable.h"
#include "../../interfaces/IRendered.h"
#include "../../interfaces/IUpdatable.h"

class Bullet : public SolidBody, public IMovable, public ISpinnable, public IRendered, public IUpdatable
{
 protected:
  unsigned int damage_;
  float flight_speed_;
  bool is_launched_;

  sf::Vector2f direct_;

  explicit Bullet(unsigned int damage, float flight_speed, const sf::Vector2f &direct);
 public:
  ~Bullet() override = default;

  [[nodiscard]] bool IsLaunched() const;
  [[nodiscard]] unsigned int GetDamage() const;
  [[nodiscard]] const sf::Vector2f &GetDirect() const;

  void SetIsLaunched(bool is_launched);
};

#endif //TANKS_SRC_SHOOTING_BULLETS_BULLET_H_
