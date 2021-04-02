#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <iostream>
#include <ncurses.h>
#include <vector>
#include <unistd.h>

using namespace std;

class Cli
{
protected:
    int window_width;
    int window_height;
    int m_delay;

private:
    void renderWindow();

public:
    Cli();
    ~Cli();
    void start();
};

#endif