#if !defined(CELL_H_)
#define CELL_H_

#include <iostream>

class Cell {
private:
    int x;
    int y;
    char type;
public:
    Cell(int x = 0, int y = 0, char type = ' ');

    int get_x() const { return x; }
    int get_y() const { return y; }
    char get_type() const { return type; }
    void set_type(char c) { type = c; }


    Cell shift_copy(int x_shift, int y_shift) const;
    void move(int x_move, int y_move);
    void set_coordinate(int x_new, int y_new);

    bool operator==(const Cell& rhs) const;
};

#endif