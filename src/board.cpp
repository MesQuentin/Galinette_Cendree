#include "board.h"

bool is_shelter(Board board, int x, int y)
{
    return (std::any_of(board.shelter_list.begin(), board.shelter_list.end(), [x, y](Shelter shelter) { return shelter.x == x && shelter.y == y; }));
}

void draw_board(Board board, p6::Context& ctx)
{
    // Basic line to define the visual of the board
    ctx.background({0.7, 0.5, 0.2});
    ctx.stroke_weight = 0.01f;
    ctx.stroke        = {0, 0, 0, 1};
    ctx.fill          = {0.f, 0.f, 0.f, 0};

    for (int x = 0; x < board.size; ++x) {
        for (int y = 0; y < board.size; ++y) {
            ctx.fill = {0.f, 0.f, 0.f, 0};
            ctx.square(p6::BottomLeftCorner{p6::map(glm::vec2{static_cast<float>(x), static_cast<float>(y)},
                                                    glm::vec2{0.f}, glm::vec2{static_cast<float>(board.size)},
                                                    glm::vec2{-1.f}, glm::vec2{1.f})},
                       p6::Radius{1.f / static_cast<float>(board.size)});

            if (is_shelter(board, x, y)) {
                ctx.fill = {0.5f, 0.5f, 0.5f, 0.5};
                // ctx.circle(p6::Center{{x + board.size / 2, y + board.size / 2}},
                //            p6::Radius{1.f / static_cast<float>(board.size)});
            }
        }
    }
}
