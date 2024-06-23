/**
 * @file
 * @author Oliver Dixon
 * @date 23 June 2022
 */

#include "Wall.h"

const sf::Vector2f& Wall::getPosition() const {
    return position;
}

const sf::Vector2f& Wall::getSize() const {
    return size;
}

Wall::Wall(const sf::Vector2f& position, const sf::Vector2f& size):
        position(position),
        size(size) { }
