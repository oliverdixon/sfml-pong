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
#include "IDrawable.h"
#include "IAnimatable.h"

/**
 * The on-screen Ball should be bounced by the paddles of players, and used to increment the scores of opponents.
 */
class Ball:
        public IDrawable<sf::CircleShape>,
        public IAnimatable<sf::Vector2f, sf::Vector2f>,
        public ICollideable {
public:
    /**
     * Creates the Ball with an initial centroid position, typically the centre of the screen.
     *
     * @param x_pos The initial X position of the Ball
     * @param y_pos The initial Y position of the Ball
     */
    explicit Ball(float x_pos, float y_pos);

    /**
     * Bounce on the X axis, according to a random angle on the Y.
     */
    void bounce_x();

    /**
     * Bounce on the Y axis only
     */
    void bounce_y();

    void update(float delta) override;

private:
    static constexpr float RADIUS{10};
    static constexpr float SPEED{300};
    static constexpr const sf::Color& COLOUR = sf::Color::White;

    std::mt19937 random_number_generator;
    std::uniform_int_distribution<int> uniform_distribution;

    /**
     * Generate a random angle of reflection for the bounce animation.
     *
     * @return The randomly generated angle, in degrees.
     */
    float generate_random_angle();

    const sf::Vector2f& getSize() const override;
    const sf::Vector2f& getPosition() const override;
    void set_state(const sf::Vector2f& state) override;
};

#endif //PONG_BALL_H
