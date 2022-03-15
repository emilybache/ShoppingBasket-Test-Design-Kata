#include <gtest/gtest.h>

#include "item.h"
#include "shopping_basket.h"

using namespace std;


TEST(ShoppingBasket, Empty) {
    std::vector<ItemQuantity> items = {};
    float p = price(items);
    ASSERT_NEAR(0, p, 0.01);
}

TEST(ShoppingBasket, One_item) {
    auto items = {ItemQuantity(1, 50)};
    float p = price(items);
    ASSERT_EQ(50, p);
}

TEST(ShoppingBasket, Two_Same_item) {
    auto items = {ItemQuantity(2, 25)};
    float p = price(items);
    ASSERT_EQ(50, p);
}

TEST(ShoppingBasket, Two_differet_item) {
    auto items = {ItemQuantity(1, 25), ItemQuantity(1, 10)};
    float p = price(items);
    ASSERT_EQ(35, p);
}

TEST(ShoppingBasket, Discount_5) {
    auto items = {ItemQuantity(1, 150)};
    float p = price(items);
    ASSERT_NEAR(142.5, p, 0.01);
}

TEST(ShoppingBasket, Discount_10) {
    auto items = {ItemQuantity(1, 220)};
    float p = price(items);
    ASSERT_NEAR(198, p, 0.01);
}

