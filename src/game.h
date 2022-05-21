#include <string>
#include <vector>

inline int letter_to_int(char x)
{
    return int(x) - 96;
}

struct Shelter {
    int x;
    int y;

    std::string info;
    bool        hunter;
    bool        squirrel;
};

struct Board {
    int width;
    int height;

    std::vector<Shelter> shelter_list;
};

struct Hunter {
    std::string name;

    int  rank;
    bool has_won;
};

struct Galinette {
    int  x;
    int  y;
    bool is_afraid = false;
};

struct Game {
    int                 nb_shelter;
    Board               board;
    std::vector<Hunter> player;
    bool                is_finished;
};
