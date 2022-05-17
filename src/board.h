#include <p6/p6.h>
#include <iostream>

struct Shelter {
    int x;
    int y;
};

struct Board {
    int                  size = 9;
    std::vector<Shelter> shelter_list;
};

void draw_board(Board board);
