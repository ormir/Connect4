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

void Player::putCoin(int col, GameBoard& board) {
    board.putCoin(name, col);
}

Player::~Player() {}

Human::Human(const char &n):
Player(n) {}

Human::~Human(){}

Computer::Computer(const char &n):
Player(n) {}

Computer::~Computer() {}