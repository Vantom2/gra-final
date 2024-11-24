#ifndef Board_H
#define Board_H

class Board {
public:
    char board[10][10]; // plansza statkow 
    char shot_board[10][10]; // Plansza strzalow 
    
    Board();
    void show_board(bool opponent_view = false);
    bool check_view(int x, int y, int LENGHT, char ORIENTATION);
    bool set_ship(int x, int y, int LENGHT, char ORIENTATION);
    bool shot(int x, int y);
    bool check_all_ships_destroyed();
    void shown_board(bool is_shot_board);
    bool receive_shot(int x, int y);
    void record_shot(int x, int y, bool hit);
    bool check_hit(int x, int y);
};

#endif
