#include "interface.h"
#include <map>

void show_info(Hunter hunter)
{
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << " LE JEU DE LA GALINETTE CENDREE" << std::endl;
    std::cout << std::endl;
    std::cout << hunter.name << ", c'est a ton tour !" << std::endl;
    // Rajouter une fonction pour associer le tour et le rang
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

void get_coord()
{
    std::cout << " Ou souhaitez-vous vous rendre ? (Taper les coordonnées comme ci-suit : A5) " << std::endl;
    std::cout << " 1. Fouiller" << std::endl;
    std::cout << " 2. Tirer" << std::endl
              << std::endl;
}

void show_menu()
{
    std::map<char, std::function> map{
        {'1', {"guess_a_number", guess_a_number()}},
        {'2', {"hangman", hangman()}},
        ,
    };

    bool quit = false;
    while (!quit) {
        command_list();
        const auto choice = get_input_from_user<char>();
        std::cout << std::endl;
        switch (choice) {
        case '1':
            guess_a_number();
            std::cout << std::endl;
            break;

        case '2':
            hangman();
            std::cout << std::endl;
            break;

        case '3':
            nought_and_crosses();
            break;

        case '4':
            Menudventure::start();
            break;

        case '5':
            std::cout << "*The old man looks at you extremely sad as you close your eyes*" << std::endl;
            std::cout << std::endl
                      << "Good night, traveler" << std::endl
                      << std::endl;
            quit = true;
        }
    }
}