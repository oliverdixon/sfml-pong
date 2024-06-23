/**
 * @file
 * @author Oliver Dixon
 * @date 23 June 2022
 */

#ifndef PONG_WALL_H
#define PONG_WALL_H

#include "ICollideable.h"

/**
 * A wall represents the most basic collideable block: an immovable two-dimensional rectangle.
 */
class Wall: public ICollideable {
private:
    sf::Vector2f size;
    sf::Vector2f position;

protected:
    [[nodiscard]] const sf::Vector2f& getSize() const override;
    [[nodiscard]] const sf::Vector2f& getPosition() const override;

public:
    /**
     * Instantiate a new wall with the given top-left position and rectangular size.
     *
     * @param position The top-left position of the wall.
     * @param size The size of the wall.
     */
    explicit Wall(const sf::Vector2f& position, const sf::Vector2f& size);
};

#endif //PONG_WALL_H
