#pragma once

#include <iostream>

class Transactie
{
public:
	Transactie(int _transactionValue);
	int ReturnTransactionValue() const;
	std::string GetTheTransactionDate() const;

private:
	std::string date;
	int transactionValue = 0;
};