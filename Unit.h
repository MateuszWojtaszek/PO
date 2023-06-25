//
// Created by mateusz on 24.06.23.
//

#ifndef PO_UNIT_H
#define PO_UNIT_H


#include <string>

class Unit {
    std::string name;
    int health;
public:
    Unit(const std::string &n, int hp);
};


#endif //PO_UNIT_H
