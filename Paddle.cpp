//
// Created by owd on 18/06/24.
//

#include "Paddle.h"

Paddle::Paddle(sf::Vector2f initial_centroid_position):
        shape{sf::Vector2(WIDTH, HEIGHT)} {
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

void Paddle::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape, states);
}

void Paddle::draw(sf::RenderTarget &target) const {
    target.draw(shape, sf::RenderStates::Default);
}

const sf::Vector2f& Paddle::getSize() const {
    return shape.getSize();
}

const sf::Vector2f& Paddle::getPosition() const {
    return shape.getPosition();
}

