#ifndef _ITEM_SHELF_H
#define _ITEM_SHELF_H

#include "Item.h"

class ItemShelf {
    int itemCode_;
    deque<Item*> items_;
public:
    ItemShelf(int code): itemCode_(code) {};

    bool isSoldOut() {
        return items_.size() == 0;
    }

    void setItemCode(int code) {
        itemCode_ = code;
    }

    int getItemCode() {
        return itemCode_;
    }

    void addItem(Item* newItem) {
        items_.push_back(newItem);
    }

    Item* getItem() {
        if (items_.size() == 0) {
            cout<<"item sold out\n";
            return nullptr;
        }

        Item* item = items_.front();
        items_.pop_front();
        return item;
    }

    void show() {
        cout<<"\nitem code: "<<itemCode_<<" : items count: "<<items_.size()<<" \n";
    }

    int getPrice() {
        if (items_.size() > 0) {
            return items_[0]->getPrice();
        }

        return -1;
    }
};

#endif //_ITEM_SHELF_H