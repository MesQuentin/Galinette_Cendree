#include "board.h"

void show_info()
{
    std::cout << std::endl;
    std::cout << " GALINETTE CENDREE" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}

void start()
{
    std::cout << std::endl;
    std::cout << " Bienvenue" << std::endl;
    std::cout << std::endl;
}

void end()
{
    std::cout << std::endl;
    std::cout << " Youhou" << std::endl;
    std::cout << std::endl;
}

int main()
{
    start();

    Game game = {10, {10, 7, {{2, 3}, {1, 2}}}, {}, false};

    while (!game.is_finished) {
        show_info();
        draw_board(game.board);
        std::cout << std::endl
                  << std::endl;
    }

    end();
    return 0;
}