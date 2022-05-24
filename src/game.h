#pragma once

#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "galinette.h"
#include "random.h"

struct Shelter {
    int x;
    int y;

    std::string info     = "";
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

// Initialisation
Game add_player(Game game);
Game add_shelter(Game game);
int  decide_order();

// Turn
std::vector<Shelter> destroy_shelter(std::vector<Shelter> shelter_list, std::vector<int> entry);

// Verification constant
bool is_game_finished(int nb_turn);
int  go_to_next_turn(int turn);