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
#include "Wall.h"
#include "Score.h"

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

    Paddle left_paddle;
    Paddle right_paddle;

    sf::Font font;

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
    void game_loop();

    /**
     * Handles a single pressed key being released
     *
     * @param keycode The released key
     */
    void handle_key_released(sf::Keyboard::Key keycode);

    /**
     * Handles a single key being depressed
     *
     * @param keycode The depressed key
     */
    void handle_key_depressed(sf::Keyboard::Key keycode);

    /**
     * Handles a generic event
     *
     * @param event The event, likely at the head of the SFML event queue.
     */
    void handle_event(const sf::Event& event);

    /**
     * Resets all sprites (Animatables) to their initial positions
     */
    void reset_sprites();
};

#endif //PONG_GAME_H
