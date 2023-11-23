#pragma once

class Transactie
{
public:
	Transactie(int _transactionValue);
	int ReturnTransactionValue() const;

private:
	int transactionValue = 0;
};