#pragma once

class invaders_game{
public:
    bool ended() const { return has_quit; }
    void quit() { has_quit = true; }
private:
    bool has_quit{false};
};