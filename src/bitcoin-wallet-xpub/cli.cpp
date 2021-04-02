#include <iostream>
#include <ncurses.h>
#include <vector>
#include <unistd.h>
#include "cli.hh"

using namespace std;

void Cli::renderWindow()
{
    for (int i = 0; i < window_width - 1; ++i)
    {
        move(0, i);
        if (i == 0 || i == (window_width - 2))
        {
            addch('+');
        }
        else
        {
            addch('-');
        }
    }

    for (int i = 1; i < window_height - 1; ++i)
    {
        move(i, 0);
        if (i == (window_height - 2))
        {
            addch('+');
        }
        else
        {
            addch('|');
        }
    }

    for (int i = 0; i < window_width - 1; ++i)
    {
        move(window_height - 2, i);
        if (i == window_width - 2 || i == 0)
        {
            addch('+');
        }
        else
        {
            addch('-');
        }
    }

    for (int i = 1; i < window_height - 1; ++i)
    {
        move(i, window_width - 2);
        if (i == (window_height - 2))
        {
            addch('+');
        }
        else
        {
            addch('|');
        }
    }
}
Cli::Cli()
{
    initscr();
    nodelay(stdscr, true); // para a snake não parar
    keypad(stdscr, true);  // KEY_...,
    noecho();              // para não exibir teclas na tela
    curs_set(0);           // desliga o curso

    window_width = getmaxx(stdscr);
    window_height = getmaxy(stdscr);

    m_delay = 100000;
    renderWindow();
    move((window_height / 2), (window_width / 2) - 10);
    printw("WALLET XPUB");
}

Cli::~Cli()
{
    nodelay(stdscr, false);
    getch();
    endwin();
}
void Cli::start()
{
    while (true)
    {
        refresh();
        usleep(m_delay);
    }
}
