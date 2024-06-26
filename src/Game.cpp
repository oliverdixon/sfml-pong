/**
 * @file
 * @author Oliver Dixon
 * @date 23 June 2024
 */

#include <iostream>

#include "Game.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-math-missing-parentheses"
#pragma ide diagnostic ignored "cppcoreguidelines-avoid-magic-numbers"
Game::Game():

        window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), std::string(WINDOW_TITLE)),

        left_paddle(sf::Vector2f(0, WINDOW_HEIGHT / 2.0)),
        right_paddle(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT / 2.0)),

        ball(sf::Vector2f(WINDOW_WIDTH / 2.0, WINDOW_HEIGHT / 2.0)),

        left_score(font, sf::Vector2f(WINDOW_WIDTH / 3.0 - 20, 20)),
        right_score(font, sf::Vector2f(2.0 * WINDOW_WIDTH / 3 + 20, 20)),

        top_wall(sf::Vector2f(0, -10), sf::Vector2f(WINDOW_WIDTH, 10)),
        bottom_wall(sf::Vector2f(0, WINDOW_HEIGHT), sf::Vector2f(WINDOW_WIDTH, 10)),
        left_wall(sf::Vector2f(-10, 0), sf::Vector2f(10, WINDOW_HEIGHT)),
        right_wall(sf::Vector2f(WINDOW_WIDTH, 0), sf::Vector2f(10, WINDOW_HEIGHT)) {

    window.setFramerateLimit(0);
    window.setVerticalSyncEnabled(true);

    if (!font.loadFromFile("../font.ttf"))
        throw std::runtime_error("The font file could not be loaded by SFML.");

    game_loop();
}
#pragma clang diagnostic pop

auto Game::game_loop() -> void {
    while (window.isOpen()) {
        sf::Event event{};

        float delta = clock.restart().asSeconds();
        while (window.pollEvent(event))
            handle_event(event);

        if (left_paddle.isColliding(ball) || right_paddle.isColliding(ball))
            ball.bounce_x();

        if (top_wall.isColliding(ball) || bottom_wall.isColliding(ball))
            ball.bounce_y();

        if (left_wall.isColliding(ball)) {
            right_score.increment_score();
            right_score.update(delta);
            reset_sprites();
        }

        if (right_wall.isColliding(ball)) {
            left_score.increment_score();
            left_score.update(delta);
            reset_sprites();
        }

        left_paddle.update(delta);
        right_paddle.update(delta);
        ball.update(delta);

        window.clear();

        left_paddle.draw(window);
        right_paddle.draw(window);
        ball.draw(window);
        left_score.draw(window);
        right_score.draw(window);

        window.display();
    }
}

auto Game::handle_key_released(sf::Keyboard::Key keycode) -> void {
    switch (keycode) {
        case sf::Keyboard::W:
        case sf::Keyboard::S:
            left_paddle.move_stop();
            break;

        case sf::Keyboard::Up:
        case sf::Keyboard::Down:
            right_paddle.move_stop();
            break;

        default: break;
    }
}

auto Game::handle_key_depressed(sf::Keyboard::Key keycode) -> void {
    switch (keycode) {
        case sf::Keyboard::W:
            left_paddle.move_up();
            break;
        case sf::Keyboard::S:
            left_paddle.move_down();
            break;
        case sf::Keyboard::Up:
            right_paddle.move_up();
            break;
        case sf::Keyboard::Down:
            right_paddle.move_down();
            break;

        default: break;
    }
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-pro-type-union-access"
auto Game::handle_event(const sf::Event& event) -> void {
    switch (event.type) {
        case sf::Event::Closed:
            window.close();
            break;

        case sf::Event::KeyPressed:
            handle_key_depressed(event.key.code);
            break;

        case sf::Event::KeyReleased:
            handle_key_released(event.key.code);
            break;

        default: break;
    }
}
#pragma clang diagnostic pop

auto Game::reset_sprites() -> void {
    left_paddle.reset();
    right_paddle.reset();
    ball.reset();
}

/**
 * Entry point: instantiates and plays the game until the game loop terminates.
 *
 * @return The process exit status code
 */
auto main() -> int {
    try {
        Game game;
    } catch (const std::runtime_error& exception) {
        std::cerr << "Fatal error: " << exception.what() << std::endl; // NOLINT(*-avoid-endl)
        return -1;
    }

    return 0;
}
