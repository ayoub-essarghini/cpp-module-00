#include "Account.hpp"
#include <iostream>

Account::Account( int initial_deposit ) : _amount(initial_deposit), _nbDeposits(0),
 _nbWithdrawals(0) {
    _displayTimestamp();
    _accountIndex = _nbAccounts++;
    _totalAmount += _amount;
    _totalNbDeposits++;
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account( void ) {
    _displayTimestamp();
    _totalAmount -= _amount;
    _nbAccounts--;
    _totalNbWithdrawals++;
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::_displayTimestamp( void ) {
   
}

void Account::makeDeposit( int deposit ) {
    _displayTimestamp();
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}


