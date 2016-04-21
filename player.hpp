//
//  player.hpp
//  Connect4
//
//  Created by dolly sharma on 4/21/16.
//  Copyright © 2016 dolly sharma. All rights reserved.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include "board.hpp"

class Player{
private:
    char name;
public:
    Player(const char&);
    void putCoin(int, GameBoard&);
    ~Player();
};

class Human : public Player {
public:
    Human(const char&);
    virtual ~Human();
};

class Computer : public Player {
public:
    Computer(const char&);
    virtual ~Computer();
};

#endif /* player_hpp */
