#pragma once

class invaders_game{
public:
    bool ended() const { return has_quit; }
    void quit() { has_quit = true; }
    inline float get_ship_x() const { return ship_x; }
    void move_left() { 
        ship_x -= 0.025; 
        if (ship_x < 0) {
            ship_x = 0;
        }
    }
    void move_right() { 
        ship_x += 0.025; 
        if (ship_x > 1) {
            ship_x = 1;
        }
    }
    void fire() {}

private:
    bool has_quit{false};
    float ship_x{0.5};
};