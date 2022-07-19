/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:13:43 by hseong            #+#    #+#             */
/*   Updated: 2022/07/18 18:13:43 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>

#include "Account.hpp"

// static member initialization
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// static member functions
int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts;
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals;
	std::cout << "\n";
}

// member functions
Account::Account(int initial_deposit):
	_accountIndex(_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	++_nbAccounts;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";created\n";
}

Account::~Account(void)
{
	--_nbAccounts;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed\n";
}

void	Account::makeDeposit(int deposit)
{
	int		prevAmount = _amount;

	_displayTimestamp();
	_amount += deposit;
	_totalAmount += deposit;
	++_nbDeposits;
	++_totalNbDeposits;
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << prevAmount;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_deposits:" << _nbDeposits;
	std::cout << "\n";
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int		prevAmount = _amount;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << prevAmount;
	if (withdrawal > _amount)
	{
		std::cout << ";withdrawal:refused\n";
		return false;
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	++_nbWithdrawals;
	++_totalNbWithdrawals;
	std::cout << ";withdrawal:" << withdrawal;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_withdrawals:" << _nbWithdrawals;
	std::cout << "\n";
	return true;
}

int		Account::checkAmount(void) const
{
	return _amount;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals;
	std::cout << "\n";
}

void	Account::_displayTimestamp(void)
{
	static time_t	timeVar;
	struct tm		*timeStruct;
	char			prevFill;

	time(&timeVar);
	timeStruct = localtime(&timeVar);
	std::cout << '[';
	prevFill = std::cout.fill('0');
	std::cout << timeStruct->tm_year + 1900;
	std::cout.width(2);
	std::cout << timeStruct->tm_mon + 1;
	std::cout.width(2);
	std::cout << timeStruct->tm_mday << '_';
	std::cout.width(2);
	std::cout << timeStruct->tm_hour;
	std::cout.width(2);
	std::cout << timeStruct->tm_min;
	std::cout.width(2);
	std::cout << timeStruct->tm_sec << "] ";
	std::cout.fill(prevFill);
}

Account::Account(void)
{
}
