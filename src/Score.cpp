/**
 * @file
 * @author Oliver Dixon
 * @date 24 June 2024
 */

#include "Score.h"

Score::Score(const sf::Font &font, const sf::Vector2f& position):
        IUpdatable<unsigned int>(0) {

    shape.setPosition(position);
    shape.setFont(font);

    shape.setString(std::to_string(initial_state));
}

auto Score::update([[maybe_unused]] float delta) -> void {
    shape.setString(std::to_string(score));
}

auto Score::increment_score() -> void {
    score++;
}

auto Score::set_state(const unsigned int& state) -> void {
    score = state;
}
