/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Account.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wsonepou <wsonepou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/16 14:03:50 by wsonepou      #+#    #+#                 */
/*   Updated: 2024/12/16 18:50:39 by wsonepou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include "Account.hpp"

// Getters
int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}


// Functions
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout	<< "accounts:" << _nbAccounts << ";"
				<< "total:" << _totalAmount << ";"
				<< "deposits" << _totalNbDeposits << ";"
				<< "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_amount += deposit;
	_nbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_amount -= withdrawal;
	_nbWithdrawals++;
}

int		Account::checkAmount(void) const
{
	
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "total:" << _amount << ";"
				<< "deposits" << _nbDeposits << ";"
				<< "withdrawals:" << _nbWithdrawals << std::endl;	
}

void	Account::_displayTimestamp( void )
{
    std::time_t current = std::time(0);
    std::tm *local_time = std::localtime(&current);
	std::cout 	<< "[" << local_time->tm_year + 1900
				<< local_time->tm_mon + 1
				<< local_time->tm_mday
				<< "-"
				<< local_time->tm_hour
				<< local_time->tm_min
				<< local_time->tm_sec
				<< "] ";
}


// Constructors & destructor
Account::Account(int initial_deposit)
{
	_nbAccounts = ;
	_totalAmount = ;
	_totalNbDeposits = 0;
	_totalNbWithdrawals = 0;
}

Account::~Account()
{
	
}

