#include <gtest/gtest.h>

#include "item.h"
#include "shopping_basket.h"

using namespace std;

TEST(ShoppingBasket, Prices) {
    std::vector<ItemQuantity> items = {};
    std::vector<ItemQuantity> all_items = {ItemQuantity(1, 50),
                                           ItemQuantity(2, 25),
                                           ItemQuantity(1, 25),
                                           ItemQuantity(1, 10),
                                           ItemQuantity(1, 100)
    };
    std::vector<float> prices = {50, 100, 118.75, 128.25, 211.5};
    for (unsigned int i = 0; i < 5; i++) {
        items.push_back(all_items.at(i));
        ASSERT_NEAR(prices.at(i), price(items), 0.01);
    }
}

