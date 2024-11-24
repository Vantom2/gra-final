#include "Player.h"
#include <iostream>
#include <vector>
using namespace std;
Player::Player(string name) {
    this->name = name;
}

void Player::set_ships_manual() {
    vector<int> ships = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1}; 
    for (int i = 0; i < ships.size(); i++) {
        bool set = false;
        while (!set) {
            int x, y;
            char ORIENTATION;
            cout << "Ustaw statek o dlugosci " << ships[i] << " (wpisz wspolrzedne x, y oraz orientacje [POZIOMO(H)/PIONOWO(V)]): ";
            cin >> x >> y >> ORIENTATION;

            
            if (board.set_ship(x, y, ships[i], ORIENTATION)) {
                set = true;
                cout << "Statek ustawiony pomyslnie!\n";
                board.show_board(false);  
            } else {
                cout << "Nie udało sie ustawic statku. Sprobuj ponownie.\n";
            }
        }
    }
}

bool Player::shot_opponent(Board& opponent_board, int x, int y) {
    bool hit = opponent_board.shot(x, y);
    // Aktualizuj planszę strzałów
    if (hit) {
        shot_board.board[y][x] = 'X'; // Trafiony
    } else {
        shot_board.board[y][x] = 'P'; // Pudło
    }
    return hit;
}

bool Player::all_ships_destroyed() {
    return board.check_all_ships_destroyed();
}
