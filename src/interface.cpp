#include "interface.h"
#include <map>

void show_info(Hunter hunter, bool past)
{
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << " LE JEU DE LA GALINETTE CENDREE" << std::endl;
    std::cout << std::endl;
    std::cout << hunter.name << ", c'est a ton tour !" << std::endl;
    if (!past) {
        std::cout << " Un coup de feu a retenti ! " << std::endl;
    }
    std::cout << std::endl;
}

void show_start()
{
    std::cout << std::endl;
    std::cout << "Bienvenue" << std::endl;
    std::cout << std::endl;
}

void show_end()
{
    std::cout << std::endl;
    std::cout << " Youhou" << std::endl;
    std::cout << std::endl;
}

int letter_to_int(char x)
{
    if (int(x) - 64 <= 0) {
        return int(x) - 48;
    }
    return int(x) - 64;
};

Board turn_position(Board board)
{
    bool             quit = false;
    std::vector<int> entry;

    while (!quit) {
        if (entry.empty()) {
            std::cout << " Ou souhaites-tu te rendre ? (Tape les coordonnees comme ci-suit : A5) " << std::endl;
            std::cout << std::endl;
        }

        const auto choice = get_input_from_user<char>();

        int int_choice = letter_to_int(choice);

        entry.push_back(int_choice);

        if (entry.size() == 2) {
            if (std::any_of(board.shelter_list.begin(), board.shelter_list.end(), [entry](Shelter shelter) { return shelter.x == entry[0] && shelter.y == entry[1]; })) {
                board = turn_action(board, entry);
                quit  = true;
            }
            else {
                std::cout << entry[0] << " " << entry[1] << std::endl;
                entry = {};
                std::cout << " Il n'y a pas de refuge a cet endroit " << std::endl
                          << std::endl;
            }
        }
    }

    std::cout << std::endl;
    return board;
}

Board turn_action(Board board, std::vector<int> entry)
{
    std::cout << " Que faire ? " << std::endl;
    std::cout << " 1. Fouiller" << std::endl;
    std::cout << " 2. Tirer" << std::endl;

    const auto choice = get_input_from_user<char>();
    std::cout << std::endl;

    switch (choice) {
    case '1':
        std::cout << "Bim" << std::endl;
        // get_info();
        std::cout << std::endl;
        break;

    case '2':
        board.shelter_list = destroy_shelter(board.shelter_list, entry);
        std::cout << std::endl;

        break;
    }
    return board;
}