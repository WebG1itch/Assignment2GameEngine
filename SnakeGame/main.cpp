#include <SFML/Graphics.hpp>
#include "Game.h"

int main() {
    // Program entry point
    Game game; // Create the game, duh!
    while(!game.GetWindow()->isDone()) {
        // Game loop stuff :D
        game.HandleInput();
        game.Update();
        game.Render();
        game.RestartClock();
    }
}