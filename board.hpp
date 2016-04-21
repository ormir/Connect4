//
//  board.hpp
//  Connect4
//
//  Created by dolly sharma on 4/20/16.
//  Copyright © 2016 dolly sharma. All rights reserved.
//

#ifndef board_hpp
#define board_hpp

#include <vector>
#include <stdio.h>
#include <iostream>

class GameBoard{
private:
    std::vector<std::vector<char>> board;
    
    bool checkWin(int, int, char) const;
    bool checkLambda(std::function<int(int)>, std::function<int(int)>, char) const;
public:
    GameBoard(int,int);
    void printBoard() const;
    bool putCoin(char,int);
    int getWidth() const;
};

#endif /* board_hpp */
