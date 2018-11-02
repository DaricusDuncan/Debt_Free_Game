//
//  Expenses.hpp
//  DEBT_SNOWBALL_GAME
//
//  Created by Lando Shepherd on 10/23/18.
//  Copyright © 2018 Lando Shepherd. All rights reserved.
//

#ifndef Expense_hpp
#define Expense_hpp

#include <iostream>

class Expense{
private:
    std::string name;
    float balance;
    float payment;
    bool paid;
    
public:
    Expense();
    Expense(std::string, float, float);
    void setName(std::string);
    void updatePayment(float);
    float getPayment();
    void updateBalance(float);
    float getBalance();
    void isExpensePaid(bool);
    ~Expense();
};
#endif /* Expense_hpp */
