#pragma once
#include <array>
#include <ncurses.h>
#include "invaders_game.hpp"

class invaders_screen {
    using row_t = std::array<char, 80>;
    std::array<row_t, 25> buffer;
public:
    invaders_screen() {
        initscr();
        for (auto &row: buffer) {
            for (auto &c: row) {
                c = 'x';
            }
        }
    }
    ~invaders_screen() {
        endwin();
    }
    void render(invaders_game const &game) {
        int y{0};
        for (auto const &row: buffer) {
            mvaddnstr(++y, 0, &row[0], row.size());
        }
        refresh();
    }
};
