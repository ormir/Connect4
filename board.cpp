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

void GameBoard::putCoin(char n, int col){
    col--;
    int size = board.begin()->size();
//    if(col > size || col < 0){
//        std::cout << "Error, try again" << std::endl;
//    }
//test
    //Zelle gecacht im Pointer previous
    for(auto row = board.begin(); row != board.end(); row++){
        if((*row)[col] != '.' && row == board.begin()) {
            std::cout << "Column full" << std::endl;
            break;
        } else if ((*row)[col]!='.'){
            (*(row--))[col] = n;
            break;
        }
        
        if(row == board.end()){
            (*row)[col] = n;
        }
        
        
    }
    
}



