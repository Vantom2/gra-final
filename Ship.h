#ifndef SHIP_H
#define SHIP_H

#include <vector>
using namespace std;
class Ship {
public:
    int LENGHT;
    vector<pair<int, int>> field; // Lista pól, które zajmuje statek
    
    Ship(int LENGHT);
    void add_field(int x, int y);
};

#endif
