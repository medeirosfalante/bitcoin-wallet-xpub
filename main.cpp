#include <iostream>
#include <ncurses.h>
#include <vector>
#include <unistd.h>
#include "src/bitcoin-wallet-xpub/cli.hh"

using namespace std;

int main(int argc, char **argv)
{
    Cli s;
    s.start();

    return 0;
}