#pragma once
#include <unordered_map>
#include <ncurses.h>

enum class control_code {
    nothing,
    left,
    right,
    fire,
    quit
};

class invaders_controls {
public:
    invaders_controls() {
        raw(), noecho(), nodelay(stdscr, true), keypad(stdscr, true);
        keyboard_map['q'] = 
            keyboard_map['Q'] = control_code::quit;
        keyboard_map[KEY_LEFT] = 
            keyboard_map['o'] =
            keyboard_map['O'] =
            control_code::left;
        keyboard_map[KEY_RIGHT] = 
            keyboard_map['p'] =
            keyboard_map['P'] =
            control_code::right;
        keyboard_map[' '] = control_code::fire;
    }
    control_code get() {
        auto k = getch();
        auto pos = keyboard_map.find(k);
        if (pos != keyboard_map.end()) {
            return pos->second;
        }
        return control_code::nothing;
    }
private:
    std::unordered_map<int, control_code> keyboard_map;
};
