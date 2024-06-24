/**
 * @file
 * @author Oliver Dixon
 * @date 24 June 2024
 */

#include "Score.h"

Score::Score(const sf::Font &font, const float x_pos, const float y_pos):
        IUpdatable<unsigned int>(0) {

    shape.setPosition(x_pos, y_pos);
    shape.setFont(font);

    shape.setString(std::to_string(initial_state));
}

void Score::update(float delta) {
    shape.setString(std::to_string(score));
}

void Score::increment_score() {
    score++;
}

void Score::set_state(const unsigned int& state) {
    score = state;
}
