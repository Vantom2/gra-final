#include "Ship.h"

Ship::Ship(int LENGHT) : LENGHT(LENGHT) {}

void Ship::add_field(int x, int y) {
    field.push_back(std::make_pair(x, y));
}
