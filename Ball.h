/**
 * @file
 * @author Oliver Dixon
 * @date 23 June 2022
 */

#ifndef PONG_BALL_H
#define PONG_BALL_H

#include <SFML/Graphics.hpp>
#include <random>

#include "IMovable.h"
#include "ICollideable.h"
#include "IDrawable.h"

/**
 * The on-screen Ball should be bounced by the paddles of players, and used to increment the scores of opponents.
 */
class Ball: public IDrawable<sf::CircleShape>, public IMovable, public ICollideable {
private:
    static constexpr float RADIUS{10};
    static constexpr float SPEED{300};
    static constexpr const sf::Color& COLOUR = sf::Color::White;

    sf::Vector2f velocity{-SPEED, 0};

    std::mt19937 random_number_generator;
    std::uniform_int_distribution<int> uniform_distribution;

    /**
     * Generate a random angle of reflection for the bounce animation.
     *
     * @return The randomly generated angle, in degrees.
     */
    float generate_random_angle();

protected:
    const sf::Vector2f& getSize() const override;
    const sf::Vector2f& getPosition() const override;

public:
    /**
     * Creates the Ball with an initial centroid position, typically the centre of the screen.
     *
     * @param initial_centroid_position The position defining the initial central point of the Ball
     */
    explicit Ball(sf::Vector2f initial_centroid_position);

    /**
     * Bounce on the X axis, according to a random angle on the Y.
     */
    void bounce_x();

    /**
     * Bounce on the Y axis only
     */
    void bounce_y();

    void move(float delta) override;
};

#endif //PONG_BALL_H
