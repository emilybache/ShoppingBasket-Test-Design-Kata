
#include <gtest/gtest.h>

#include "item.h"
#include "shopping_basket.h"

using namespace std;

TEST(ShoppingBasket, Price_boundaries) {
    std::vector<ItemQuantity> items = {};
    ASSERT_NEAR(0, price(items), 0.01);
    items.emplace_back(1, 50);
    ASSERT_NEAR(50, price(items), 0.01);
    items.emplace_back(1, 50);
    ASSERT_NEAR(100, price(items), 0.01);
    items.emplace_back(1, 50);
    ASSERT_NEAR(150 - 7.5, price(items), 0.01);
    items.emplace_back(1, 50);
    ASSERT_NEAR(200 - 10, price(items), 0.01);
    items.emplace_back(1, 50);
    ASSERT_NEAR(250 - 25, price(items), 0.01);
}