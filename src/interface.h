#pragma once

#include <functional>
#include "game.h"

template<typename T>

T get_input_from_user()
{
    T choice;
    while (!(std::cin >> choice)) {
        std::cin.clear();
        std::cout << "*This ... is not really what was asked of you." << std::endl;
        std::cout << "The old man waits for your next answer with hope (Invalid Input)*\n\n";
        break;
    }

    return choice;
}

inline int letter_to_int(char x)
{
    return int(x) - 96;
};

void show_info(Hunter hunter);
void show_start();
void show_end();
void get_coord();
void show_menu();
