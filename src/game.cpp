#include "game.h"

#include <iostream>

const uint32_t Game::WINDOW_HEIGHT = 720;
const uint32_t Game::WINDOW_WIDTH = 960;

const sf::Vector2f Game::MOVE_UP(0.0f, -30.0f);
const sf::Vector2f Game::MOVE_DOWN(0.0f, 30.0f);
const sf::Vector2f Game::MOVE_LEFT(-30.0f, 0.0f);
const sf::Vector2f Game::MOVE_RIGHT(30.0f, 0.0f);

Game::Game()
    : m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Snake game"),
      m_current_movement(MOVE_RIGHT) {
  m_window.setVerticalSyncEnabled(true);
  expandSnake();
}

void Game::gameLoop() {

  expandSnake();
  expandSnake();

  int moved = 0;

  while (m_window.isOpen()) {
    sf::Event event;

    sf::Vector2f previous_movement(m_current_movement);

    while (m_window.pollEvent(event)) {
      switch (event.type) {

      case sf::Event::Closed:
        m_window.close();
        break;

      case sf::Event::KeyPressed:
        if (event.key.code == sf::Keyboard::W &&
            m_current_movement != MOVE_UP) {
          m_current_movement = MOVE_UP;
          moved = 0;
        } else if (event.key.code == sf::Keyboard::A &&
                   m_current_movement != MOVE_LEFT) {
          m_current_movement = MOVE_LEFT;
          moved = 0;
        } else if (event.key.code == sf::Keyboard::S &&
                   m_current_movement != MOVE_DOWN) {
          m_current_movement = MOVE_DOWN;
          moved = 0;
        } else if (event.key.code == sf::Keyboard::D &&
                   m_current_movement != MOVE_RIGHT) {
          m_current_movement = MOVE_RIGHT;
          moved = 0;
        }
        break;

      case sf::Event::KeyReleased:
        break;

      default:
        break;
      }
    }

    m_window.clear(sf::Color(188, 201, 1));

    for (int i = 0; i < m_snake.size(); ++i) {
      if (i <= moved) {
        m_snake[i].move(m_current_movement);
      } else
        m_snake[i].move(previous_movement);

      m_window.draw(m_snake[i]);
      // std::cout << "x=" << snake_part.getPosition().x
      //           << ",y=" << snake_part.getPosition().y << '\n';
    }
    moved++;

    m_window.display();
    sf::sleep(sf::seconds(0.5));
  }
}

void Game::expandSnake() {
  sf::RectangleShape snake_part(sf::Vector2f(30, 30));
  snake_part.setFillColor(sf::Color(111, 97, 7));

  if (m_snake.empty()) {
    snake_part.setPosition(
        sf::Vector2f(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f));
  } else {
    sf::Vector2f tail_position = m_snake.back().getPosition();
    sf::Vector2f new_tail_position(tail_position.x - 30.0f, tail_position.y);

    snake_part.setPosition(new_tail_position);
  }

  m_snake.push_back(snake_part);
}