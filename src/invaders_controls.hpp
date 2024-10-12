#pragma once
#include <unordered_map>
#include <ncurses.h>

enum class control_code {
    nothing,
    quit
};

class invaders_controls {
public:
    invaders_controls() {
        raw(), noecho(), nodelay(stdscr, true);
        keyboard_map['q'] = 
            keyboard_map['Q'] = control_code::quit;
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
