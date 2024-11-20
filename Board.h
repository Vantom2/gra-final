#ifndef Board_H
#define Board_H

class Board {
public:
    char board[10][10];
    
    Board();
    void show_board(bool opponent_view = false);
    bool check_view(int x, int y, int LENGHT, char ORIENTATION);
    bool set_ship(int x, int y, int LENGHT, char ORIENTATION);
    bool shot(int x, int y);
    bool check_all_ships_destroyed();
};

#endif