/**
 * @file
 * @author Oliver Dixon
 * @date 23 June 2024
 */

#include "Paddle.h"

Paddle::Paddle(const sf::Vector2f& initial_position):
        IAnimatable<float, sf::Vector2f, sf::RectangleShape>(0, initial_position,
                                                             sf::Vector2(WIDTH, HEIGHT)) {

    shape.setFillColor(COLOUR);

    if (initial_state.x != 0)
        initial_state.x -= WIDTH;

    if (initial_state.y != 0)
        initial_state.y -= HEIGHT / 2;

    IAnimatable::reset();
}

auto Paddle::move_up() -> void {
    velocity = -SPEED;
}

auto Paddle::move_down() -> void {
    velocity = SPEED;
}

auto Paddle::move_stop() -> void {
    velocity = 0.0;
}

auto Paddle::getSize() const -> const sf::Vector2f& {
    return shape.getSize();
}

auto Paddle::getPosition() const -> const sf::Vector2f& {
    return shape.getPosition();
}

auto Paddle::set_state(const sf::Vector2f &state) -> void {
    shape.setPosition(state);
}
