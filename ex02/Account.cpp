#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0),
                                        _nbWithdrawals(0)
{
    _displayTimestamp();
    _accountIndex = _nbAccounts++;
    _totalAmount += _amount;
    _totalNbDeposits++;
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    _totalAmount -= _amount;
    _nbAccounts--;
    _totalNbWithdrawals++;
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::_displayTimestamp(void)
{
    auto now = std::chrono::system_clock::now();

    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    std::tm *localTime = std::localtime(&currentTime);

  std::cout << "["
              << std::put_time(localTime, "%Y%m%d_%H%M%S")
              << "]";
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    if (_amount < withdrawal)
    {
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount + withdrawal << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

int Account::checkAmount(void) const
{
    return _amount;
}

int Account::getNbAccounts(void)
{
    return _nbAccounts;
}
int Account::getTotalAmount(void)
{
    return _totalAmount;
}

int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}
int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}
