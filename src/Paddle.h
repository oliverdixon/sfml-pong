/**
 * @file
 * @author Oliver Dixon
 * @date 23 June 2024
 */

#ifndef PONG_PADDLE_H
#define PONG_PADDLE_H

#include <SFML/Graphics.hpp>

#include "IAnimatable.h"
#include "Ball.h"
#include "ICollideable.h"

/**
 * A player-controlled paddle, movable along the Y axis, used to deflect the ball.
 */
class Paddle:
        public IDrawable<sf::RectangleShape>,
        public IAnimatable<float, sf::Vector2f>,
        public ICollideable {
public:
    /**
     * Creates a Paddle with an initial centroid position, typically an extreme-centre of the screen.
     *
     * @param initial_position The initial position of the Paddle.
     */
    explicit Paddle(const sf::Vector2f& initial_position);

    /**
     * Queue an update-up animation for the Paddle
     */
    auto move_up() -> void;

    /**
     * Queue an update-down animation for the Paddle
     */
    auto move_down() -> void;

    /**
     * Stop any queued animation
     */
    auto move_stop() -> void;

    auto update(float delta) -> void override;

private:
    static constexpr float WIDTH{25};
    static constexpr float HEIGHT{WIDTH * 4};
    static constexpr float SPEED{600};
    static constexpr const sf::Color& COLOUR = sf::Color::White;

    auto getSize() const -> const sf::Vector2f& override;
    auto getPosition() const -> const sf::Vector2f& override;
    auto set_state(const sf::Vector2f& state) -> void override;
};

#endif //PONG_PADDLE_H
