//
// Created by owd on 18/06/24.
//

#ifndef PONG_BALL_H
#define PONG_BALL_H

#include <SFML/Graphics.hpp>
#include <random>

#include "IMoveable.h"
#include "ICollideable.h"

class Ball: public sf::Drawable, public IMoveable, public ICollideable {
private:
    static constexpr float RADIUS{10};
    static constexpr float SPEED{300};
    static constexpr sf::Color& COLOUR = const_cast<sf::Color &>(sf::Color::White);

    sf::Vector2f velocity{-SPEED, 0};
    sf::CircleShape shape;

    std::mt19937 random_number_generator;
    std::uniform_int_distribution<int> uniform_distribution;

    float generate_random_angle();

protected:
    const sf::Vector2f& getSize() const override;
    const sf::Vector2f& getPosition() const override;

public:
    explicit Ball(sf::Vector2f initial_centroid_position);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void draw(sf::RenderTarget& target) const;

    void move(float delta) override;
    void bounce_x();
    void bounce_y();
};

#endif //PONG_BALL_H
