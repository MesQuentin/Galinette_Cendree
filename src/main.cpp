#include "board.h"
#include "interface.h"

int main()
{
    // Initialisation
    srand(time(NULL));
    Game game = {17, {10, 7, {}}, {}, false};

    show_start();
    game            = add_player(game);
    int player_turn = decide_order();

    // Shelter part
    game                      = add_shelter(game);
    std::vector<Shelter> past = game.board.shelter_list;

    int nb_turn = 2;

    while (!game.is_finished) {
        show_info(game.player[player_turn], past.size() != game.board.shelter_list.size());
        draw_board(game.board);
        game.board = turn_position(game.board);

        std::cout << std::endl
                  << std::endl;

        past             = game.board.shelter_list;
        player_turn      = go_to_next_turn(player_turn);
        game.is_finished = is_game_finished(nb_turn);
        nb_turn--;
    }

    show_end();
    return 0;
}