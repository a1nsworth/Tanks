//
// Created by Daniel on 04.05.2023.
//

#ifndef TANKS_SRC_SHOOTING_BULLETS_SIMPLEBULLET_H_
#define TANKS_SRC_SHOOTING_BULLETS_SIMPLEBULLET_H_

#include "Bullet.h"
#include "../../components/SimpleBulletColorComponent.h"

class Tank;

class SimpleBullet : public Bullet
{
 private:
  SimpleBulletColorComponent color_component_;

  void SetUpComponents(const sf::Color &color);
  void SetUpSetting();

  void Move(const sf::Vector2f &direct, float delta_time) override;
  void Spin(float angle, float delta_time) override;
 public:
  SimpleBullet(const sf::Vector2f &start_launch,
			   const float angel_launch,
			   const sf::Vector2f &direct,
			   const sf::Color &color);
  ~SimpleBullet() override = default;

  void Render(sf::RenderWindow *render_window) override;
  void Update(float delta_time) override;

  void ActionOnCollision(const sf::FloatRect &collided_object) override;
  void ActionOnCollision(SolidBody *collided_object) override;
};

#endif //TANKS_SRC_SHOOTING_BULLETS_SIMPLEBULLET_H_
