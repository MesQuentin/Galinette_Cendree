#include "board.h"
#define WHITE_SQUARE 0xDB

template<typename T>
void draw_multiple(int n, T c)
{
    for (int k = 0; k < n; k++) {
        std::cout << c;
    }
}

void draw_lines(Board board, int line)
{
    for (int column = 0; column < board.width; column++) {
        if (std::any_of(board.shelter_list.begin(), board.shelter_list.end(), [line, column](Shelter shelter) { return shelter.x == column + 1 && shelter.y == line + 1; })) {
            std::cout << "| ";
            draw_multiple(3, char(WHITE_SQUARE));
            std::cout << " ";
        }
        else {
            std::cout << "|     ";
        }
    }

    std::cout << "|        " << line + 1 << std::endl;
    draw_multiple(6 * board.width + 1, '-');
    std::cout << std::endl;
}

void draw_board(Board board)
{
    for (int column = 0; column < board.width; column++) {
        std::cout << "   " << char(column + 97) << "  ";
    }
    std::cout << std::endl
              << std::endl;

    draw_multiple(6 * board.width + 1, '-');
    std::cout << std::endl;
    for (int line = 0; line < board.height; line++) {
        draw_lines(board, line);
    }
}
