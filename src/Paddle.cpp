/**
 * @file
 * @author Oliver Dixon
 * @date 23 June 2024
 */

#include "Paddle.h"

Paddle::Paddle(const float x_pos, const float y_pos):

        IDrawable<sf::RectangleShape>(sf::Vector2(WIDTH, HEIGHT)),
        IAnimatable<float, sf::Vector2f>(0, sf::Vector2f(x_pos, y_pos)) {

    shape.setFillColor(COLOUR);

    if (initial_state.x != 0)
        initial_state.x -= WIDTH;

    if (initial_state.y != 0)
        initial_state.y -= HEIGHT / 2;

    IAnimatable::reset();
}

void Paddle::move_up() {
    velocity = -SPEED;
}

void Paddle::move_down() {
    velocity = SPEED;
}

void Paddle::move_stop() {
    velocity = 0.0f;
}

void Paddle::update(float delta) {
    shape.move(0, velocity * delta);
}

const sf::Vector2f& Paddle::getSize() const {
    return shape.getSize();
}

const sf::Vector2f& Paddle::getPosition() const {
    return shape.getPosition();
}

void Paddle::set_state(const sf::Vector2f &state) {
    shape.setPosition(state);
}
