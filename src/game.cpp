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
      m_current_movement(MOVE_RIGHT),
      m_food(sf::Vector2f(rand() % (WINDOW_WIDTH - 15),
                          rand() % (WINDOW_HEIGHT - 15))),
      m_snake(sf::Vector2f(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f)) {
  m_window.setFramerateLimit(15);
}

void Game::gameLoop() {

  while (m_window.isOpen()) {
    sf::Event event;

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

      default:
        break;
      }
    }

    m_window.clear(sf::Color(188, 201, 1));

    // Detect borders and teleport snake to the opposite side
    // sf::Vector2f head_pos = m_snake[0].getPosition();
    // if (head_pos.x >= WINDOW_WIDTH)
    //   m_snake[0].setPosition(0, head_pos.y);
    // else if (head_pos.x <= 0)
    //   m_snake[0].setPosition(WINDOW_WIDTH, head_pos.y);
    // else if (head_pos.y >= WINDOW_HEIGHT)
    //   m_snake[0].setPosition(head_pos.x, 0);
    // else if (head_pos.y <= 0)
    //   m_snake[0].setPosition(head_pos.x, WINDOW_HEIGHT);

    // Move head in the current direction
    m_snake.move(m_current_movement);
    m_snake.draw(m_window);

    // if (m_snake[0].getGlobalBounds().intersects(m_food.getGlobalBounds())) {
    //   std::cout << "Got food!\n";
    // }

    m_food.draw(m_window);

    m_window.display();
    // sf::sleep(sf::seconds(0.5));
  }
}
