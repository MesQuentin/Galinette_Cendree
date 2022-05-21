#include "board.h"

void show_info()
{
    std::cout << std::endl;
    std::cout << " GALINETTE CENDREE" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}

int main()
{
    show_info();
    Board board = {10, 5, {{2, 3}, {1, 2}}};
    draw_board(board);
    std::cout << std::endl
              << std::endl;

    return 0;
}