//
// Created by Daniel on 16.05.2023.
//

#ifndef TANKS_SRC_COMPONENTS_TANKMOVECOMPONENT_H_
#define TANKS_SRC_COMPONENTS_TANKMOVECOMPONENT_H_

#include <cmath>
#include "../interfaces/IMovable.h"

class TankMoveComponent : public IMovable
{
 private:
  sf::Sprite *sprite_;

  sf::Vector2f direct_;
  float movement_speed_;

  void Move(const sf::Vector2f &direct, float delta_time) override;
 public:
  TankMoveComponent(sf::Sprite *sprite, float movement_speed);
  ~TankMoveComponent() = default;

  void UpdateDirect();

  void MoveUp(float delta_time);
  void MoveDown(float delta_time);

  [[nodiscard]]    sf::Sprite *GetSprite() const;
  [[nodiscard]]    const sf::Vector2f &GetDirect() const;
  [[nodiscard]]    float GetMovementSpeed() const;
  void SetMovementSpeed(float movement_speed);
};

#endif //TANKS_SRC_COMPONENTS_TANKMOVECOMPONENT_H_
