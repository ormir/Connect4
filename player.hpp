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

class Player{
private:
    char name;
public:
    Player(char);
    void turn();
};

#endif /* player_hpp */
