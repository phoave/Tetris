#if !defined(PIECE_H_)
#define PIECE_H_

#include "Cell.h"
#include <vector>
#include <stdlib.h>
#include <time.h>

enum piece_type {
    t_piece,
    i_piece,
    o_piece,
    l_piece,
    j_piece,
    s_piece,
    z_piece
};

enum move_direction {
    right = 1,
    left = -1
};

class Piece {
private:
    enum piece_type type;
    std::vector<Cell> body;
    Cell pos;


public:
    Piece() = default;
    Piece(Cell pos);
    void fall_down();
    std::vector<Cell> next_fall_down_body();
    void move(enum move_direction dir);
    std::vector<Cell> next_move_body(enum move_direction dir);
    void rotate();
    std::vector<Cell> next_rotate_body();

    std::vector<Cell> get_body() { return body; }
    void set_body(std::vector<Cell> body) { this->body = body; }

};

#endif