#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    Item(const std::string& name = "", int quantity = 0, double price = 0.0)
        : _name(name), _quantity(quantity), _price(price) {}

    //defining getters and setters
    std::string getName() const { return _name; }
    int getQuantity() const { return _quantity; }
    double getPrice() const { return _price; }

    void setQuantity(int quantity) { _quantity = quantity; }
    void setPrice(double price) { _price = price; }

private:
    std::string _name;
    int _quantity;
    double _price;
};

#endif // ITEM_H
