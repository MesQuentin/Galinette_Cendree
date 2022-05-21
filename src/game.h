#pragma once

#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "galinette.h"

struct Shelter {
    int x;
    int y;

    std::string info;
    bool        hunter   = false;
    bool        squirrel = false;
};

struct Board {
    int width;
    int height;

    std::vector<Shelter> shelter_list;
};

struct Hunter {
    std::string name;

    int  rank    = 0;
    bool has_won = false;
};

struct Galinette {
    int  x;
    int  y;
    bool is_afraid = false;
};

struct Game {
    int                 nb_shelter = 10;
    Board               board;
    std::vector<Hunter> player;
    bool                is_finished = false;
};

Game add_player(Game game);
Game add_shelter(Game game);
