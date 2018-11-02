//
//  Gameplay.cpp
//  DEBT_SNOWBALL_GAME
//
//  Created by Lando Shepherd on 10/20/18.
//  Copyright © 2018 Lando Shepherd. All rights reserved.
//

#include "DFSGame.hpp"

DFSGame::DFSGame(){
    srand(time(NULL));
    newPlayer = new Janitor;
    assert(newPlayer);
    
    numOfNew = 0;
    numOfDelete = 0;
    numOfNew++;
    
    //Creates a list to of careers to randomly choose from.
    careers[0] = "Janitor";
    careers[1] = "Engneer";
    careers[2] = "Nurse";
    careers[3] = "Teacher";
    careers[4] = "Doctor";
}

void DFSGame::displayGameTitle(){
    std::cout << std::right << std::setw(60)<< "Debt Free Snowball: The Game" << std::endl;
    std::cout << std::right << std::setw(48) << "BETA" << std::endl;
    std::cout << "***********************************************************"
    "**************************************" << std::endl;
}

void DFSGame::viewMainMenu(){
    displayGameTitle();
    std::cout << "A. Play Game" << std::endl;
    std::cout << "B. Instructions" << std::endl;
    std::cout << "C. Quit Game" << std::endl;
    return;
}

//Allows for program to validate user input for the main menu.
//This may be put into a validation class strictly for this game.
bool DFSGame::validateMenuChoice(char choice){
    if(choice == 'A' || choice == 'B' || choice == 'C'){
        return true;
    }
    else{
        std::cout << "Invalid Entry." << std::endl;
        return false;
    }
}

void DFSGame::getPlayerAge(){
    std::cout << "Enter Age: ";
    std::cin >> playerAge;                          //Validate
    newPlayer->setPlayerAge(playerAge);
}

//Allows for initial game setup
char DFSGame::setupGame(){
    char choice;
    char modified_Choice;
    do{
        viewMainMenu();
        std::cin >> choice;                       //Validate
        modified_Choice = toupper(choice);
    } while (!validateMenuChoice(modified_Choice));
    getPlayerAge();
    return modified_Choice;
}

void DFSGame::viewStats(int count){
    updateTotals();
    std::cout << std::fixed << std::setprecision(2);
    displayGameTitle();
    std::cout << std::right << std::setw(35) << "Year: " << std::left << std::setw(8)
    << year << "Total Debt: $" << totalDebt << std::endl;
    std::cout << "Day: " << count << std::endl;
    std::cout << "Age: " << newPlayer->getPlayerAge() << std::endl;
    std::cout << "Job Title: " << newPlayer->getJobTitle() << std::endl;
    std::cout << "Salary/Month: $" << newPlayer->getJobSalary() << std::endl;
    std::cout << "Bank Balance: $" << newPlayer->getBankBalance() << std::endl;
    std::cout << "Emergency Fund: $" << newPlayer->getEmergencyFund() << std::endl;
    std::cout << "Savings: $" << newPlayer->getSavingsFund() << std::endl;
    std::cout << "Retirement: $" << newPlayer->getRetirementAccount() << std::endl;
    std::cout << std::endl;
}

void DFSGame::viewExpenses(){
    updateTotals();
    displayGameTitle();
    std::cout << "Tithe: $" << newPlayer->getTithePayment() << std::endl;
    std::cout << "Mortgage Payment: $" << newPlayer->getMortgagePayment() << std::endl;
    std::cout << "Utilities: $" << newPlayer->getUtilitiesPayment() << std::endl;
    std::cout << "Groceries: $" << newPlayer->getGroceriesPayment() << std::endl;
    std::cout << "Insurance: $" << newPlayer->getInsurancePayment() << std::endl;
    std::cout << "Internet: $" << newPlayer->getInternetPayment() << std::endl;
    std::cout << "Cable: $" << newPlayer->getCablePayment() << std::endl;
    std::cout << "Music Service: $" << newPlayer->getMusicServicePayment() << std::endl;
    std::cout << "Movie Service: $" << newPlayer->getMovieServicePayment() << std::endl;
    std::cout << "Fun Money: $" << newPlayer->getFunMoneyPayment() << std::endl;
    std::cout << std::endl;
    std::cout << "Press [B] to go back" << std::endl;
    //Validate input
}

void DFSGame::viewDebt(){
    displayGameTitle();
    std::cout << "A. Student Loan" << std::endl;
    std::cout << "   Balance: $" << newPlayer->getStudentLoanBalance() << std::endl;
    std::cout << "   Payment: $" << newPlayer->getGetStudentLoansPayment() << std::endl;
    std::cout << std::endl;
    std::cout << "B. Credit Card" << std::endl;
    std::cout << "   Balance: $" << newPlayer->getCreditCardBalance() << std::endl;
    std::cout << "   Payment: $" << newPlayer->getCreditCardsPayment() << std::endl;
    std::cout << std::endl;
    std::cout << "C. Car Loan" << std::endl;
    std::cout << "   Balance: $" << newPlayer->getCarLoanBalance() << std::endl;
    std::cout << "   Payment: $" << newPlayer->getCarLoanPayment() << std::endl;
    std::cout << std::endl;
    std::cout << "D. Mortgage" << std::endl;
    std::cout << "   Balance: $" << newPlayer->getMortgageBalance() << std::endl;
    std::cout << std::endl;
    std::cout << "E. Total of Backed Up Expenses" << std::endl;
    std::cout << "   Balance: $" << newPlayer->getTotalOfUnpaidBills() << std::endl;
    std::cout << std::endl;
    std::cout << std::left << std::setw(35)<< "Press [P] to make a payment" << std::left
    << std::setw(25)<< "Press [B] to go back" << std::endl;
}

void DFSGame::viewAccounts(){
    displayGameTitle();
    std::cout << "A. Bank Account: $" << newPlayer->getBankBalance() << std::endl;
    std::cout << "B. Emergency Fund: $" << newPlayer->getEmergencyFund() << std::endl;
    std::cout << "C. Savings Account: $" << newPlayer->getSavingsFund() << std::endl;
    std::cout << "D. Retirement Account: $" << newPlayer->getRetirementAccount() << std::endl;
    std::cout << std::endl;
}

void DFSGame::payDebt(char debt){
    float payment = 0;
    std::cout << "How much would you like to pay?" << std::endl;
    std::cout << "Payment: ";
    std::cin >> payment;
    if (debt == 'A'){
        if (payment > newPlayer->getBankBalance()){
            std::cout << "Insufficient funds." << std::endl;
        }
        else if(payment > newPlayer->getStudentLoanBalance()){
            std::cout << "Sallie Mae has evicted! Don't keep paying her!" << std::endl;
        }
        else{
            newPlayer->updateBankBalance(newPlayer->getBankBalance()-payment);
            newPlayer->updateStudentLoanBalance(newPlayer->getStudentLoanBalance()-payment);
            std::cout << "Student loan payment successful!" << std::endl;
        }
    }
    else if(debt == 'B'){
        if (payment > newPlayer->getBankBalance()){
            std::cout << "Insufficient funds." << std::endl;
        }
        else if(payment > newPlayer->getCreditCardBalance()){
            std::cout << "Keep your money! Don't give it to credit card companies!" << std::endl;
        }
        else{
            newPlayer->updateBankBalance(newPlayer->getBankBalance()-payment);
            newPlayer->updateCreditCardsBalance(newPlayer->getCreditCardBalance()-payment);
            std::cout << "Credit card payment successful!" << std::endl;
        }
    }
    else if(debt == 'C'){
        if (payment > newPlayer->getBankBalance()){
            std::cout << "Insufficient funds." << std::endl;
        }
        else if(payment > newPlayer->getCarLoanBalance()){
            std::cout << "Why continue to pay for a paid for car?!" << std::endl;
        }
        else{
            newPlayer->updateBankBalance(newPlayer->getBankBalance()-payment);
            newPlayer->updateCarLoanBalance(newPlayer->getCarLoanBalance()-payment);
            std::cout << "Car loan payment successful!" << std::endl;
        }
    }
    else if(debt == 'D'){
        if (payment > newPlayer->getBankBalance()){
            std::cout << "Insufficient funds." << std::endl;
        }
        else if(payment > newPlayer->getMortgageBalance()){
            std::cout << "Whoa! Whoa! You're house is already paid for! Go on a vacation instead!" << std::endl;
        }
        else{
            newPlayer->updateBankBalance(newPlayer->getBankBalance()-payment);
            newPlayer->updateMortgageBalance(newPlayer->getMortgageBalance()-payment);
            std::cout << "Mortgage payment successful!" << std::endl;
        }
    }
    else if(debt == 'E'){
        if (payment > newPlayer->getBankBalance()){
            std::cout << "Insufficient funds." << std::endl;
        }
        else if(payment > newPlayer->getTotalOfUnpaidBills()){
            std::cout << "Just give them the amount owed. Nothing more and hopefully nothing less." << std::endl;
        }
        else{
            newPlayer->updateBankBalance(newPlayer->getBankBalance()-payment);
            newPlayer->updateTotalOfUnpaidBills(newPlayer->getTotalOfUnpaidBills()-payment);
            std::cout << "Back payments have been paid!" << std::endl;
        }
    }
}

void DFSGame::payDay(int day){
    if (day % 14 == 0){
        std::cout << "It's pay day!" << std::endl;
        newPlayer->updateBankBalance((newPlayer->getJobSalary()/2)+newPlayer->getBankBalance());
    }
}

//This function will be added to the validation class for the game.
bool DFSGame::_validateAccountSelection(char account){
    if (account == 'A' || account == 'B' || account == 'C' || account == 'D' || account == 'T'){
        return true;
    }
    else{
        std::cout << "Invalid entry. Lets try that again." << std::endl;
        return false;
    }
}


bool DFSGame::_validateFundAvailability(char account, float amount){
    //Account must be validated before use of this function.
    if (account == 'A'){
        //Bank account
        if(amount > newPlayer->getBankBalance()){
            std::cout << "Psst! You don't have that much money in this account! Try another one!" << std::endl;
            return false;
        }
        else{
            return true;
        }
    }
    else if(account == 'B'){
        //Emergency fund
        if(amount > newPlayer->getEmergencyFund()){
            std::cout << "Psst! You don't have that much money in this account! Try another one!" << std::endl;
            return false;
        }
        else{
            return true;
        }
    }
    else if(account == 'C'){
        //savings account
        if(amount > newPlayer->getSavingsFund()){
            std::cout << "Psst! You don't have that much money in this account! Try another one!" << std::endl;
            return false;
        }
        else{
            return true;
        }
    }
    else{
        //Retirement account
        if(amount > newPlayer->getRetirementAccount()){
            std::cout << "Psst! You don't have that much money in this account! Try another one!" << std::endl;
            return false;
        }
        else{
            return true;
        }
    }
}

void DFSGame::_makeTransfer(char fromAccount, char toAccount, float amount){
    if (fromAccount == 'A'){
        //Bank account
        newPlayer->updateBankBalance(newPlayer->getBankBalance() - amount);
    }
    else if(fromAccount == 'B'){
        //Emergency fund
        newPlayer->updateEmergencyFund(newPlayer->getEmergencyFund() - amount);
    }
    else if(fromAccount == 'C'){
        //savings account
        newPlayer->updateSavingsFund(newPlayer->getSavingsFund() - amount);
    }
    else{
        //Retirement account
        newPlayer->updateRetirementAccount(newPlayer->getRetirementAccount() - amount);
    }
    
    if (toAccount == 'A'){
        //Bank account
        newPlayer->updateBankBalance(newPlayer->getBankBalance() + amount);
    }
    else if(toAccount == 'B'){
        //Emergency fund
        newPlayer->updateEmergencyFund(newPlayer->getEmergencyFund() + amount);
    }
    else if(toAccount == 'C'){
        //savings account
        newPlayer->updateSavingsFund(newPlayer->getSavingsFund() + amount);
    }
    else{
        //Retirement account
        newPlayer->updateRetirementAccount(newPlayer->getRetirementAccount() + amount);
    }
}

void DFSGame::transferFunds(){
    char action;
    char fromAccount;
    char toAccount;
    bool repeat = true;
    float amount;
    do{
        viewAccounts();
        std::cout << "Select account to transfer FROM or [T] to terminate transaction: ";
        std::cin >> action;
        if(_validateAccountSelection(action)){
            if(action != 'T'){
                fromAccount = action;
                std::cout << "Select account to transfer TO or [T] to terminate transaction: ";
                std::cin >> action;
                if (_validateAccountSelection(action)){
                    if (action != 'T'){
                        toAccount = action;
                        std::cout << "Enter amount you would like to transfer: ";
                        std::cin >> amount;
                        std::cout << std::endl;
                        if (fromAccount != toAccount){
                            if (_validateFundAvailability(fromAccount, amount)){
                                //Make transfer here
                                _makeTransfer(fromAccount, toAccount, amount);
                            }
                            else{
                                repeat = true;
                            }
                        }
                        else{
                            std::cout << "Oy! The accounts you've selected are the same! Try again!" << std::endl;
                            repeat = true;
                        }
                    }
                    else{
                        std::cout << "Transaction canceled." << std::endl;
                        repeat = false;
                    }
                }
            }
            else{
                std::cout << "Transaction canceled." << std::endl;
                repeat = false;
            }
        }
    } while (repeat);
}

void DFSGame::updateTotals(){
    totalDebt = newPlayer->getStudentLoanBalance() + newPlayer->getCarLoanBalance()
    + newPlayer->getCreditCardBalance() + newPlayer->getTotalOfUnpaidBills();
    
    totalExpenses = newPlayer->getTithePayment() + newPlayer->getUtilitiesPayment() + newPlayer->getMortgagePayment()
    + newPlayer->getGroceriesPayment() + newPlayer->getInsurancePayment() + newPlayer->getInternetPayment()
    + newPlayer->getCablePayment() + newPlayer->getMusicServicePayment() + newPlayer->getMovieServicePayment()
    + newPlayer->getFunMoneyPayment();
}

void DFSGame::autoPay(int day){
    bool allBillsPaid = true;
    
    if(day%30 == 0){
        for (int i = 0; i < newPlayer->getExpenses().size(); i++){
            if(newPlayer->getBankBalance() >= newPlayer->getExpenses()[i]->getPayment()){
                newPlayer->updateBankBalance(newPlayer->getBankBalance() - newPlayer->getExpenses()[i]->getPayment());
                newPlayer->getExpenses()[i]->updateBalance(newPlayer->getExpenses()[i]->getBalance() - newPlayer->getExpenses()[i]->getPayment());
            }
            else{
                newPlayer->updateTotalOfUnpaidBills(newPlayer->getTotalOfUnpaidBills() + newPlayer->getExpenses()[i]->getPayment());
                allBillsPaid = false;
            }
        }
        if (allBillsPaid == false){
            std::cout << "WARNING: ALL OR SOME BILLS WERE NOT PAID AND WILL ROLL OVER TO NEXT MONTH" << std::endl;
            std::cout << "Check your 'Unpaid Bills' amount in the 'View Debt' tab to catch back up!" << std::endl;
        }
        else{
            std::cout << "It's bills day and all the bills were paid!" << std::endl;
        }
    }
}

void DFSGame::startGame(){
    char player_Choice = setupGame();
    
    if (player_Choice == 'A'){
        int day = 1;
        bool quit = false;
        char action;
        bool continueDay = true;
        bool nextDay;
        do{
            nextDay = true;
            do{
                updateTotals();
                viewStats(day);
                
                if (nextDay == true){
                    payDay(day);
                    autoPay(day);
                    nextDay = false;
                }
                
                //Random event happens here.
                std::cout << std::setw(29)<< "Press [A] to View Expenses" << std::left
                << std::setw(25)<< "Press [B] to View Debt"
                << std::left << std::setw(25) << "Press [N] for Next Day"
                << std::left << std::setw(20) << "Press [Q] to Quit" << std::endl;
                std::cout << "Press [T] to transfer funds" << std::endl;
                std::cin >> action;
                if (action == 'A'){
                    viewExpenses();
                    std::cin >> action;
                    continueDay = true;
                    quit = false;
                }
                else if(action == 'B'){
                    bool goToMainScreen = false;
                    do{
                        viewDebt();
                        std::cin >> action;
                        if (action == 'P'){
                            //Make payment
                            char debt;
                            std::cout << "Select debt with respective button shown above: ";
                            std::cin >> debt;
                            if (debt == 'A' || debt == 'B' || debt == 'C' || debt == 'D' || debt == 'E'){
                                payDebt(debt);
                            }
                            else{
                                std::cout << "Invalid input. Try again." << std::endl;
                            }
                            goToMainScreen = false;
                        }
                        else if(action == 'B'){
                            goToMainScreen = true;
                        }
                    } while (goToMainScreen == false);
                    continueDay = true;
                    quit = false;
                }
                else if(action == 'T'){
                    transferFunds();
                    continueDay = true;
                    quit = false;
                }
                else if(action == 'N'){
                    continueDay = false;
                    quit = false;
                    day++;
                }
                else if(action == 'Q'){
                    continueDay = false;
                    quit = true;
                }
            } while (continueDay == true);
        } while (quit == false);
    }
    else if(player_Choice == 'B'){
        std::cout << "Now viewing the instructions." << std::endl;
    }
    else if (player_Choice == 'C'){
        std::cout << "Thanks for playing!" << std::endl;
    }
    return;
}

DFSGame::~DFSGame(){
    for (int i = 0; i < newPlayer->getExpenses().size(); i++){
        delete newPlayer->getExpenses()[i];
    }
    delete newPlayer;
}

