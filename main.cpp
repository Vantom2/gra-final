#include "Player.h"
#include "Board.h"
#include <iostream>
#include <vector>
using namespace std;
// Funkcje pomocnicze
void clear_screan() {
#ifdef _WIN32
    system("cls"); // Wyczyść ekran na Windows
#else
    system("clear"); 
#endif
}

void stop_round() {
    cout << "Nacisnij Enter, aby przekazac ture przeciwnikowi...";
    cin.ignore(); // Oczekiwanie na Enter
    cin.get();    // Kolejne oczekiwanie, gdy jest buforowane wejście
}

// Funkcja ustawiania statków dla gracza
void set_player_ship(Player& player) {
    cout << player.name << " - ustaw swoje statki.\n";
    player.set_ships_manual();
    clear_screan();
}

// Funkcja obsługi tury gracza
bool t_round(Player& akt_player, Player& opponent, int& round) {
    cout << akt_player.name << " - Twoja tura!\n";
    akt_player.board.show_board(false); // Plansza statków
    akt_player.shot_board.show_board(true); // Plansza strzałów

    int x, y;
    bool correct = false;
    while (!correct) {
        cout << "Podaj wspolrzedne do strzalu (x y): ";
        cin >> x >> y;

        if (x >= 0 && x < 10 && y >= 0 && y < 10) {
            correct = true;
            if (akt_player.shot_opponent(opponent.board, x, y)) {
                if (opponent.all_ships_destroyed()) {
                    cout << "Gratulacje! " << akt_player.name << " wygral!\n";
                    return true; // Koniec gry
                } else {
                    cout << "Masz kolejną ture!\n";
                }
            } else {
                round = (round == 1) ? 2 : 1;
                stop_round();
                clear_screan();
            }
        } else {
            cout << "Niepoprawne wspolrzedne! Wprowadz liczby od 0 do 9.\n";
        }
    
    }

    return false; // Gra trwa dalej
}

// Funkcja pojedynczej rozgrywki
bool game_play(int& player1_wins, int& player2_wins) {
    Player player1("Player 1");
    Player player2("Player 2");

    // Ustawienie statków
    set_player_ship(player1);
    set_player_ship(player2);

    int round = 1; // 1 dla Gracza 1, 2 dla Gracza 2
    bool end = false;

    while (!end) {
        Player& akt_player = (round == 1) ? player1 : player2;
        Player& opponent = (round == 1) ? player2 : player1;

        end = t_round(akt_player, opponent, round);
    }

    if (round == 1) {
        player1_wins++;
    } else {
        player2_wins++;
    }

    cout << "Czy chcesz zagrac ponownie? (T/N): ";
    char choice;
    cin >> choice;
    return !(choice == 'N' || choice == 'n'); // Zwraca true, jeśli player chce kontynuować
}

// Funkcja główna
int main() {
    int player1_wins = 0;
    int player2_wins = 0;
    bool play_again = true;

    while (play_again) {
        play_again = game_play(player1_wins, player2_wins);
        cout << "Wyniki:\n";
        cout << "Player 1: " << player1_wins << " wygranych\n";
        cout << "Player 2: " << player2_wins << " wygranych\n";
    }

    cout << "Dziekujemy za gre!" << endl;
    return 0;
}
