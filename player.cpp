//
//  player.cpp
//  Connect4
//
//  Created by Nitika Kumar, Ormir Gjurgjej on 4/21/16.
//  Copyright © 2016. All rights reserved.
//

#include "player.hpp"

Player::Player(const char &n):
name(n) {}

bool Player::putCoin(GameBoard& board) {
    int col = -1;
    std::cout << name << ": ";
    std::cin >> col;
    return board.putCoin(name, col, true) == 3 ? true : false;
}

char Player::getName() const {
    return name;
}

Player::~Player() {}

Human::Human(const char &n):
Player(n) {}

Human::~Human(){}

Computer::Computer(const char &n):
Player(n) {}

Computer::~Computer(){}

bool Computer::putCoin(GameBoard &board) {
    int bestMax = -1;
    std::vector<int> posCol; // possible colms

    for(int col = 0; col < board.getWidth(); col++) {
        int colMax = board.putCoin(name, col+1, false);
        if (bestMax < colMax) {
            posCol.clear();
            posCol.push_back(col);
            bestMax = colMax;
        } else if (bestMax >= 0 && bestMax == colMax) {
            posCol.push_back(col);
        }
    }
    
    if (posCol.size() == 0) {
        std::cout << "Computer '" << name << "' couldn't find any colum" << std::endl;
    } else {
        srand((unsigned int)time(NULL));
        int putCol = (posCol.size() == 1) ? posCol[0] : posCol[std::rand()%posCol.size()];
        putCol ++;
        std::cout << name << ": " << putCol << std::endl;
        return board.putCoin(name, putCol, true) == 3 ? true : false;
    }
    return false;
}
