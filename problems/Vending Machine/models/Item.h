#ifndef _ITEM_H_
#define _ITEM_H_
#include "common.h"

class Item {
    ItemType itemType_;
    int price_;
public:
    Item(ItemType itemType, int price): itemType_(itemType), price_(price) {}
    int getPrice() {
        return price_;
    }

    ItemType getItemType() {
        return itemType_;
    }

    void setItemType(ItemType itemType) {
        itemType_ = itemType;
    }

    void setPrice(int price) {
        price_ = price;
    }
};

#endif //_ITEM_H_