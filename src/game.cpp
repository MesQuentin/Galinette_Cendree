#include "game.h"

Game add_player(Game game)
{
    std::string name;
    std::cout << " Entrez le nom du premier joueur : " << std::endl;
    std::cin >> name;
    Hunter player1 = {name, 0, false};
    game.player.push_back(player1);
    std::cout << std::endl
              << std::endl;

    std::cout << " Entrez le nom du second joueur : " << std::endl;
    std::cin >> name;
    Hunter player2 = {name, 0, false};
    game.player.push_back(player2);
    std::cout << std::endl;

    return game;
}

Game add_shelter(Game game)
{
    Shelter new_shelter;
    for (int k = 0; k < game.nb_shelter; k++) {
        new_shelter.x = rand() % game.board.width + 1;
        new_shelter.y = rand() % game.board.height + 1;

        if (std::any_of(game.board.shelter_list.begin(), game.board.shelter_list.end(), [new_shelter](Shelter shelter) { return shelter.x == new_shelter.x && shelter.y == new_shelter.y; })) {
            k--;
        }
        else {
            game.board.shelter_list.push_back(new_shelter);
        }
    }

    return game;
}