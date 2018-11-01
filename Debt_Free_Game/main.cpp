//
//  main.cpp
//  DEBT_SNOWBALL_GAME
//
//  Created by Lando Shepherd on 10/20/18.
//  Copyright © 2018 Lando Shepherd. All rights reserved.
//

#include <iostream>
#include "DFSGame.hpp"

int main() {
    DFSGame *newGame;
    newGame = new DFSGame;
    
    newGame->startGame();
    delete newGame;
    return 0;
}
