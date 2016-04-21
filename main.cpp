//
//  main.cpp
//  Connect4
//
//  Copyright © 2016 Ormir Gjurgjejt, Nitika Kumar. All rights reserved.
//

#include <iostream>
#include "board.hpp"

int main(int argc, const char * argv[]) {
    GameBoard gameboard(8,5);
    
    gameboard.putCoin('A', 1);
    gameboard.putCoin('A', 2);
    gameboard.putCoin('A', 3);
    gameboard.putCoin('A', 4);
    
    gameboard.printBoard();

    return 0;
}
