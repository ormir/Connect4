//
//  board.cpp
//  Connect4
//
//  Created by dolly sharma on 4/20/16.
//  Copyright © 2016 dolly sharma. All rights reserved.
//

#include "board.hpp"

GameBoard::GameBoard(int width,int height):
board(height, std::vector<char>(width, '.')){}

void GameBoard::printBoard() const {
    int itY = 1;
    for(auto y = board.begin(); y!= board.end(); y++){
        for(auto x = y->begin(); x!=y->end(); x++){
            std::cout << *x;
        }
        std::cout << itY << std::endl;
        itY++;
    }
    
    for(int itX=1; itX<=board.begin()->size(); itX++){
        std::cout << itX;
    }
    std::cout << std::endl;
}

bool GameBoard::putCoin(char n, int col) {
    col--;
    int coinRow = 0;
    if (col >  board.begin()->size() || col < 0) {
        std::cout << "Colum " << col << " doesn't exist" << std::endl;
        return false;
    } else if ((*(board.begin()))[col] != '.'){
        std::cout << "Column full" << std::endl;
        return false;
    }
  
    //Zelle gecacht im Pointer previous
    for(auto row = board.begin(); row != board.end(); row++){
        if ((*row)[col]!='.'){
            (*(--row))[col] = n;
            break;
        }
        
        if(row == --board.end()){
            (*row)[col] = n;
        }
        coinRow++;
    }
    
    checkWin(col, --coinRow, n);
    return true;
}

bool GameBoard::checkWin(int col, int row, char n) const {
   
    if (checkHorisontal(col, row, n) ||
        checkVertical(col, row, n) ||
        checkDiagonal(col, row, n) ||
        checkBackDiagonal(col, row, n)) {
        std::cout << "WIN " << n << std::endl;
        return true;
    }
    
    return false;
}

bool GameBoard::checkHorisontal(int col, int row, char n) const {
    int hits = 0; // horisontal hits
    
    // Horisontal right Check
    for(int i = 1; i < 4; i++) {
        if(col + i < board.begin()->size() &&
           board[row][col+i] == n) {
            hits ++;
        } else {
            break;
        }
    }
    
    // Horisontal left Check
    for(int i = 1; i < 4; i++) {
        if(col - i >= 0 &&
           board[row][col-i] == n) {
            hits ++;
        } else {
            break;
        }
    }
    
    if (hits == 3) return true;
    return false;
}

bool GameBoard::checkVertical(int col, int row, char n) const {
    int hits = 0;
    // Vertical down
    for(int i = 1; i < 4; i++) {
        if(row + i < board.size() &&
           board[row+i][col] == n) {
            hits ++;
        } else {
            break;
        }
    }
    
    // Vertical up
    for(int i = 1; i < 4; i++) {
        if(row - i >= 0 &&
           board[row-i][col] == n) {
            hits ++;
        } else {
            break;
        }
    }
    
    if (hits == 3) return true;
    return false;
}

bool GameBoard::checkDiagonal(int col, int row, char n) const {
    int hits = 0;
    
    // Diagonal down
    for(int i = 1; i < 4; i++) {
        if(row + i < board.size() &&
           col + i < board.begin()->size() &&
           board[row+i][col+i] == n) {
            hits ++;
        } else {
            break;
        }
    }
    
    // Diagonal up
    for(int i = 1; i < 4; i++) {
        if(row - i >= 0 &&
           col - i >= 0 &&
           board[row-i][col-i] == n) {
            hits ++;
        } else {
            break;
        }
    }
    
    if (hits == 3) return true;
    return false;
}

bool GameBoard::checkBackDiagonal(int col, int row, char n) const {
    int hits = 0;
    
    // Back Diagonal down
    for(int i = 1; i < 4; i++) {
        if(row - i >= 0 &&
           col + i < board.begin()->size() &&
           board[row-i][col+i] == n) {
            hits ++;
        } else {
            break;
        }
    }
    
    // Back Diagonal up
    for(int i = 1; i < 4; i++) {
        if(row + i < board.size() &&
           col - i >= 0 &&
           board[row+i][col-i] == n) {
            hits ++;
        } else {
            break;
        }
    }
    
    if (hits == 3) return true;
    return false;
}
