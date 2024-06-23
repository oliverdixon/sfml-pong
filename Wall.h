//
// Created by owd on 23/06/24.
//

#ifndef PONG_WALL_H
#define PONG_WALL_H

#include "ICollideable.h"

class Wall: public ICollideable {
private:
    sf::Vector2f size;
    sf::Vector2f position;

protected:
    [[nodiscard]] const sf::Vector2f& getSize() const override;
    [[nodiscard]] const sf::Vector2f& getPosition() const override;

public:
    explicit Wall(const sf::Vector2f& position, const sf::Vector2f& size);
};


#endif //PONG_WALL_H
