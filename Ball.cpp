/**
 * @file
 * @author Oliver Dixon
 * @date 23 June 2022
 */

#include "Ball.h"

Ball::Ball(sf::Vector2f initial_centroid_position):
        shape(RADIUS),
        random_number_generator(std::random_device{}()),
        uniform_distribution(-100, 100) {

    shape.setFillColor(COLOUR);

    initial_centroid_position.x -= RADIUS;
    initial_centroid_position.y -= RADIUS;

    shape.setPosition(initial_centroid_position);
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape, states);
}

void Ball::draw(sf::RenderTarget &target) const {
    target.draw(shape, sf::RenderStates::Default);
}

void Ball::move(float delta) {
    shape.move(velocity * delta);
}

float Ball::generate_random_angle() {
    return static_cast<float>(uniform_distribution(random_number_generator));
}

void Ball::bounce_x() {
    velocity.x = -velocity.x;
    velocity.y = generate_random_angle();
}

void Ball::bounce_y() {
    velocity.y = -velocity.y;
}

const sf::Vector2f& Ball::getSize() const {
    static const sf::Vector2f radius_cache {RADIUS * 2, RADIUS * 2};
    return radius_cache;
}

const sf::Vector2f& Ball::getPosition() const {
    return shape.getPosition();
}
