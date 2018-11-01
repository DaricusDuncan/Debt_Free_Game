//
//  Player.hpp
//  DEBT_SNOWBALL_GAME
//
//  Created by Lando Shepherd on 10/22/18.
//  Copyright © 2018 Lando Shepherd. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <iostream>
#include <vector>
#include "Expense.hpp"

class Player
{
private:
    int playerAge;
    std::string jobTitle;
    
    //Player Financials
    float jobSalary;
    float emergencyFund;
    float bankBalance;
    float savings;
    float retirement;
    float totalDebt;
    
    //Player Expenses
    Expense* tithe;
    Expense* mortgage; //Will have a balance
    Expense* utilities;
    Expense* groceries;
    Expense* insurance;
    Expense* internet;
    Expense* cable;
    Expense* musicService;
    Expense* movieService;
    Expense* funMoney;
    
    //Player Debt
    Expense* creditCards;
    Expense* studentLoans;
    Expense* carLoan;
    Expense* totalOfUnpaidBills;
    
    std::vector<Expense*> expenses;
    
public:
    Player();
    //Player Stats
    void setPlayerAge(int);
    int getPlayerAge();
    void setJobTitle(std::string);
    std::string getJobTitle();
    void setJobSalary(float);
    float getJobSalary();
    void updateEmergencyFund(float);
    float getEmergencyFund();
    void updateBankBalance(float);
    float getBankBalance();
    void updateSavingsFund(float);
    float getSavingsFund();
    void updateRetirementAccount(float);
    float getRetirementAccount();
    void addExpense(Expense*);
    std::vector<Expense*> getExpenses();
    
    //Player Expenses
    void setTithePayment(float);
    float getTithePayment();
    void setMortgagePayment(float);
    float getMortgagePayment(); //Will have a balance
    void updateMortgageBalance(float);
    float getMortgageBalance();
    void setUtilitiesPayment(float);
    float getUtilitiesPayment();
    void setGroceriesPayment(float);
    float getGroceriesPayment();
    void setInsurancePayment(float);
    float getInsurancePayment();
    void setInternetPayment(float);
    float getInternetPayment();
    void setCablePayment(float);
    float getCablePayment();
    void setMusicServicePayment(float);
    float getMusicServicePayment();
    void setMovieServicePayment(float);
    float getMovieServicePayment();
    void setFunMoneyPayment(float);
    float getFunMoneyPayment();
    
    //Player Debt
    void setCreditCardsPayment(float);
    float getCreditCardsPayment();
    void updateCreditCardsBalance(float);
    float getCreditCardBalance();
    void setStudentLoansPayment(float);
    float getGetStudentLoansPayment();
    void updateStudentLoanBalance(float);
    float getStudentLoanBalance();
    void setCarLoanPayment(float);
    float getCarLoanPayment();
    void updateCarLoanBalance(float);
    float getCarLoanBalance();
    void updateTotalOfUnpaidBills(float);
    float getTotalOfUnpaidBills();
    
    ~Player();
};
#endif /* Player_hpp */
