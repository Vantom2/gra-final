#include "Player.h"
#include <iostream>
#include <vector>

Player::Player(std::string name) {
    this->name = name;
}

void Player::set_ships_manual() {
    std::vector<int> ships = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1}; 
    for (int i = 0; i < ships.size(); i++) {
        bool set = false;
        while (!set) {
            int x, y;
            char ORIENTATION;
            std::cout << "Ustaw statek o dlugosci " << ships[i] << " (wpisz wspolrzedne x, y oraz orientacje [POZIOMO(H)/PIONOWO(V)]): ";
            std::cin >> x >> y >> ORIENTATION;

            
            if (board.set_ship(x, y, ships[i], ORIENTATION)) {
                set = true;
                std::cout << "Statek ustawiony pomyślnie!\n";
                board.show_board(false);  
            } else {
                std::cout << "Nie udało się ustawić statku. Spróbuj ponownie.\n";
            }
        }
    }
}

bool Player::shot_opponent(int x, int y) {
    return board.shot(x, y);
}

bool Player::all_ships_destroyed() {
    return board.check_all_ships_destroyed();
}
