/**
 * @file
 * @author Oliver Dixon
 * @date 24 June 2024
 */

#ifndef PONG_SCORE_H
#define PONG_SCORE_H

#include "IDrawable.h"
#include "IUpdatable.h"

/**
 * A Score encodes the integral score of a player, with facilities for rendering the score w.r.t. a given font and SFML
 * rendering surface, incrementing, and resetting.
 */
class Score:
        public IDrawable<sf::Text>,
        public IUpdatable<unsigned int> {
public:
    /**
     * Instantiates a Score to be rendered with the given font, at the given position.
     *
     * @param font The SFML font to be used for rendering the numerical score.
     * @param position The fixed position of the label.
     */
    Score(const sf::Font& font, const sf::Vector2f& position);

    /**
     * Increments the score by a single point
     */
    auto increment_score() -> void;

    auto update([[maybe_unused]] float delta) -> void override;

private:
    unsigned int score{};

    auto set_state(const unsigned int& state) -> void override;
};

#endif //PONG_SCORE_H
