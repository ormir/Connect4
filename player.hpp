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
#include <time.h>
#include "board.hpp"

class Player{
protected:
    char name;
    Player(const char&);
public:
    virtual bool putCoin(GameBoard&);
    char getName() const;
    virtual ~Player();
};

class Human : public Player {
public:
    Human(const char&);
    ~Human();
};

class Computer : public Player {
public:
    Computer(const char&);
    bool putCoin(GameBoard&);
    ~Computer();
};

#endif /* player_hpp */
