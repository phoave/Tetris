										   #include "Cell.h"


Cell::Cell(int x, int y, char type)
    :x{x}, y{y}, type{type} {}

 bool Cell::operator==(const Cell &rhs) const {
     return (x == rhs.get_x() && y == rhs.get_y());
 }

Cell Cell::shift_copy(int x_shift, int y_shift) const {
    return Cell(x + x_shift, y + y_shift, type);
}

void Cell::move(int x_move, int y_move) {
    x += x_move;
    y += y_move;
}

void Cell::set_coordinate(int x_new, int y_new) {
    x = x_new;
    y = y_new;
}