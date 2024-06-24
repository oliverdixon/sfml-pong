/**
 * @file
 * @author Oliver Dixon
 * @date 23 June 2022
 */

#include "Paddle.h"

Paddle::Paddle(sf::Vector2f initial_centroid_position):
        IDrawable<sf::RectangleShape>(sf::Vector2(WIDTH, HEIGHT)) {

    shape.setFillColor(COLOUR);

    if (initial_centroid_position.x != 0)
        initial_centroid_position.x -= WIDTH;

    if (initial_centroid_position.y != 0)
        initial_centroid_position.y -= HEIGHT / 2;

    shape.setPosition(initial_centroid_position);
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

void Paddle::move(float delta) {
    shape.move(0, velocity * delta);
}

const sf::Vector2f& Paddle::getSize() const {
    return shape.getSize();
}

const sf::Vector2f& Paddle::getPosition() const {
    return shape.getPosition();
}

