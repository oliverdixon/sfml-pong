/**
 * @file
 * @author Oliver Dixon
 * @date 23 June 2022
 */

#ifndef PONG_ICOLLIDEABLE_H
#define PONG_ICOLLIDEABLE_H

#include <SFML/System/Vector2.hpp>

/**
 * An ICollideable may be used as a source or target for standardised collision-detection of two-dimensional
 * rectangle-like objects.
 */
class ICollideable {
public:
    /**
     * Determines if two collideable objects are colliding, including any boundary/edge collisions.
     *
     * @param candidate The collideable object against which to test for a collision.
     * @return Are the objects colliding?
     */
    [[nodiscard]] virtual bool isColliding(const ICollideable& candidate) const {
        const sf::Vector2f& size = getSize();
        const sf::Vector2f& position = getPosition();
        const sf::Vector2f& candidate_size = candidate.getSize();
        const sf::Vector2f& candidate_position = candidate.getPosition();
        
        return (position.x <= candidate_position.x + candidate_size.x) &&
               (position.x + size.x >= candidate_position.x) &&
               (position.y <= candidate_position.y + candidate_size.y) &&
               (position.y + size.y >= candidate_position.y);
    }

protected:
    /**
     * Retrieves the read-only size of the collideable object.
     *
     * @return The size of the object
     */
    [[nodiscard]] virtual const sf::Vector2f& getSize() const = 0;

    /**
     * Retrieves the current position, anchored on the top-left, of the collideable object.
     *
     * @return The position of the object
     */
    [[nodiscard]] virtual const sf::Vector2f& getPosition() const = 0;
};

#endif //PONG_ICOLLIDEABLE_H
