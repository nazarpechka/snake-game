#ifndef __FOOD_H__
#define __FOOD_H__

#include <SFML/Graphics.hpp>

class Food {
public:
  Food(const sf::Vector2f &pos);

  void draw(sf::RenderWindow &window);
  void setPosition(sf::Vector2f &pos);

private:
  static const unsigned int FOOD_RADIUS;
  static const sf::Color FOOD_COLOR;

  sf::CircleShape m_food;
};

#endif // __FOOD_H__