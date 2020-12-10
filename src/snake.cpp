#include "snake.h"

const sf::Vector2f Snake::SNAKE_PART_DIMENSIONS = sf::Vector2f(30.0f, 30.0f);
const sf::Color Snake::SNAKE_COLOR = sf::Color(111, 97, 7);

Snake::Snake(const sf::Vector2f &head_pos) {
  sf::RectangleShape head(SNAKE_PART_DIMENSIONS);
  head.setFillColor(SNAKE_COLOR);
  head.setPosition(head_pos);

  m_snake_parts.push_back(head);
}

void Snake::expandSnake() {
  sf::RectangleShape tail(SNAKE_PART_DIMENSIONS);
  tail.setFillColor(SNAKE_COLOR);

  sf::Vector2f curr_tail_position = m_snake_parts.back().getPosition();
  tail.setPosition(curr_tail_position.x - SNAKE_PART_DIMENSIONS.x,
                   curr_tail_position.y);

  m_snake_parts.push_back(tail);
}

void Snake::move(const sf::Vector2f &head_pos) {

  for (int i = m_snake_parts.size() - 1; i >= 0; --i) {
    if (i == 0) {
      m_snake_parts[0].move(head_pos);
    } else {
      m_snake_parts[i].setPosition(m_snake_parts[i - 1].getPosition());
    }
  }
}

void Snake::draw(sf::RenderWindow &window) {
  for (int i = 0; i < m_snake_parts.size(); ++i) {
    window.draw(m_snake_parts[i]);
  }
}

const sf::Vector2f &Snake::getHeadPosition() {
  return m_snake_parts[0].getPosition();
}
