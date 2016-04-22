//
//  board.hpp
//  Connect4
//
//  Created by Nitika Kumar, Ormir Gjurgjej on 4/21/16.
//  Copyright © 2016. All rights reserved.
//

#ifndef board_hpp
#define board_hpp

#include <vector>
#include <stdio.h>
#include <iostream>

class GameBoard{
private:
    std::vector<std::vector<char>> board;
    int checkMatch(std::function<int(int)>, std::function<int(int)>, char) const;
    int checkWin(int, int, char) const;
    bool full;
public:
    GameBoard(int,int);
    void printBoard() const;
    int putCoin(char,int, bool);
    int getWidth() const;
    int getHeight() const;
    bool isFull() const;
};

#endif /* board_hpp */
