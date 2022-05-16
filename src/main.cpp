#include "board.h"

int main()
{
    Board board = {9, {{2, 3}}};
    auto  ctx   = p6::Context{{800, 800, "La Galinette Cendrée"}};
    ctx.update  = [&]() {
        draw_board(board, ctx);
    };
    ctx.start();
}