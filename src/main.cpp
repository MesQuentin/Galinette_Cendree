#include "board.h"
#include "interface.h"

int main()
{
    srand(time(NULL));
    show_start();

    Game game = {17, {10, 7, {{1, 3}}}, {}, false};

    game = add_shelter(game);
    game = add_player(game);

    // while (!game.is_finished) {
    std::cout << game.player[0].name;
    show_info(game.player[0]);
    draw_board(game.board);
    std::cout << std::endl
              << std::endl;
    // }

    // show_end();
    return 0;
}