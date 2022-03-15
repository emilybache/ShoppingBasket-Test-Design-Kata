#include <gtest/gtest.h>

#include "item.h"
#include "shopping_basket.h"

using namespace std;

TEST(ShoppingBasket, Price)
{
    std::vector<ItemQuantity> items = {};
    ASSERT_NEAR(0, price(items), 0.01);
    items = {ItemQuantity(1, 50)};
    ASSERT_EQ(50, price(items));
    items = {ItemQuantity(2, 25)};
    ASSERT_EQ(50, price(items));
    items  = {ItemQuantity(1, 25), ItemQuantity(1, 10)};
    ASSERT_EQ(35, price(items));
    items  = {ItemQuantity(1, 100), ItemQuantity(1, 50)};
    ASSERT_NEAR(142, price(items), 0.5);
    items  = {ItemQuantity(1, 200), ItemQuantity(1, 20)};
    ASSERT_NEAR(198, price(items), 0.5);
}