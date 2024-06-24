/**
 * @file
 * @author Oliver Dixon
 * @date 23 June 2024
 */

#ifndef PONG_PADDLE_H
#define PONG_PADDLE_H

#include <SFML/Graphics.hpp>

#include "IAnimatable.h"
#include "ICollideable.h"
#include "Ball.h"

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
     * @param initial_centroid_position The position defining the initial central point of the Paddle
     */
    explicit Paddle(const sf::Vector2f&& initial_centroid_position);

    /**
     * Queue an update-up animation for the Paddle
     */
    void move_up();

    /**
     * Queue an update-down animation for the Paddle
     */
    void move_down();

    /**
     * Stop any queued animation
     */
    void move_stop();

    void update(float delta) override;

private:
    static constexpr float WIDTH{25};
    static constexpr float HEIGHT{WIDTH * 4};
    static constexpr float SPEED{600};
    static constexpr const sf::Color& COLOUR = sf::Color::White;

    const sf::Vector2f& getSize() const override;
    const sf::Vector2f& getPosition() const override;
    void set_state(const sf::Vector2f& state) override;
};

#endif //PONG_PADDLE_H
