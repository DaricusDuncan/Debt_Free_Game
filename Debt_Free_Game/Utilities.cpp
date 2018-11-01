//
//  Utilities.cpp
//  DEBT_SNOWBALL_GAME
//
//  Created by Lando Shepherd on 10/24/18.
//  Copyright © 2018 Lando Shepherd. All rights reserved.
//

#include "Utilities.hpp"

Utilities::Utilities(){};
void Utilities::deleteCheck(int numOfNew, int numOfDelete)
{
    assert(numOfNew == numOfDelete);
    if(numOfNew != numOfDelete)
    {
        std::cout << "ERROR: Leak in Gameplay." << std::endl;
    }
    else
    {
        std::cout << "Clear" << std::endl;
    }
}
Utilities::~Utilities(){};
