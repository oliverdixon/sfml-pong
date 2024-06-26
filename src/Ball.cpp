/**
 * @file
 * @author Oliver Dixon
 * @date 23 June 2024
 */

#include "Ball.h"

Ball::Ball(const sf::Vector2f& initial_position):
        IAnimatable<sf::Vector2f, sf::Vector2f, sf::CircleShape>(INITIAL_VELOCITY, initial_position, RADIUS),
        random_number_generator(std::random_device{}()),
        uniform_distribution(MINIMUM_RANDOM_REFLECTION_ANGLE, MAXIMUM_RANDOM_REFLECTION_ANGLE) {

    shape.setFillColor(COLOUR);
    IAnimatable::reset();
}

auto Ball::generate_random_angle() -> float {
    return static_cast<float>(uniform_distribution(random_number_generator));
}

auto Ball::bounce_x() -> void {
    velocity.x = -velocity.x * BOUNCE_X_VELOCITY_FACTOR;
    velocity.y = generate_random_angle();
}

auto Ball::bounce_y() -> void {
    velocity.y = -velocity.y;
}

auto Ball::getSize() const -> const sf::Vector2f& {
    static const sf::Vector2f radius_cache {RADIUS * 2, RADIUS * 2};
    return radius_cache;
}

auto Ball::getPosition() const -> const sf::Vector2f& {
    return shape.getPosition();
}

auto Ball::set_state(const sf::Vector2f& state) -> void {
    shape.setPosition(state);
}
