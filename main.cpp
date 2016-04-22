//
//  main.cpp
//  Connect4
//
//  Copyright © 2016 Ormir Gjurgjejt, Nitika Kumar. All rights reserved.
//

#include <iostream>
#include "board.hpp"
#include "player.hpp"

int main(int argc, const char * argv[]) {
    GameBoard gameboard(8,5);
    Player *p1 = NULL;
    Player *p2 = NULL;
    char type, name;
    
    // Set players
    std::cout << "First player is: (h/c) ";
    std::cin >> type;
    std::cout << "First player name is: ";

    std::cin >> name;
    
    if (type == 'h') {
        p1 = new Human(name);
    } else if (type == 'c') {
        p1 = new Computer(name);
    }
    
    std::cout << "Second player is: (h/c) ";
    std::cin >> type;
    std::cout << "Second player name is: ";
    std::cin >> name;
    
    if (type == 'h') {
        p2 = new Human(name);
    } else if (type == 'c') {
        p2 = new Computer(name);
    }
    
    while (!gameboard.isFull()) {
        p1->putCoin(gameboard);
        gameboard.printBoard();
        p2->putCoin(gameboard);
        gameboard.printBoard();
    }
    
    delete p1;
    delete p2;
    return 0;
}

// Horisontal win
//        gameboard.putCoin('A', 1);
//        gameboard.putCoin('A', 2);
//        gameboard.putCoin('A', 3);
//        gameboard.putCoin('A', 4);

// Vertical win
//        gameboard.putCoin('A', 1);
//        gameboard.putCoin('A', 1);
//        gameboard.putCoin('A', 1);
//        gameboard.putCoin('A', 1);

//    // Diagonal win
//        gameboard.putCoin('A', 1);
//        gameboard.putCoin('B', 2);
//        gameboard.putCoin('B', 3);
//        gameboard.putCoin('A', 4);
//        gameboard.putCoin('A', 1);
//        gameboard.putCoin('B', 2);
//        gameboard.putCoin('A', 3);
//        gameboard.putCoin('B', 1);
//        gameboard.putCoin('A', 2);
//        gameboard.putCoin('A', 1);

// Back Diagonal win
//        gameboard.putCoin('A', 1);
//        gameboard.putCoin('B', 2);
//        gameboard.putCoin('B', 3);
//        gameboard.putCoin('A', 4);
//        gameboard.putCoin('A', 2);
//        gameboard.putCoin('B', 3);
//        gameboard.putCoin('A', 4);
//        gameboard.putCoin('A', 3);
//        gameboard.putCoin('B', 4);
//        gameboard.putCoin('A', 4);