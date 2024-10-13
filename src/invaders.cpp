#include <functional>
#include <unordered_map>

#include "invaders_game.hpp"
#include "invaders_screen.hpp"
#include "invaders_controls.hpp"

int main() {
    invaders_game game;
    invaders_screen screen;
    invaders_controls controls;

    std::unordered_map<control_code, std::function<void()>> control_map {
        {control_code::left, [&] { game.move_left(); }},
        {control_code::right, [&] { game.move_right(); }},
        {control_code::fire, [&] { game.fire(); }},
        {control_code::quit, [&] { game.quit(); }}
    };

    while (!game.ended()) {
        auto c = controls.get();
        auto pos = control_map.find(c);
        if (pos != control_map.end()) {
            pos->second();
        }
        screen.render(game);
    }
}
