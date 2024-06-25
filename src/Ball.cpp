/**
 * @file
 * @author Oliver Dixon
 * @date 23 June 2024
 */

#include "Ball.h"

Ball::Ball(const float x_pos, const float y_pos):

        IDrawable<sf::CircleShape>(RADIUS),
        random_number_generator(std::random_device{}()),
        IAnimatable<sf::Vector2f, sf::Vector2f>(sf::Vector2f(-SPEED, 0),
                                                sf::Vector2f(x_pos, y_pos)),
        uniform_distribution(-MINIMUM_RANDOM_REFLECTION_ANGLE, MAXIMUM_RANDOM_REFLECTION_ANGLE) {

    shape.setFillColor(COLOUR);
    IAnimatable::reset();
}

void Ball::update(float delta) {
    shape.move(velocity * delta);
}

auto Ball::generate_random_angle() -> float {
    return static_cast<float>(uniform_distribution(random_number_generator));
}

void Ball::bounce_x() {
    velocity.x = -velocity.x;
    velocity.y = generate_random_angle();
}

void Ball::bounce_y() {
    velocity.y = -velocity.y;
}

auto Ball::getSize() const -> const sf::Vector2f& {
    static const sf::Vector2f radius_cache {RADIUS * 2, RADIUS * 2};
    return radius_cache;
}

auto Ball::getPosition() const -> const sf::Vector2f& {
    return shape.getPosition();
}

void Ball::set_state(const sf::Vector2f& state) {
    shape.setPosition(state);
}
