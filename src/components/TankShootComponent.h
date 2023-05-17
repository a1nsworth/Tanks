//
// Created by Daniel on 17.05.2023.
//

#ifndef TANKS_SRC_COMPONENTS_TANKSHOOTCOMPONENT_H_
#define TANKS_SRC_COMPONENTS_TANKSHOOTCOMPONENT_H_

#include "../shooting/bullets/SimpleBullet.h"
#include "../interfaces/IShootable.h"
#include "TankMoveComponent.h"

#include <memory>

class TankShootComponent : public IShootable, public IUpdatable, public IRendered
{
 private:
  std::unique_ptr<Bullet> bullet_ = nullptr;
  float duration_;
  float time_last_shoot_ = 0;
  sf::Clock clock_;

  sf::Color color_;

  TankMoveComponent *move_component_;
 public:
  explicit TankShootComponent(TankMoveComponent *move_component,
							  const sf::Color &color,
							  float duration = 2);
  ~TankShootComponent() = default;

  [[nodiscard]] const std::unique_ptr<Bullet> &GetBullet() const;
  [[nodiscard]] float GetDuration() const;
  [[nodiscard]] float GetTimeLastShoot() const;
  [[nodiscard]] const sf::Clock &GetClock() const;

  void Shot(float delta) override;
  void DeleteBullet();

  void Render(sf::RenderWindow *render_window) override;
  void Update(float delta_time) override;
};

#endif //TANKS_SRC_COMPONENTS_TANKSHOOTCOMPONENT_H_
