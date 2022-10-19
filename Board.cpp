#include "Board.h"

Board::Board(int width, int height)
    :width{ width }, height{ height } {
    for (int i{ 0 }; i < width; i++)
        for (int j{ 0 }; j < height; j++)
            all_points.push_back(Cell(i, j));

    set_border();
}

void Board::refresh() {
    set_border();
    for (auto& all_pnt : all_points)
        for (auto built_pnt : built_points)
            if (all_pnt == built_pnt)
                all_pnt = built_pnt;    //seting the char of all_pnt to built pnt
}

void Board::insert_to_built_points(std::vector<Cell> insert_points) {
    built_points.insert(built_points.end(), insert_points.begin(), insert_points.end());
}

void Board::set_border() {
    for (auto& point : all_points) {
        if (point.get_x() == 0 || point.get_y() == 0 || point.get_x() == width - 1 || point.get_y() == height - 1)
            point.set_type('#');
        else
            point.set_type(' ');
    }
}

int Board::remove_row() {
    int removed_rows{ 0 };
    int i{ 1 };
    while (i < height) {

        int built_points_count = std::count_if(built_points.begin(), built_points.end(), [i](const Cell& point) {
            return (point.get_y() == i);
            });

        if (built_points_count == (width - 2)) {
            removed_rows++;

            // earse-remove idiom
            auto it = std::remove_if(built_points.begin(), built_points.end(), [i](Cell point) {
                return (point.get_y() == i);
                });
            built_points.erase(it, built_points.end());

            std::for_each(built_points.begin(), built_points.end(), [i](Cell& point) {
                if (point.get_y() > i)
                    point.move(0, -1);
                });

        }
        else
            i++;
    }

    return removed_rows;
}