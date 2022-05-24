#include "galinette.h"

Galinette setup(std::vector<Shelter> shelter_list)
{
    Galinette galinette;
    galinette.x = shelter_list[0].x;
    galinette.y = shelter_list[0].y;

    return galinette;
}

// std::vector<Shelter> update(std::vector<Shelter> shelter_list)
// {
// }