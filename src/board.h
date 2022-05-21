#include <algorithm>
#include <iostream>
#include "game.h"

struct Shelter {
    int x;
    int y;
};

struct Board {
    int                  width;
    int                  height;
    std::vector<Shelter> shelter_list;
};

void draw_board(Board board);
