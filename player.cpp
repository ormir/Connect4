//
//  player.cpp
//  Connect4
//
//  Created by dolly sharma on 4/21/16.
//  Copyright © 2016 dolly sharma. All rights reserved.
//

#include "player.hpp"

Player::Player(const char &n):
name(n) {}

void Player::putCoin(GameBoard& board) {
    int col = -1;
    std::cout << name << ": ";
    std::cin >> col;
    board.putCoin(name, col, true);
}

Player::~Player() {
    std::cout << "Deleted player" << std::endl;
}

Human::Human(const char &n):
Player(n) {}

Computer::Computer(const char &n):
Player(n) {}

void Computer::putCoin(GameBoard &board) {
    // AI
//    board.putCoin(name, std::rand()%board.getWidth());
    for(int col = 0; col < board.getWidth(); col++) {
        board.putCoin(name, col, false);
    }
    
//    board.checkWin(&col, <#int#>, name);
}
