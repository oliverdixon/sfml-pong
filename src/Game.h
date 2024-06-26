/**
 * @file
 * @author Oliver Dixon
 * @date 23 June 2024
 */

#ifndef PONG_GAME_H
#define PONG_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Paddle.h"
#include "Ball.h"
#include "Score.h"
#include "Wall.h"

/**
 * The Game encapsulates the entire playing experience, including the SFML window and event handler, and all on-screen
 * objects. Once the Game is constructed, it will be played.
 */
class Game {
public:
    /**
     * Create the game window and begin the game loop, event listeners, and renderers.
     */
    Game();

private:
    static constexpr int WINDOW_WIDTH = 800;
    static constexpr int WINDOW_HEIGHT = 600;
    static constexpr std::string_view WINDOW_TITLE{"Pong @ LBU!"};

    sf::RenderWindow window;
    sf::Clock clock;
    sf::Font font;

    Paddle left_paddle;
    Paddle right_paddle;

    Score left_score;
    Score right_score;

    Ball ball;

    Wall top_wall;
    Wall bottom_wall;
    Wall left_wall;
    Wall right_wall;

    /**
     * Initialises the game loop
     */
    auto game_loop() -> void;

    /**
     * Handles a single pressed key being released
     *
     * @param keycode The released key
     */
    auto handle_key_released(sf::Keyboard::Key keycode) -> void;

    /**
     * Handles a single key being depressed
     *
     * @param keycode The depressed key
     */
    auto handle_key_depressed(sf::Keyboard::Key keycode) -> void;

    /**
     * Handles a generic event
     *
     * @param event The event, likely at the head of the SFML event queue.
     */
    auto handle_event(const sf::Event& event) -> void;

    /**
     * Resets all sprites (Animatables) to their initial positions
     */
    auto reset_sprites() -> void;
};

#endif //PONG_GAME_H
