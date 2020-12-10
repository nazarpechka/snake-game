#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <SFML/Graphics.hpp>
#include <vector>

class Snake {
public:
  Snake(const sf::Vector2f &head_pos);

  void expandSnake();
  void move(const sf::Vector2f &head_pos);
  void draw(sf::RenderWindow &window);

  const sf::Vector2f &getHeadPosition();

private:
  static const sf::Vector2f SNAKE_PART_DIMENSIONS;
  static const sf::Color SNAKE_COLOR;

  std::vector<sf::RectangleShape> m_snake_parts;
};

#endif // __SNAKE_H__