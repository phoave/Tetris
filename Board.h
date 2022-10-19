#if !defined(BOARD_H_)
#define BOARD_H_

#include "Piece.h"
#include <vector>
#include <algorithm>


class Board {
private:
    int width;
    int height;
    std::vector<Cell> all_points;
    std::vector<Cell> built_points;
public:
    Board(int width = 30, int height = 30);

    int get_width() { return width; }
    int get_height() { return height; }
    std::vector<Cell> get_all_points() { return all_points; }
    std::vector<Cell> get_built_points() { return built_points; }
    void set_built_points(std::vector<Cell> built_points) { this->built_points = built_points; }
    void set_border();

    void insert_to_built_points(std::vector<Cell> insert_points);
    int remove_row();
    void refresh();

};

#endif