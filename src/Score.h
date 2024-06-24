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
     * @param position The fixed position of the onscreen text.
     */
    Score(const sf::Font& font, sf::Vector2f position);

    /**
     * Increments the score by a single point
     */
    void increment_score();

    void update([[maybe_unused]] float delta) override;

private:
    unsigned int score{};

    void set_state(const unsigned int& state) override;
};

#endif //PONG_SCORE_H
