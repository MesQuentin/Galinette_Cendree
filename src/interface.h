#pragma once

#include <functional>
#include "game.h"

template<typename T>

T get_input_from_user()
{
    T choice;
    while (!(std::cin >> choice)) {
        std::cin.clear();
        std::cout << "*Ce n'est pas vraiment ce qu'on vous a demandé." << std::endl;
        std::cout << "Invalid Input*\n\n";
        break;
    }

    return choice;
}

void  show_info(Hunter hunter);
void  show_start();
void  show_end();
Board turn_position(Board board);
Board turn_action(Board board, std::vector<int> entry);
