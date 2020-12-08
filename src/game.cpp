#include "game.h"

#include <iostream>

const uint32_t Game::WINDOW_HEIGHT = 720;
const uint32_t Game::WINDOW_WIDTH = 960;

const sf::Vector2f Game::MOVE_UP(0.0f, -35.0f);
const sf::Vector2f Game::MOVE_DOWN(0.0f, 35.0f);
const sf::Vector2f Game::MOVE_LEFT(-35.0f, 0.0f);
const sf::Vector2f Game::MOVE_RIGHT(35.0f, 0.0f);

Game::Game()
    : m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Snake game"),
      m_current_movement(MOVE_RIGHT) {
  m_window.setVerticalSyncEnabled(true);
  expandSnake();
}

void Game::gameLoop() {

  expandSnake();
  expandSnake();
  expandSnake();
  expandSnake();

  while (m_window.isOpen()) {
    sf::Event event;

    sf::Vector2f previous_movement(m_current_movement);

    while (m_window.pollEvent(event)) {
      switch (event.type) {

      case sf::Event::Closed:
        m_window.close();
        break;

      case sf::Event::KeyPressed:
        if (event.key.code == sf::Keyboard::W) {
          m_current_movement = MOVE_UP;
        } else if (event.key.code == sf::Keyboard::A &&
                   m_current_movement != MOVE_RIGHT) {
          m_current_movement = MOVE_LEFT;
        } else if (event.key.code == sf::Keyboard::S) {
          m_current_movement = MOVE_DOWN;
        } else if (event.key.code == sf::Keyboard::D &&
                   m_current_movement != MOVE_LEFT) {
          m_current_movement = MOVE_RIGHT;
        }
        break;

      case sf::Event::KeyReleased:
        break;

      default:
        break;
      }
    }

    m_window.clear(sf::Color(188, 201, 1));

    sf::Vector2f head_pos = m_snake[0].getPosition();
    if (head_pos.x >= WINDOW_WIDTH)
      m_snake[0].setPosition(0, head_pos.y);
    else if (head_pos.x <= 0)
      m_snake[0].setPosition(WINDOW_WIDTH, head_pos.y);
    else if (head_pos.y >= WINDOW_HEIGHT)
      m_snake[0].setPosition(head_pos.x, 0);
    else if (head_pos.y <= 0)
      m_snake[0].setPosition(head_pos.x, WINDOW_HEIGHT);

    for (int i = m_snake.size() - 1; i >= 0; --i) {
      if (i == 0) {
        m_snake[i].move(m_current_movement);
      } else
        m_snake[i].setPosition(m_snake[i - 1].getPosition());

      m_window.draw(m_snake[i]);
    }

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
    sf::Vector2f new_tail_position(tail_position.x - 35.0f, tail_position.y);

    snake_part.setPosition(new_tail_position);
  }

  m_snake.push_back(snake_part);
}