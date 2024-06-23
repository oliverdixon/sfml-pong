/**
 * @file
 * @author Oliver Dixon
 * @date 23 June 2022
 */

#ifndef PONG_PADDLE_H
#define PONG_PADDLE_H

#include <SFML/Graphics.hpp>
#include "IMovable.h"
#include "ICollideable.h"
#include "Ball.h"

/**
 * A player-controlled paddle, movable along the Y axis, used to deflect the ball.
 */
class Paddle: public sf::Drawable, public IMovable, public ICollideable {
private:
    static constexpr float WIDTH{25};
    static constexpr float HEIGHT{WIDTH * 4};
    static constexpr float SPEED{600};
    static constexpr const sf::Color& COLOUR = sf::Color::White;

    float velocity = 0.0f;
    sf::RectangleShape shape;

protected:
    const sf::Vector2f& getSize() const override;
    const sf::Vector2f& getPosition() const override;

public:
    /**
     * Creates a Paddle with an initial centroid position, typically an extreme-centre of the screen.
     *
     * @param initial_centroid_position The position defining the initial central point of the Paddle
     */
    explicit Paddle(sf::Vector2f initial_centroid_position);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void draw(sf::RenderTarget& target) const;

    /**
     * Queue a move-up animation for the Paddle
     */
    void move_up();

    /**
     * Queue a move-down animation for the Paddle
     */
    void move_down();

    /**
     * Stop any queued animation
     */
    void move_stop();

    void move(float delta) override;
};

#endif //PONG_PADDLE_H
