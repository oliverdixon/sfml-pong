/**
 * @file
 * @author Oliver Dixon
 * @date 23 June 2024
 */

#ifndef PONG_IDRAWABLE_H
#define PONG_IDRAWABLE_H

#include <SFML/Graphics.hpp>

template<typename T>
concept GenericDrawable = std::is_base_of_v<sf::Drawable, T>;

/**
 * Provides a pseudo-wrapper interface for the SFML Drawable type with sensibly defaulting draw methods, and a
 * shape object.
 *
 * @tparam ShapeType The SFML Drawable type
 */
template<GenericDrawable ShapeType>
class IDrawable {
public:
    /**
     * Create a new Drawable object
     *
     * @tparam Args The type of arguments passed to the SFML Drawable constructor
     * @param args The arguments pure-forwarded to the SFML Drawable constructor
     */
    template<typename... Args>
    explicit IDrawable(Args&& ... args): shape(std::forward<Args>(args)...) { }

    /**
     * Draw the object to the specified target
     *
     * @param target The target surface onto which the shape should be drawn
     */
    auto draw(sf::RenderTarget& target) const -> void {
        target.draw(shape, sf::RenderStates::Default);
    }

protected:
    ShapeType shape{};
};

#endif //PONG_IDRAWABLE_H
