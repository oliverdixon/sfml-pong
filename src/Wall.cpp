/**
 * @file
 * @author Oliver Dixon
 * @date 23 June 2024
 */

#include "Wall.h"

auto Wall::getPosition() const -> const sf::Vector2f& {
    return position;
}

auto Wall::getSize() const -> const sf::Vector2f& {
    return size;
}

Wall::Wall(float x_pos, float y_pos, float width, float height):
        position(x_pos, y_pos),
        size(width, height) { }
