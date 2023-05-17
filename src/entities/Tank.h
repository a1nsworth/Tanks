//
// Created by Daniel on 30.04.2023.
//

#ifndef TANKS_SRC_ENTITIES_TANK_H_
#define TANKS_SRC_ENTITIES_TANK_H_

#include <cmath>
#include <algorithm>

#include "SolidBody.h"
#include "../animation/AnimationDeath.h"
#include "../control/KeyAssignments.h"
#include "../application/ApplicationConstants.h"
#include "../interfaces/IHitable.h"
#include "../subject/Subject.h"
#include "../components/TankMoveComponent.h"
#include "../components/TankSpinComponent.h"
#include "../components/TankShootComponent.h"
#include "../components/TankColorComponent.h"

class Tank
	: public SolidBody,
	  public IRendered,
	  public IUpdatable,
	  public IHitable,
	  public IShootable
{
 private:
  TankMoveComponent *move_component_;
  TankSpinComponent *spin_component_;
  TankShootComponent *shoot_component_;
  TankColorComponent color_component_;

  bool is_alive_ = true;
  unsigned int health_ = 4;
  sf::Color color_;

  KeyAssignments *key_assignments_;

  AnimationDeath *animation_death_;

  void SetUpComponents(const sf::Color &color);
  void SetUpSettings();
 public:
  Subject on_getting_damage;

  explicit Tank(sf::Color color, KeyAssignments key_assignments);
  ~Tank() override = default;

  [[nodiscard]] bool IsAlive() const;
  [[nodiscard]] Bullet *GetBullet() const;
  [[nodiscard]] KeyAssignments *GetKeyAssignments() const;

  void Render(sf::RenderWindow *render_window) override;
  void Update(float delta_time) override;

  void MoveUp(float delta_time);
  void MoveDown(float delta_time);
  void SpinClockwise(float delta_time);
  void SpinAntiClockwise(float delta_time);
  void Shot(float delta_time) override;
  void DeleteBullet();

  void ActionOnCollision(SolidBody *collided_object) override;
  void ActionOnCollision(const sf::FloatRect &collided_object) override;

  void Hit(unsigned int damage) override;
};

#endif //TANKS_SRC_ENTITIES_TANK_H_
