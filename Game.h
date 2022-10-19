#if !defined(GAME_H_)
#define GAME_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include "windows.h"

#include "Cell.h"
#include "Piece.h"
#include "Board.h"

class Game {
private:
    Board board;
    Piece curr_piece;
    std::vector<Cell> final_pionts;
    int score;
    int speed;
    bool run;
public:

    Game();
    void controls();
    void running();
    bool hit_built_points_down();

    bool checked_move(enum move_direction dir);
    bool checked_rotate();

    void draw();
    void refresh_final_points();

    void ClearScreen();
    bool game_over();
    bool regame();


};


#endif