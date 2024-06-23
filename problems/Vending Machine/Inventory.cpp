#ifndef _INVENTORY_H_
#define _INVENTORY_H_

#include "models/ItemShelf.h"

class Inventory {
    vector<ItemShelf*> inventory_;

    void initEmptyInventory() {
        int code = 101;
        for (int i=0;i<inventory_.size();i++,code++) {
            ItemShelf* shelf = new ItemShelf(code);
            inventory_[i] = shelf;
        }
    }
public:
    Inventory(int capacity) {
        inventory_.resize(capacity);
        initEmptyInventory();
    }

    void addItem(Item* item, int code) {
        for (ItemShelf* shelf: inventory_) {
            if (shelf->getItemCode() == code) {
                shelf->addItem(item);
                break;
            }
        }
    }

    Item* getItem(int code) {
        for (ItemShelf* shelf:inventory_) {
            if (shelf->getItemCode() == code) {
                return shelf->getItem();
            }
        }

        return nullptr;
    }

    int getItemPrice(int code) {
        for (ItemShelf* shelf:inventory_) {
            if (shelf->getItemCode() == code) {
                int price = shelf->getPrice();
                return price;
            }
        }
        
        return -1;
    }

    void display() {
        for (int i=0;i<inventory_.size();i++) {
            inventory_[i]->show();
        }
    }
};

#endif //_INVENTORY_H_