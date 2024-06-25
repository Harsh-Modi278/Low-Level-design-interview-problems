#ifndef _COMMON_H_
#define _COMMON_H_

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

enum ATMStateType {
    IDLE,
    HAS_CARD,
    OPERATION_SELECTION,
    CHECK_BALANCE,
    CASH_WITHDRAWAL
};

vector<string> ATMStateToNameMapping = {
    "Idle",
    "HasCard",
    "Operation_Selection",
    "Check_Balance",
    "Cash_Withdrawal"
};

enum OperationTypes {
    CHECK__BALANCE,
    CASH__WITHDRAWAL
};

enum CurrencyType {
    TWO_THOUSAND,
    FIVE_HUNDRED,
    HUNDRED
};

class NotImplemented : public logic_error
{
public:
    NotImplemented() : logic_error("Function not yet implemented") { };
};

#endif //_COMMON_H_