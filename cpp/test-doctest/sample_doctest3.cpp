#include "ApprovalTests.hpp"
#include "doctest/doctest.h"
#include "item.h"
#include "shopping_basket.h"


TEST_CASE("ShoppingBasket, Empty") {
    std::vector<ItemQuantity> items = {};
    float p = price(items);
    REQUIRE(doctest::Approx(0) == p);
}

TEST_CASE("ShoppingBasket, One_item") {
    auto items = {ItemQuantity(1, 50)};
    float p = price(items);
    REQUIRE(doctest::Approx(50) == p);
}

TEST_CASE("ShoppingBasket, Two_Same_item") {
    auto items = {ItemQuantity(2, 25)};
    float p = price(items);
    REQUIRE(doctest::Approx(50) == p);
}

TEST_CASE("ShoppingBasket, Two_differet_item") {
    auto items = {ItemQuantity(1, 25), ItemQuantity(1, 10)};
    float p = price(items);
    REQUIRE(doctest::Approx(35) == p);
}

TEST_CASE("ShoppingBasket, Discount_5") {
    auto items = {ItemQuantity(1, 150)};
    float p = price(items);
    REQUIRE(doctest::Approx(142.5) == p);
}

TEST_CASE("ShoppingBasket, Discount_10") {
    auto items = {ItemQuantity(1, 220)};
    float p = price(items);
    REQUIRE(doctest::Approx(198) == p);
}



