#include "Piece.h"

Piece::Piece(Cell pos)
    :pos{ pos } {
    srand(time(0));
    type = static_cast<piece_type>(rand() % 7);

    if (type == t_piece)
        body = { pos, pos.shift_copy(1, 0), pos.shift_copy(-1, 0), pos.shift_copy(0, 1) };
    else if (type == i_piece)
        body = { pos, pos.shift_copy(0, -1), pos.shift_copy(0, 1), pos.shift_copy(0, 2) };
    else if (type == o_piece)
        body = { pos, pos.shift_copy(0, 1), pos.shift_copy(1, 0), pos.shift_copy(1, 1) };
    else if (type == l_piece)
        body = { pos, pos.shift_copy(0, 1), pos.shift_copy(0, -1), pos.shift_copy(1, -1) };
    else if (type == j_piece)
        body = { pos, pos.shift_copy(-1, 0), pos.shift_copy(0, 1), pos.shift_copy(0, 2) };
    else if (type == s_piece)
        body = { pos, pos.shift_copy(-1, 0), pos.shift_copy(0, 1), pos.shift_copy(1, 1) };
    else if (type == z_piece)
        body = { pos, pos.shift_copy(1, 0), pos.shift_copy(0, 1), pos.shift_copy(-1, 1) };
}

void Piece::fall_down() {
    pos.move(0, -1);
    for (auto& point : body)
        point.move(0, -1);
}

std::vector<Cell> Piece::next_fall_down_body() {
    std::vector<Cell> next_body;
    for (const auto& point : body)
        next_body.push_back(point.shift_copy(0, -1));
    return next_body;
}

void Piece::move(enum move_direction dir) {
    pos.move(dir, 0);
    for (auto& point : body)
        point.move(dir, 0);
}

std::vector<Cell> Piece::next_move_body(enum move_direction dir) {
    std::vector<Cell> next_body;
    for (const auto& point : body)
        next_body.push_back(point.shift_copy(dir, 0));
    return next_body;
}

void Piece::rotate() {
    for (auto& point : body) {
        int point_x = point.get_x() - pos.get_x();
        int point_y = point.get_y() - pos.get_y();
        point.set_coordinate((-1 * point_y) + pos.get_x(), point_x + pos.get_y());
    }
}

std::vector<Cell> Piece::next_rotate_body() {
    std::vector<Cell> next_body;
    for (const auto& point : body) {
        int point_x = point.get_x() - pos.get_x();
        int point_y = point.get_y() - pos.get_y();
        next_body.push_back(Cell((-1 * point_y) + pos.get_x(), point_x + pos.get_y()));
    }
    return next_body;
}