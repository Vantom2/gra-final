#ifndef GRACZ_H
#define GRACZ_H

#include <string>
#include "Board.h"

class Player {
public:
    std::string name;
    Board board;
    Board shot_board;
    Player(std::string name);
    void set_ships_manual(); 
    bool shot_opponent(Board& opponent_board, int x, int y);
    bool all_ships_destroyed();
};

#endif
