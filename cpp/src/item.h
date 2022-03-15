#ifndef SHOPPINGBASKET_ITEM_H
#define SHOPPINGBASKET_ITEM_H

class ItemQuantity
{
public:
    int quantity_;
    float price_;
    ItemQuantity(int quantity, float price): quantity_(quantity), price_(price){};
};

#endif //SHOPPINGBASKET_ITEM_H
