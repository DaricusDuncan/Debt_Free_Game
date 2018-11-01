//
//  Expenses.cpp
//  DEBT_SNOWBALL_GAME
//
//  Created by Lando Shepherd on 10/23/18.
//  Copyright © 2018 Lando Shepherd. All rights reserved.
//

#include "Expense.hpp"

Expense::Expense()
{
    balance = 0;
    payment = 0;
}

Expense::Expense(std::string _name, float _balance, float _payment)
{
    name = _name;
    balance = _balance;
    payment = _payment;
}

void Expense::updatePayment(float _newPayment)
{
    payment = _newPayment;
}

float Expense::getPayment()
{
    return payment;
}

void Expense::updateBalance(float newBalance)
{
    balance = newBalance;
}

float Expense::getBalance()
{
    return balance;
}

void Expense::isExpensePaid(bool isBillPaid)
{
    paid = isBillPaid;
}

Expense::~Expense()
{
    
}
