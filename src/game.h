#ifndef __GAME_H__
#define __GAME_H__

#include <SFML/Graphics.hpp>
#include <vector>

#include "food.h"
#include "snake.h"

class Game {
public:
  Game();

  void gameLoop();

private:
  static const uint32_t WINDOW_HEIGHT;
  static const uint32_t WINDOW_WIDTH;

  static const sf::Vector2f MOVE_UP;
  static const sf::Vector2f MOVE_DOWN;
  static const sf::Vector2f MOVE_LEFT;
  static const sf::Vector2f MOVE_RIGHT;

  sf::RenderWindow m_window;
  Snake m_snake;
  Food m_food;
  sf::Vector2f m_current_movement;
};

#endif // __GAME_H__