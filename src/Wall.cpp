/**
 * @file
 * @author Oliver Dixon
 * @date 23 June 2024
 */

#include "Wall.h"

const sf::Vector2f& Wall::getPosition() const {
    return position;
}

const sf::Vector2f& Wall::getSize() const {
    return size;
}

Wall::Wall(float x_pos, float y_pos, float width, float height):
        position(x_pos, y_pos),
        size(width, height) { }
