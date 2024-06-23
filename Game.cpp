/**
 * @file
 * @author Oliver Dixon
 * @date 23 June 2022
 */

#include "Game.h"

Game::Game():
        window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE),

        left_paddle(sf::Vector2f(0, WINDOW_HEIGHT / 2.0f)),
        right_paddle(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT / 2.0f)),

        ball(sf::Vector2f(WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f)),

        top_wall(sf::Vector2f(0, -10), sf::Vector2f(WINDOW_WIDTH, 10)),
        bottom_wall(sf::Vector2f(0, WINDOW_HEIGHT), sf::Vector2f(WINDOW_WIDTH, 10)),
        left_wall(sf::Vector2f(-10, 0), sf::Vector2f(10, WINDOW_HEIGHT)),
        right_wall(sf::Vector2f(WINDOW_WIDTH, 0), sf::Vector2f(10, WINDOW_HEIGHT)) {

    window.setFramerateLimit(0);
    window.setVerticalSyncEnabled(true);
    game_loop();
}

void Game::game_loop() {
    while (window.isOpen()) {
        sf::Event event{};

        float delta = clock.restart().asSeconds();
        while (window.pollEvent(event))
            handle_event(event);

        if (left_paddle.isColliding(ball) || right_paddle.isColliding(ball))
            ball.bounce_x();

        if (top_wall.isColliding(ball) || bottom_wall.isColliding(ball))
            ball.bounce_y();

        left_paddle.move(delta);
        right_paddle.move(delta);
        ball.move(delta);

        window.clear();

        left_paddle.draw(window);
        right_paddle.draw(window);
        ball.draw(window);

        window.display();
    }
}

void Game::handle_key_released(sf::Keyboard::Key keycode) {
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

void Game::handle_key_depressed(sf::Keyboard::Key keycode) {
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

void Game::handle_event(const sf::Event& event) {
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

/**
 * Entry point: instantiates and plays the game until the game loop terminates.
 *
 * @return The process exit status code
 */
int main() {
    Game game;
    return 0;
}
