//
// Created by Daniel on 30.04.2023.
//

#ifndef TANKS_SRC_GAME_ENTITIES_TANK_H_
#define TANKS_SRC_GAME_ENTITIES_TANK_H_

#include <cmath>

#include "SolidBody.h"
#include "../control/KeyAssignments.h"
#include "../application/ApplicationConstants.h"
#include "../interfaces/IRendered.h"
#include "../interfaces/IUpdatable.h"

class Tank : public SolidBody, public IRendered, public IUpdatable
{
 private:
  unsigned int health_;
  unsigned int lives_;
  sf::Color color_;

  sf::Vector2f direct_;
  float movement_speed_ = 100000;
  float angle_ = 200000;

  KeyAssignments *key_assignments_;

  void SetTextureRectByColor();
  void SetSettings();

  void Move(const sf::Vector2f &direct, float delta_time);
  void Spin(float angle, float delta_time);

  void UpdateDirect();
 public:
  explicit Tank(sf::Color color, KeyAssignments key_assignments = KeyAssignments(sf::Keyboard::Key::W,
																				 sf::Keyboard::Key::S,
																				 sf::Keyboard::Key::A,
																				 sf::Keyboard::Key::D));
  ~Tank() = default;

  void Render(sf::RenderWindow *render_window) override;
  void Update() override;

  void MoveUp(float delta_time);
  void MoveDown(float delta_time);

  void SpinClockwise(float delta_time);
  void SpinAntiClockwise(float delta_time);

  KeyAssignments *GetKeyAssignments() const;
};

#endif //TANKS_SRC_GAME_ENTITIES_TANK_H_
