#ifndef HANDLERS_H
#define HANDLERS_H

#include "inventory.h"
#include <string>

enum Command {
    ADD,
    REMOVE,
    LIST,
    SAVE,
    LOAD,
    EXIT,
    UPDATE,
    SORT_PRICE,
    SORT_NAME,
    INVALID
};
bool compareItemsByName(const Item& item1, const Item& item2);
bool compareItemsByPrice(const Item& item1, const Item& item2);
void handleAdd(Inventory& inventory);
void handleRemove(Inventory& inventory);
void handleUpdate(Inventory& inventory);
void handleSave(Inventory& inventory);
void handleLoad(Inventory& inventory);
void handleSort(Inventory& inventory, const std::string& by);
void printInventory(const Inventory& inventory);
void printItems(const std::vector<Item>& items);
void runInventory();

#endif // HANDLERS_H
