#include "food.h"

const unsigned int Food::FOOD_RADIUS = 15;
const sf::Color Food::FOOD_COLOR = sf::Color::Red;

Food::Food(const sf::Vector2f &pos) : m_food(FOOD_RADIUS) {
  m_food.setFillColor(FOOD_COLOR);
  m_food.setPosition(pos);
}

void Food::draw(sf::RenderWindow &window) { window.draw(m_food); }

void Food::setPosition(sf::Vector2f &pos) { m_food.setPosition(pos); }
