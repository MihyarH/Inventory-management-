#include "handlers.h"
#include <iostream>
#include "item.h"

Command resolveCommand(const std::string& command) {
    if (command == "add") {
        return ADD;
    } else if (command == "remove") {
        return REMOVE;
    } else if (command == "list") {
        return LIST;
    } else if (command == "save") {
        return SAVE;
    } else if (command == "load") {
        return LOAD;
    } else if (command == "exit") {
        return EXIT;
    } else if (command == "update") {
        return UPDATE;
    } else if (command == "sort_price") {
        return SORT_PRICE;
    } else if (command == "sort_name") {
        return SORT_NAME;
    } else {
        return INVALID;
    }
}


void printInventory(const Inventory& inventory) {
    std::map<std::string, Item> items = inventory.getItems();
    std::map<std::string, Item>::const_iterator it;
    for (it = items.begin(); it != items.end(); it++) {
        const Item& item = it->second;
        std::cout << "Item name: " << item.getName()
                  << ", quantity: " << item.getQuantity()
                  << ", price: " << item.getPrice() << '\n';
    }
}

void printItems(const std::vector<Item>& items) {
    for (const auto& item : items) {
        std::cout << "Item name: " << item.getName()
                  << ", quantity: " << item.getQuantity()
                  << ", price: " << item.getPrice() << '\n';
    }
}

void handleAdd(Inventory& inventory) {
    std::string name;
    int quantity;
    double price;
    std::cout << "Enter item name, quantity, and price: ";
    std::cin >> name >> quantity >> price;
    inventory.addItem(Item(name, quantity, price));
}

void handleRemove(Inventory& inventory) {
    std::string name;
    std::cout << "Enter item name: ";
    std::cin >> name;
    inventory.removeItem(name);
}

void handleUpdate(Inventory& inventory) {
    std::string name;
    int quantity;
    double price;
    std::cout << "Enter item name, new quantity, and new price: ";
    std::cin >> name >> quantity >> price;
    if (!inventory.updateItem(name, quantity, price)) {
        std::cout << "Item not found.\n";
    }
}

void handleSave(Inventory& inventory) {
    std::string filename;
    std::cout << "Enter filename to save: ";
    std::cin >> filename;
    inventory.saveToFile(filename);
}

void handleLoad(Inventory& inventory) {
    std::string filename;
    std::cout << "Enter filename to load: ";
    std::cin >> filename;
    if (!inventory.loadFromFile(filename)) {
        std::cout << "Could not open file.\n";
    }
}

void handleSort(Inventory& inventory, const std::string& type) {
    if(type == "price") {
        printItems(inventory.sortByPrice());
    } else if (type == "name") {
        printItems(inventory.sortByName());
    }
}

void runInventory() {
    Inventory inventory;
    bool running = true;

    while (running) {
        std::cout << "Enter command (add/update/remove/list/sort_price/sort_name/save/load/exit): ";
        std::string command;
        std::cin >> command;

        switch (resolveCommand(command)) {
            case ADD:
                handleAdd(inventory);
                break;
            case REMOVE:
                handleRemove(inventory);
                break;
            case LIST:
                printInventory(inventory);
                break;
            case SAVE:
                handleSave(inventory);
                break;
            case LOAD:
                handleLoad(inventory);
                break;
            case EXIT:
                running = false;
                break;
            case UPDATE:
                handleUpdate(inventory);
                break;
            case SORT_PRICE:
                handleSort(inventory, "price");
                break;
            case SORT_NAME:
                handleSort(inventory, "name");
                break;
            default:
                std::cout << "Invalid command. Please enter again.\n";
                break;
        }
    }
}
