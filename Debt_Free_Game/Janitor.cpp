//
//  Janitor.cpp
//  DEBT_SNOWBALL_GAME
//
//  Created by Lando Shepherd on 10/27/18.
//  Copyright © 2018 Lando Shepherd. All rights reserved.
//

#include "Janitor.hpp"

Janitor::Janitor(){
    setJobTitle("Janitor");
    
    //Janitor Finances
    setJobSalary(2500);
    updateBankBalance(300);
    updateEmergencyFund(200);
    updateSavingsFund(0);
    updateRetirementAccount(0);
    
    //Janitor Expenses
    setTithePayment(getJobSalary()*.1);
    updateMortgageBalance(190000);
    setMortgagePayment(getMortgageBalance() * .0045);
    setUtilitiesPayment(250);
    setGroceriesPayment(350);
    setInsurancePayment(180);
    setInternetPayment(60);
    setCablePayment(60);
    setMusicServicePayment(15);
    setMovieServicePayment(10);
    setFunMoneyPayment(100);
    
    //Janitor Debt
    updateCreditCardsBalance(15000);
    setCreditCardsPayment(getCreditCardBalance()*.02);
    updateStudentLoanBalance(3000);
    setStudentLoansPayment(getStudentLoanBalance()*.02);
    updateCarLoanBalance(12000);
    setCarLoanPayment(getCarLoanBalance()*.02);
    updateTotalOfUnpaidBills(0);
}

Janitor::~Janitor(){
    
}
