#ifndef INVENTORY_H
#define INVENTORY_H

#include <map>
#include "item.h"
#include <fstream>
#include <vector>
#include <algorithm>

// Comparison functions for sorting
bool compareItemsByName(const Item& a, const Item& b) {
    return a.getName() < b.getName();
}

bool compareItemsByPrice(const Item& a, const Item& b) {
    return a.getPrice() < b.getPrice();
}

class Inventory {
public:
    void addItem(const Item& item) {
        _items[item.getName()] = item;
    }

    void removeItem(const std::string& itemName) {
        _items.erase(itemName);
    }

    //getter function for Inventory 
    std::map<std::string, Item> getItems() const {
        return _items;
    }

     std::vector<Item> sortByPrice() const {
        std::vector<Item> sortedItems;
        for (std::map<std::string, Item>::const_iterator it = _items.begin(); it != _items.end(); ++it) {
            sortedItems.push_back(it->second);
        }

        std::sort(sortedItems.begin(), sortedItems.end(), compareItemsByPrice);
        return sortedItems;
    }

    std::vector<Item> sortByName() const {
        std::vector<Item> sortedItems;
        for (std::map<std::string, Item>::const_iterator it = _items.begin(); it != _items.end(); ++it) {
            sortedItems.push_back(it->second);
        }

        std::sort(sortedItems.begin(), sortedItems.end(), compareItemsByName);
        return sortedItems;
    }

    bool updateItem(const std::string& itemName, int quantity, double price) {
        auto it = _items.find(itemName);
        if (it != _items.end()) {
            it->second.setQuantity(quantity);
            it->second.setPrice(price);
            return true;
        }
        return false;
    }

     void saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        for(const auto& pair : _items) {
            const Item& item = pair.second;
            file << item.getName() << ' ' << item.getQuantity() << ' ' << item.getPrice() << '\n';
        }
        file.close();
    }

    bool loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) return false;

        _items.clear(); // Clear current inventory

        std::string name;
        int quantity;
        double price;
        while(file >> name >> quantity >> price) {
            addItem(Item(name, quantity, price));
        }
        file.close();

        return true;
    }

private:
    std::map<std::string, Item> _items;
};


#endif // INVENTORY_H
