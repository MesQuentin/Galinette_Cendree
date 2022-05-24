#include "board.h"
#include "interface.h"

int main()
{
    // Initialisation
    srand(time(NULL));
    Game game = {17, {10, 7, {}}, {}, false};

    // First draw : who goes first
    show_start();
    game            = add_player(game);
    int player_turn = decide_order();

    // Add random shelter on the board
    game = add_shelter(game);

    int nb_turn = 2;

    while (!game.is_finished) {
        show_info(game.player[player_turn]);
        draw_board(game.board);
        game.board = turn_position(game.board);

        std::cout << std::endl
                  << std::endl;

        player_turn      = go_to_next_turn(player_turn);
        game.is_finished = is_game_finished(nb_turn);
        nb_turn--;
    }

    show_end();
    return 0;
}