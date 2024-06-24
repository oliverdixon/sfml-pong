/**
 * @file
 * @author Oliver Dixon
 * @date 23 June 2024
 */

#include "Ball.h"

Ball::Ball(const sf::Vector2f&& initial_centroid_position):

        IDrawable<sf::CircleShape>(RADIUS),
        random_number_generator(std::random_device{}()),
        IAnimatable<sf::Vector2f, sf::Vector2f>(sf::Vector2f(-SPEED, 0),
                                                initial_centroid_position),
        uniform_distribution(-100, 100) {

    shape.setFillColor(COLOUR);
    IAnimatable::reset();
}

void Ball::update(float delta) {
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

void Ball::set_state(const sf::Vector2f& state) {
    shape.setPosition(state);
}
