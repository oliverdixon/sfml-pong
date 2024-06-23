//
// Created by owd on 18/06/24.
//

#ifndef PONG_PADDLE_H
#define PONG_PADDLE_H

#include <SFML/Graphics.hpp>
#include "IMoveable.h"
#include "ICollideable.h"
#include "Ball.h"

class Paddle: public sf::Drawable, public IMoveable, public ICollideable {
private:
    static constexpr float WIDTH{25};
    static constexpr float HEIGHT{WIDTH * 4};
    static constexpr float SPEED{600};
    static constexpr sf::Color& COLOUR = const_cast<sf::Color &>(sf::Color::White);

    float velocity = 0.0f;
    sf::RectangleShape shape;

protected:
    const sf::Vector2f& getSize() const override;
    const sf::Vector2f& getPosition() const override;

public:
    explicit Paddle(sf::Vector2f initial_centroid_position);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void draw(sf::RenderTarget& target) const;

    void move_up();
    void move_down();
    void move_stop();

    void move(float delta) override;
};

#endif //PONG_PADDLE_H
