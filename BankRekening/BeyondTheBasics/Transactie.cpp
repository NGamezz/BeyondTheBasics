#include "Transactie.h"

Transactie::Transactie(int _transactionValue)
{
	transactionValue = _transactionValue;
}

int Transactie::ReturnTransactionValue() const
{
	return transactionValue;
}
