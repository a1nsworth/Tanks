//
// Created by Daniel on 02.05.2023.
//

#ifndef TANKS_SRC_ENTITIES_OBJECT_H_
#define TANKS_SRC_ENTITIES_OBJECT_H_

#include "SFML/Graphics.hpp"

class Object
{
 protected:
  sf::Image image_;
  sf::Texture texture_;
  sf::Sprite sprite_;

 public:
  Object(const sf::Image &image, const sf::Texture &texture, const sf::Sprite &sprite);
  Object();
  virtual ~Object() = default;

  const sf::Image &GetImage() const;
  const sf::Texture &GetTexture() const;
  const sf::Sprite &GetSprite() const;
  void SetImage(const sf::Image &image);
  void SetTexture(const sf::Texture &texture);
  void SetSprite(const sf::Sprite &sprite);

  sf::Image &GetLinkImage();
  sf::Texture &GetLinkTexture();
  sf::Sprite &GetLinkSprite();
};

#endif //TANKS_SRC_ENTITIES_OBJECT_H_
