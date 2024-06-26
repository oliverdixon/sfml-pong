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

Wall::Wall(const sf::Vector2f& position, const sf::Vector2f& size): // NOLINT(*-easily-swappable-parameters)
        position(position),
        size(size) { }
