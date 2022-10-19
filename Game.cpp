#include "Game.h"

Game::Game()
    :score{ 0 }, speed{ 200 }, run{ true } {

    do {
        system("cls");
        board = Board(20, 20);
        running();
    } while (regame());

}


void Game::running() {
    while (!game_over()) {
        curr_piece = Piece(Cell((board.get_width() - 1) / 2, board.get_height(), 'O'));
        while (!hit_built_points_down()) {
            speed = 200;
            ClearScreen();
            curr_piece.fall_down();
            score += board.remove_row();
            board.refresh();
            refresh_final_points();
            draw();
            controls();
            Sleep(speed);

        }
    }
}

bool Game::game_over() {
    for (const auto& pnt : board.get_built_points())
        if (pnt.get_y() >= board.get_height() - 2) {
            return true;
        }
    return false;
}

bool Game::regame() {
    std::cout << "======Game over======" << std::endl;
    std::cout << "replay ?? (y/n) " << std::endl;
    char c{};
    bool isvalid{ false };
    do {
        std::cin >> c;
        if (c == 'y')
            return true;
        else if (c == 'n')
            return false;
        else {
            std::cout << "invalid entry\n";
            isvalid = true;
        }
    } while (isvalid);
}

bool Game::hit_built_points_down() {

    for (const auto& next_piece_pnt : curr_piece.next_fall_down_body()) {
        //hit the ground
        if (next_piece_pnt.get_y() == 0) {
            board.insert_to_built_points(curr_piece.get_body());
            return true;
        }
        //hit built points
        for (const auto& built_pnt : board.get_built_points())
            if (next_piece_pnt == built_pnt) {
                board.insert_to_built_points(curr_piece.get_body());
                return true;
            }
    }

    return false;
}

bool Game::checked_move(enum move_direction dir) {
    for (const auto& next_piece_pnt : curr_piece.next_move_body(dir)) {
        if (next_piece_pnt.get_x() == 0 || next_piece_pnt.get_x() == (board.get_width() - 1))
            return false;

        for (const auto& built_pnt : board.get_built_points())
            if (built_pnt == next_piece_pnt)
                return false;
    }

    curr_piece.move(dir);
    return true;
}

bool Game::checked_rotate() {
    for (const auto& next_piece_pnt : curr_piece.next_rotate_body()) {
        if (next_piece_pnt.get_x() == 0 || next_piece_pnt.get_x() == (board.get_width() - 1))
            return false;

        for (const auto& built_pnt : board.get_built_points())
            if (built_pnt == next_piece_pnt)
                return false;
    }

    curr_piece.rotate();
    return true;
}

void Game::refresh_final_points() {

    final_pionts = board.get_all_points();
    for (auto& final_pnt : final_pionts)
        for (auto piece_pnt : curr_piece.get_body())
            if (final_pnt == piece_pnt)
                final_pnt = piece_pnt;
}

void Game::draw() {
    for (int i{ board.get_height() - 1 }; i >= 0; i--) {
        for (int j{ 0 }; j < board.get_width(); j++) {
            auto t = std::find(final_pionts.begin(), final_pionts.end(), Cell(j, i));
            std::cout << t->get_type();
        }
        std::cout << std::endl;
    }
    std::cout << "\n Score = " << score << std::endl;
}

void Game::controls() {
    if (GetAsyncKeyState(VK_UP))
        checked_rotate();
    else if (GetAsyncKeyState(VK_DOWN))
        speed = 10;
    else if (GetAsyncKeyState(VK_RIGHT))
        checked_move(right);
    else if (GetAsyncKeyState(VK_LEFT))
        checked_move(left);
    else if (GetAsyncKeyState('P')) {
        //run = gameover();
    }
}

void Game::ClearScreen() {
    // Function which cleans the screen without flickering
    COORD cursorPosition;   cursorPosition.X = 0;   cursorPosition.Y = 0;   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}