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
     * @param position The fixed position of the Wall
     * @param size The fixed size of the Wall
     */
    explicit Wall(const sf::Vector2f& position, const sf::Vector2f& size);
};

#endif //PONG_WALL_H
