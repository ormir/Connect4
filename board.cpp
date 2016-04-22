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

bool GameBoard::putCoin(char n, int col, bool write) {
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
            if(write) (*(--row))[col] = n; //name of player being inserted
            break;
        }
        
        //the bottom of the board
        if(row == --board.end()){
            if(write) (*row)[col] = n;
        }
        coinRow++;
    }
    
    checkWin(col, --coinRow, n);
    return true;
}

int GameBoard::getWidth() const{
    return board.begin()->size();
}

int GameBoard::getHeight() const {
    return board.size();
}

bool GameBoard::checkWin(int col, int row, char n) const {
    int maxMatch = 0;
    int hMatch = 0; //horizontal Match
    int vMatch = 0;
    int dMatch = 0;
    int bdMatch = 0;
    
    // Horizontal
    //&col - call by reference to save memory
    auto horisontalCol = [&col](int i){return col+i;};
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
    
//    if(checkMatch(horisontalRow, horisontalCol, n) == 3 ||
//       checkMatch(verticalRow, verticalCol, n) == 3 ||
//       checkMatch(diagonalRow, diagonalCol, n) == 3 ||
//       checkMatch(backDiagonalRow, backDiagonalCol, n) == 3){
//        std::cout << "WIN " << n << std::endl;
//        return true;
//    }
    
    hMatch = checkMatch(horisontalRow, horisontalCol, n);
    vMatch = checkMatch(verticalRow, verticalCol, n);
    dMatch = checkMatch(diagonalRow, diagonalCol, n);
    bdMatch = checkMatch(backDiagonalRow, backDiagonalCol, n);
    
    if (hMatch > maxMatch) {
        maxMatch = hMatch;
    }
    
    if(vMatch > maxMatch){
        maxMatch = vMatch;
    }

    if(dMatch > maxMatch){
        maxMatch = dMatch;
    }
    
    if(bdMatch > maxMatch){
        maxMatch = bdMatch;
    }
    
    return false;
}

int GameBoard::checkMatch(std::function<int(int)> funRow, std::function<int(int)> funCol, char n) const {
    int matches = 0; // horisontal hits
    
    // Forward Check: horizontal, vertical, diagonal, back diagonal
    for(int i = 1; i < 4; i++) {
        if(funRow(i) < board.size() &&
           funCol(i) < board.begin()->size() &&
           board[funRow(i)][funCol(i)] == n) {
            matches ++;
        } else {
            break;
        }
    }
    
    // Backward Check: horizontal, vertical, diagonal, back diagonal
    for(int i = 1; i < 4; i++) {
        if(funRow(-i) >= 0 &&
           funRow(-i)< board.size() &&
           funCol(-i) >= 0 &&
           board[funRow(-i)][funCol(-i)] == n) {
            matches ++;
        } else {
            break;
        }
    }
    
    return matches;
}
