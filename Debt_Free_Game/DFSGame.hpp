//
//  Gameplay.hpp
//  DEBT_SNOWBALL_GAME
//
//  Created by Lando Shepherd on 10/20/18.
//  Copyright © 2018 Lando Shepherd. All rights reserved.
//

#ifndef DFSGame_hpp
#define DFSGame_hpp

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <ctime>
#include "Player.hpp"
#include "Janitor.hpp"
#include "Utilities.hpp"

class DFSGame
{
private:
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    
    Player* newPlayer = NULL;
    int numOfNew;
    int numOfDelete;
    
    int year = timePtr->tm_year + 1900;
    int playerAge;
    std::string jobTitle;
    float jobSalary;
    float bankBalance;
    float emergencyFund;
    float savings;
    float retirment;
    float totalDebt;
    float totalExpenses;
    std::string careers[5];
    
public:
    DFSGame();
    ~DFSGame();
    void displayGameTitle();
    void viewMainMenu();
    bool validateMenuChoice(char);
    void getPlayerAge();
    void setPlayerFinancials();
    void setExpenses();
    char setupGame();
    void viewStats(int);
    void viewExpenses();
    void viewDebt();
    void viewAccounts();
    void updateMonthlyPayments();
    void payDebt(char);
    void payDay(int);
    //void viewUnpaidExpenses();
    bool _validateAccountSelection(char);
    bool _validateFundAvailability(char, float);
    void _makeTransfer(char, char, float);
    void transferFunds();
    void updateTotals();
    void autoPay(int);
    void startGame();
};

#endif
