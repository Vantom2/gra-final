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
            // Dla statków jedno masztowych, automatycznie ustawiamy orientację w pionie
            if (ships[i] == 1) {
                ORIENTATION = 'V'; // Ustawiamy w pionie
                cout << "Ustaw statek o dlugosci " << ships[i] << " (wspolrzedne x, y): ";
                cin >> x >> y;

                if (board.set_ship(x, y, ships[i], ORIENTATION)) {
                    set = true;
                    cout << "Statek ustawiony pomyślnie!\n";
                    board.show_board(false);  
                } else {
                    cout << "Nie udało się ustawić statku. Spróbuj ponownie.\n";
                }
            } else {
                // Dla pozostałych statków pytamy o orientację
                cout << "Ustaw statek o dlugosci " << ships[i] << " (wpisz wspolrzedne x, y oraz orientacje POZIOMO(H)/PIONOWO(V) (np. 4 5 V): ";
                cin >> x >> y >> ORIENTATION;

                if (board.set_ship(x, y, ships[i], ORIENTATION)) {
                    set = true;
                    cout << "Statek ustawiony pomyślnie!\n";
                    board.show_board(false);  
                } else {
                    cout << "Nie udało się ustawić statku. Spróbuj ponownie.\n";
                }
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
