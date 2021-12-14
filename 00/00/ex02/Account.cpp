/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmander <rmander@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:50:52 by rmander           #+#    #+#             */
/*   Updated: 2021/12/14 21:05:53 by rmander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <ctime>
#include <iostream>


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


void Account::_displayTimestamp( void ) {
	char buff[16];
	std::time_t time = std::time(nullptr);
	std::tm* ptime = std::localtime(&time);

	std::strftime(buff, 16, "%Y%m%d_%H%M%S", ptime);
	std::cout<<"["<<buff<<"]"<<" ";
}


Account::Account( int initial_deposit ) : _accountIndex(Account::_nbAccounts),
																					_amount(initial_deposit),
																					_nbDeposits(0),
																					_nbWithdrawals(0) {
	Account::_displayTimestamp();

	std::cout<<"index:"<<_accountIndex<<";"
		<<"amount:"<<checkAmount()<<";"
		<<"created"<<std::endl;

	Account::_nbAccounts++;
	Account::_totalAmount += checkAmount();
}

Account::~Account() {
	Account::_totalAmount -= checkAmount();
	Account::_nbAccounts--;
	Account::_totalNbDeposits -= _nbDeposits;
	Account::_totalNbWithdrawals -= _nbWithdrawals;

	Account::_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";"
		<<"amount:"<<checkAmount()<<";"<<"closed"
		<<std::endl;
}

int Account::getNbAccounts( void ) {
	return _nbAccounts;
}


int Account::getTotalAmount( void ) {
	return _totalAmount;
}


int Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}


int Account::getNbWithdrawals() {
	return _totalNbWithdrawals;
}


void Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();

	std::cout<<"accounts:"<<Account::getNbAccounts()<<";"
		<<"total:"<<Account::getTotalAmount()<<";"
		<<"deposits:"<<Account::getNbDeposits()<<";"
		<<"withdrawals:"<<Account::getNbWithdrawals()
		<<std::endl;
}


void Account::displayStatus( void ) const {
	Account::_displayTimestamp();

	std::cout<<"index:"<<_accountIndex<<";"
		<<"amount:"<<checkAmount()<<";"
		<<"deposits:"<<_nbDeposits<<";"
		<<"withdrawals:"<<_nbWithdrawals
		<<std::endl;
}


int Account::checkAmount( void ) const {
	return _amount;
}


void Account::makeDeposit( int deposit ) {
	int p_amount = checkAmount();

	++_nbDeposits;
	++_totalNbDeposits;
	_amount += deposit;
	_totalAmount += deposit;

	Account::_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";"
		<<"p_amount:"<<p_amount<<";"
		<<"deposit:"<<deposit<<";"
		<<"amount:"<<checkAmount()<<";"
		<<"nb_deposits:"<<_nbDeposits
		<<std::endl;
}

bool Account::makeWithdrawal( int withdrawal ) {
	int p_amount = checkAmount();
	
	Account::_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";"
		<<"p_amount:"<<p_amount<<";"
		<<"withdrawal:";

	if (withdrawal > checkAmount()) {
		std::cout<<"refused"<<std::endl;
		return false;
	}

	++_nbWithdrawals;
	++_totalNbWithdrawals;
	_amount -= withdrawal;	
	_totalAmount -= withdrawal;

	std::cout<<withdrawal<<";"
		<<"amount:"<<checkAmount()<<";"
		<<"nb_withdrawals:"<<_nbWithdrawals
		<<std::endl;
	return true;
}
