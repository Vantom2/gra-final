#include "Board.h"
#include <iostream>
using namespace std;
Board::Board() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board[i][j] = '~';
        }
    }
}

void Board::show_board(bool opponent_view) {
    std::cout << "   ";
    for (int i = 0; i < 10; i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 10; i++) {
        std::cout << i << "  ";
        for (int j = 0; j < 10; j++) {
            if (opponent_view && board[i][j] == 'O') {
                std::cout << "~ ";
            } else {
                std::cout << board[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}
bool Board::check_view(int x, int y, int LENGHT, char ORIENTATION) {
    if (ORIENTATION == 'H') { // Poziomo
        for (int i = -1; i <= LENGHT; i++) {
            for (int j = -1; j <= 1; j++) {
                int nx = x + i;
                int ny = y + j;
                if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10 && board[ny][nx] != '~') {
                    return false;
                }
            }
        }
    } else if (ORIENTATION == 'V') { // Pionowo
        for (int i = -1; i <= LENGHT; i++) {
            for (int j = -1; j <= 1; j++) {
                int nx = x + j;
                int ny = y + i;
                if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10 && board[ny][nx] != '~') {
                    return false;
                }
            }
        }
    }
    return true;
}


bool Board::set_ship(int x, int y, int LENGHT, char ORIENTATION) {
    // Sprawdź, czy statek zmieści się na planszy
    if ((ORIENTATION == 'H' && (x + LENGHT - 1) >= 10) || (ORIENTATION == 'V' && (y + LENGHT - 1) >= 10)) {
        return false;
    }

    // Sprawdź, czy okolice są wolne
    if (!check_view(x, y, LENGHT, ORIENTATION)) {
        return false;
    }

    // Ustaw statek
    if (ORIENTATION == 'H') {
        for (int i = 0; i < LENGHT; i++) {
            board[y][x + i] = 'O';
        }
    } else if (ORIENTATION == 'V') {
        for (int i = 0; i < LENGHT; i++) {
            board[y + i][x] = 'O';
        }
    }

    return true;
}


bool Board::shot(int x, int y) {
    if (board[y][x] == 'O') {
        board[y][x] = 'X';
        std::cout << "Trafiony!\n";
        return true;
    } else if (board[y][x] == '~') {
        board[y][x] = 'P';
        std::cout << "Pudło!\n";
        return false;
    } else {
        std::cout << "To pole zostało już trafione! Tracisz turę.\n";
        return false;
    }
}

bool Board::check_all_ships_destroyed() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (board[i][j] == 'O') {
                return false;
            }
        }
    }
    return true;
}
