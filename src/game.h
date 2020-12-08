#ifndef __GAME_H__
#define __GAME_H__

#include <SFML/Graphics.hpp>
#include <vector>

class Game {
public:
  Game();

  void gameLoop();
  void expandSnake();

private:
  static const uint32_t WINDOW_HEIGHT;
  static const uint32_t WINDOW_WIDTH;

  static const sf::Vector2f MOVE_UP;
  static const sf::Vector2f MOVE_DOWN;
  static const sf::Vector2f MOVE_LEFT;
  static const sf::Vector2f MOVE_RIGHT;

  sf::RenderWindow m_window;
  std::vector<sf::RectangleShape> m_snake;
  sf::Vector2f m_current_movement;
};

#endif // __GAME_H__