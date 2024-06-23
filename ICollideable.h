//
// Created by owd on 18/06/24.
//

#ifndef PONG_ICOLLIDEABLE_H
#define PONG_ICOLLIDEABLE_H

#include <SFML/System/Vector2.hpp>

class ICollideable {
public:
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
    [[nodiscard]] virtual const sf::Vector2f& getSize() const = 0;
    [[nodiscard]] virtual const sf::Vector2f& getPosition() const = 0;
};

#endif //PONG_ICOLLIDEABLE_H
