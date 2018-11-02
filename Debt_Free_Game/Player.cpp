//
//  Player.cpp
//  DEBT_SNOWBALL_GAME
//
//  Created by Lando Shepherd on 10/22/18.
//  Copyright © 2018 Lando Shepherd. All rights reserved.
//

#include "Player.hpp"

Player::Player(){
    //Player Expenses
    tithe = new Expense;
    mortgage = new Expense;
    utilities = new Expense;
    groceries = new Expense;
    insurance = new Expense;
    internet = new Expense;
    cable = new Expense;
    musicService = new Expense;
    movieService = new Expense;
    funMoney = new Expense;
    
    //Player Debt
    creditCards = new Expense;
    studentLoans = new Expense;
    carLoan = new Expense;
    totalOfUnpaidBills = new Expense;
    
    expenses.push_back(tithe);
    expenses.push_back(mortgage);
    expenses.push_back(utilities);
    expenses.push_back(groceries);
    expenses.push_back(insurance);
    expenses.push_back(internet);
    expenses.push_back(cable);
    expenses.push_back(musicService);
    expenses.push_back(movieService);
    expenses.push_back(funMoney);
    expenses.push_back(creditCards);
    expenses.push_back(studentLoans);
    expenses.push_back(carLoan);
    expenses.push_back(totalOfUnpaidBills);
}

//**************************************************************
//Player Stats
void Player::setPlayerAge(int _age){
    playerAge = _age;
}

int Player::getPlayerAge(){
    return playerAge;
}

void Player::setJobTitle(std::string _jobTitle){
    jobTitle = _jobTitle;
}

std::string Player::getJobTitle(){
    return jobTitle;
}

void Player::setJobSalary(float _jobSalary){
    jobSalary = _jobSalary;
}

float Player::getJobSalary(){
    return jobSalary;
}

void Player::updateEmergencyFund(float _emergencyFund){
    emergencyFund = _emergencyFund;
}

float Player::getEmergencyFund(){
    return emergencyFund;
}

void Player::updateBankBalance(float _bankBalance){
    bankBalance = _bankBalance;
}

float Player::getBankBalance(){
    return bankBalance;
}

void Player::updateSavingsFund(float _savingsFund){
    savings = _savingsFund;
}

float Player::getSavingsFund(){
    return savings;
}

void Player::updateRetirementAccount(float _retirement){
    retirement = _retirement;
}

float Player::getRetirementAccount(){
    return retirement;
}

void Player::addExpense(Expense* newExpense){
    expenses.push_back(newExpense);
}

std::vector<Expense*> Player::getExpenses(){
    return expenses;
}

void Player::setTithePayment(float tithePayment){
    tithe->updatePayment(tithePayment);
}

float Player::getTithePayment(){
    return tithe->getPayment();
}

void Player::setMortgagePayment(float mortgagePayment){
    mortgage->updatePayment(mortgagePayment);
}

float Player::getMortgagePayment(){
    return mortgage->getPayment();
}

void Player::updateMortgageBalance(float mortgageBalance){
    mortgage->updateBalance(mortgageBalance);
}

float Player::getMortgageBalance(){
    return mortgage->getBalance();
}

void Player::setUtilitiesPayment(float utilitiesPayment){
    utilities->updatePayment(utilitiesPayment);
}

float Player::getUtilitiesPayment(){
    return utilities->getPayment();
}

void Player::setGroceriesPayment(float groceriesPayment){
    groceries->updatePayment(groceriesPayment);
}

float Player::getGroceriesPayment(){
    return groceries->getPayment();
}

void Player::setInsurancePayment(float insurancePayment){
    insurance->updatePayment(insurancePayment);
}

float Player::getInsurancePayment(){
    return insurance->getPayment();
}

void Player::setInternetPayment(float internetPayment){
    internet->updatePayment(internetPayment);
}

float Player::getInternetPayment(){
    return internet->getPayment();
}

void Player::setCablePayment(float cablePayment){
    cable->updatePayment(cablePayment);
}

float Player::getCablePayment(){
    return cable->getPayment();
}

void Player::setMusicServicePayment(float musicPayment){
    musicService->updatePayment(musicPayment);
}

float Player::getMusicServicePayment(){
    return musicService->getPayment();
}

void Player::setMovieServicePayment(float moviePayment){
    movieService->updatePayment(moviePayment);
}

float Player::getMovieServicePayment(){
    return movieService->getPayment();
}

void Player::setFunMoneyPayment(float funMoneyPayment){
    funMoney->updatePayment(funMoneyPayment);
}

float Player::getFunMoneyPayment(){
    return funMoney->getPayment();
}

void Player::setCreditCardsPayment(float ccPayment){
    creditCards->updatePayment(ccPayment);
}

float Player::getCreditCardsPayment(){
    return creditCards->getPayment();
}

void Player::updateCreditCardsBalance(float newBalance){
    creditCards->updateBalance(newBalance);
}

float Player::getCreditCardBalance(){
    return creditCards->getBalance();
}

void Player::setStudentLoansPayment(float slPayment){
    studentLoans->updatePayment(slPayment);
}

float Player::getGetStudentLoansPayment(){
    return studentLoans->getPayment();
}

void Player::updateStudentLoanBalance(float newBalance){
    studentLoans->updateBalance(newBalance);
}

float Player::getStudentLoanBalance(){
    return studentLoans->getBalance();
}

void Player::setCarLoanPayment(float clPayment){
    carLoan->updatePayment(clPayment);
}

float Player::getCarLoanPayment(){
    return carLoan->getPayment();
}

void Player::updateCarLoanBalance(float newBalance){
    carLoan->updateBalance(newBalance);
}

float Player::getCarLoanBalance(){
    return carLoan->getBalance();
}

void Player::updateTotalOfUnpaidBills(float bills){
    totalOfUnpaidBills->updateBalance(bills);
}

float Player::getTotalOfUnpaidBills(){
    return totalOfUnpaidBills->getBalance();
}

Player::~Player(){
    
}
