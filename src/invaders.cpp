#include "invaders_game.hpp"
#include "invaders_screen.hpp"
#include "invaders_controls.hpp"

int main() {
    invaders_game game;
    invaders_screen screen;
    invaders_controls controls;
    while (!game.ended()) {
        auto c = controls.get();
        if (c == control_code::quit) {
            game.quit();
        }
        screen.render(game);
    }
}
