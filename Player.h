#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Board.h"

class Player {
public:
    std::string name;
    Board board;
    
    Player(std::string name);
    void set_ships_manual(); 
    bool shot_opponent(Board& opponent_board, int x, int y);
    bool all_ships_destroyed();
};

#endif
