#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <map>

using namespace std;

enum ItemType {
    COKE,
    PEPSI,
    JUICE,
    CHIPS
};

enum CoinType {
    PENNY = 1,
    NICKLE = 5,
    DIME = 10,
    QUARTER = 25
};

class NotImplemented : public logic_error
{
public:
    NotImplemented() : logic_error("Function not yet implemented") { };
};

#endif //COMMON_H