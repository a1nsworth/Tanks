//
// Created by Daniel on 09.05.2023.
//

#ifndef TANKS_SRC_ANIMATION_ANIMATIONDEATH_H_
#define TANKS_SRC_ANIMATION_ANIMATIONDEATH_H_

#include <iostream>
#include <exception>

#include "Animation.h"
#include "../application/ApplicationConstants.h"
#include "../interfaces/IMovable.h"

class AnimationDeath : public Animation, public IMovable
{
 private:
  const float step_scale_size_ = 0.001;

  float movement_speed_y_ = 50;
  const int count_animations_ = 100;

  bool is_finished_;
  bool is_started_;

  Object *CreateObject(const sf::Color &color);

  void Move(const sf::Vector2f &direct, float delta_time) override;
  void MoveUp(float delta_time);

  void ReScaling()
  {
	const auto kCurrentScale = animations_.at(0)->GetLinkSprite().getScale();
	//animations_.at(0)->GetLinkSprite().setScale(kCurrentScale.x + step_scale_size_, kCurrentScale.y + step_scale_size_);
  }
 public:
  explicit AnimationDeath(const sf::Color &color);
  ~AnimationDeath()  = default;

  bool IsFinished() const;
  bool IsStarted() const;

  void Run(const sf::Vector2f &appearance_position);

  void Render(sf::RenderWindow *render_window) override;
  void Update(float delta_time) override;
};

#endif //TANKS_SRC_ANIMATION_ANIMATIONDEATH_H_
