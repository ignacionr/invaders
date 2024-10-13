#pragma once
#include <array>
#include <ncurses.h>
#include "invaders_game.hpp"

class invaders_screen {
public:
    invaders_screen() {
        initscr();
        for (int i = 0; i < getmaxy(stdscr); ++i) {
            for (int j = 0; j < getmaxx(stdscr); ++j) {
                mvaddch(i, j, ' ');
            }
        }
    }
    ~invaders_screen() {
        endwin();
    }
    int get_width() const {
        return getmaxx(stdscr);
    }
    int get_height() const {
        return getmaxy(stdscr);
    }
    int game_to_screen_x(float x) const {
        return x * (get_width() - 1);
    }
    int game_to_screen_y(float y) const {
        return y * (get_height() - 1);
    }

    void draw_invader(float x, float y, int type) {
        constexpr std::array<const char*,3> invader_types {
            "▀▀▀█ █▀▀▀",
            "█▀█▄ ▄█▀█",
            "▀█▀▀▀▀█▀█"
        };
        auto screen_x = game_to_screen_x(x);
        auto screen_y = game_to_screen_y(y);
        mvaddch(screen_y-1, screen_x-1, invader_types[type][0]);
        mvaddch(screen_y-1, screen_x, invader_types[type][1]);
        mvaddch(screen_y-1, screen_x+1, invader_types[type][2]);
        mvaddch(screen_y, screen_x-1, invader_types[type][3]);
        mvaddch(screen_y, screen_x, invader_types[type][4]);
        mvaddch(screen_y, screen_x+1, invader_types[type][5]);
        mvaddch(screen_y+1, screen_x-1, invader_types[type][6]);
        mvaddch(screen_y+1, screen_x, invader_types[type][7]);
        mvaddch(screen_y+1, screen_x+1, invader_types[type][8]);
    }

    void draw_ship(float x) {
        auto screen_x = game_to_screen_x(x);
        mvaddch(get_height() - 1, screen_x, 'A');
        if (screen_x > 0) {
            mvaddch(get_height() - 1, screen_x - 1, '<');
        }
        if (screen_x < get_width() - 1) {
            mvaddch(get_height() - 1, screen_x + 1, '>');
        }
    }
    void render(invaders_game const &game) {
        int y{0};
        // clear();
        draw_invader(0.5, 0.5, 0);
        draw_ship(game.get_ship_x());
        refresh();
    }
};
