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

int GameBoard::getWidth() const{
    return board.begin()->size();
}

bool GameBoard::checkWin(int col, int row, char n) const {

    // Horisontal
    auto horisontalCol = [&col](int i) { return col+i; };
    auto horisontalRow = [&row](int i) { return row; };
    
    // Vertical
    auto verticalCol = [&col](int i) { return col; };
    auto verticalRow = [&row](int i) { return row+i; };
    
    // Diagonal
    auto diagonalCol = [&col](int i) { return col+i; };
    auto diagonalRow = [&row](int i) { return row+i; };
    
    // Back Diagonal
    auto backDiagonalCol = [&col](int i) { return col+i; };
    auto backDiagonalRow = [&row](int i) { return row-i; };
    
    if(checkLambda(horisontalRow, horisontalCol, n) ||
       checkLambda(verticalRow, verticalCol, n) ||
       checkLambda(diagonalRow, diagonalCol, n) ||
       checkLambda(backDiagonalRow, backDiagonalCol, n)){
        std::cout << "WIN " << n << std::endl;
        return true;
    }
    
    return false;
}

bool GameBoard::checkLambda(std::function<int(int)> funRow, std::function<int(int)> funCol, char n) const {
    int hits = 0; // horisontal hits
    
    // Horisontal right Check
    for(int i = 1; i < 4; i++) {
        if(funRow(i) < board.size() &&
           funCol(i) < board.begin()->size() &&
           board[funRow(i)][funCol(i)] == n) {
            hits ++;
        } else {
            break;
        }
    }
    
    // Horisontal left Check
    for(int i = 1; i < 4; i++) {
        if(funRow(-i) >= 0 &&
           funRow(-i)< board.size() &&
           funCol(-i) >= 0 &&
           board[funRow(-i)][funCol(-i)] == n) {
            hits ++;
        } else {
            break;
        }
    }
    
    if (hits == 3) return true;
    return false;
}
