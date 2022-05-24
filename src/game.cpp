#include "game.h"

Game add_player(Game game)
{
    std::string name;
    std::cout << " Entrez le nom du premier joueur : " << std::endl;
    std::cin >> name;
    Hunter player1 = {name};
    game.player.push_back(player1);
    std::cout << std::endl
              << std::endl;

    std::cout << " Entrez le nom du second joueur : " << std::endl;
    std::cin >> name;
    Hunter player2 = {name};
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

int decide_order()
{
    int turn;
    if (bernouilli(0.5)) {
        turn = 0;
    }
    else {
        turn = 1;
    }

    return turn;
}

int go_to_next_turn(int turn)
{
    if (turn == 0) {
        return turn + 1;
    }
    return turn - 1;
}

std::vector<Shelter> destroy_shelter(std::vector<Shelter> shelter_list, std::vector<int> entry)
{
    std::vector<Shelter> copycat;
    for (const Shelter& shelter : shelter_list) {
        if (shelter.x != entry[0] && shelter.y != entry[1]) {
            copycat.push_back(shelter);
        }
    }
    return copycat;
}

bool is_game_finished(int nb_turn)
{
    if (nb_turn == 0) {
        return true;
    }
    return false;
}