/**
 * @file
 * @author Oliver Dixon
 * @date 23 June 2024
 */

#ifndef PONG_BALL_H
#define PONG_BALL_H

#include <SFML/Graphics.hpp>
#include <random>

#include "ICollideable.h"
#include "IAnimatable.h"
#include "IDrawable.h"

/**
 * The on-screen Ball should be bounced by the paddles of players, and used to increment the scores of opponents.
 */
class Ball:
        public IAnimatable<sf::Vector2f, sf::Vector2f, sf::CircleShape>,
        public ICollideable {
public:
    /**
     * Creates the Ball with an initial centroid position, typically the centre of the screen.
     *
     * @param initial_position The initial position of the Ball.
     */
    explicit Ball(const sf::Vector2f& initial_position);

    /**
     * Bounce on the X axis, according to a random angle on the Y.
     */
    auto bounce_x() -> void;

    /**
     * Bounce on the Y axis only
     */
    auto bounce_y() -> void;

private:
    static constexpr float RADIUS{10};
    static constexpr const sf::Color& COLOUR = sf::Color::White;
    static inline const sf::Vector2f INITIAL_VELOCITY{-300, 0}; // NOLINT(*-err58-cpp)
    static constexpr int MINIMUM_RANDOM_REFLECTION_ANGLE = -170;
    static constexpr int MAXIMUM_RANDOM_REFLECTION_ANGLE = -MINIMUM_RANDOM_REFLECTION_ANGLE;
    static constexpr float BOUNCE_X_VELOCITY_FACTOR = 1.1;

    std::mt19937 random_number_generator;
    std::uniform_int_distribution<int> uniform_distribution;

    /**
     * Generate a random angle of reflection for the bounce animation.
     *
     * @return The randomly generated angle, in degrees.
     */
    auto generate_random_angle() -> float;

    auto getSize() const -> const sf::Vector2f& override;
    auto getPosition() const -> const sf::Vector2f& override;
    auto set_state(const sf::Vector2f& state) -> void override;
};

#endif //PONG_BALL_H
