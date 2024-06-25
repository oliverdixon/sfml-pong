/**
 * @file
 * @author Oliver Dixon
 * @date 23 June 2024
 */

#ifndef PONG_WALL_H
#define PONG_WALL_H

#include "ICollideable.h"

/**
 * A wall represents the most basic collideable block: an immovable two-dimensional rectangle.
 */
class Wall:
        public ICollideable {
private:
    sf::Vector2f size;
    sf::Vector2f position;

    [[nodiscard]] auto getSize() const -> const sf::Vector2f& override;
    [[nodiscard]] auto getPosition() const -> const sf::Vector2f& override;

public:
    /**
     * Instantiate a new wall with the given top-left position and rectangular size.
     *
     * @param x_pos The fixed X position of the Wall
     * @param y_pos The fixed Y position of the Wall
     * @param width The fixed width of the Wall
     * @param height The fixed height of the Wall
     */
    explicit Wall(float x_pos, float y_pos, float width, float height);
};

#endif //PONG_WALL_H
