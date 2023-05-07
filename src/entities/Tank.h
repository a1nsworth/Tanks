//
// Created by Daniel on 30.04.2023.
//

#ifndef TANKS_SRC_GAME_ENTITIES_TANK_H_
#define TANKS_SRC_GAME_ENTITIES_TANK_H_

#include <queue>
#include <cmath>

#include "SolidBody.h"
#include "../control/KeyAssignments.h"
#include "../application/ApplicationConstants.h"
#include "../interfaces/IRendered.h"
#include "../interfaces/IUpdatable.h"
#include "../interfaces/IShootable.h"
#include "../interfaces/IHitable.h"
#include "../shooting/bullets/SimpleBullet.h"

class Tank
	: public SolidBody,
	  public IRendered,
	  public IUpdatable,
	  public IShootable,
	  public IMovable,
	  public ISpinnable,
	  public IHitable
{
 private:
  bool is_alive_ = true;
  unsigned int base_health_ = 2;
  unsigned int health_ = base_health_;
  unsigned int lives_ = 1;
  sf::Color color_;

  sf::Vector2f direct_;
  const float angel_ = 200000;
  const float movement_speed_ = 100000;
  const float split_speed_ = 1;
  float current_movement_speed_ = movement_speed_;
  float current_split_speed_ = 0;

  Bullet *bullet_ = nullptr;
  const float duration_ = 2;
  float time_last_shoot_ = 0;
  sf::Clock clock_;

  KeyAssignments *key_assignments_;

  void SetTextureRectByColor();
  void SetSettings();

  void Move(const sf::Vector2f &direct, float delta_time) override;
  void Spin(float angle, float delta_time) override;

  void UpdateDirect();
 public:
  explicit Tank(sf::Color color, KeyAssignments key_assignments = KeyAssignments(sf::Keyboard::Key::W,
																				 sf::Keyboard::Key::S,
																				 sf::Keyboard::Key::A,
																				 sf::Keyboard::Key::D,
																				 sf::Keyboard::Key::C));
  ~Tank() override = default;

  bool IsAlive() const;
  Bullet *GetBullet() const;
  const float GetDuration() const;
  const sf::Vector2f &GetDirect() const;
  KeyAssignments *GetKeyAssignments() const;

  void Render(sf::RenderWindow *render_window) override;
  void Update(float delta_time) override;

  void MoveUp(float delta_time);
  void MoveDown(float delta_time);
  void SpinClockwise(float delta_time);
  void SpinAntiClockwise(float delta_time);
  void Shot(float delta_time) override;

  void ActionOnCollision(SolidBody *collided_object) override;
  void ActionOnCollision(const sf::FloatRect &collided_object) override;
  void Hit(unsigned int damage) override;

  void DeleteBullet();
};

#endif //TANKS_SRC_GAME_ENTITIES_TANK_H_
