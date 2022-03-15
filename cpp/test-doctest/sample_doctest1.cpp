#include "ApprovalTests.hpp"
#include "doctest/doctest.h"
#include "item.h"
#include "shopping_basket.h"


TEST_CASE ("ShoppingBasket Price") {
    SUBCASE("empty") {
        std::vector<ItemQuantity> items = {};
        REQUIRE(doctest::Approx(0) == price(items));
    }
    SUBCASE("no discount") {
        auto items = {ItemQuantity(1, 50)};
        REQUIRE(50 == price(items));
    }
    SUBCASE("two items of one type") {
        auto items = {ItemQuantity(2, 25)};
        REQUIRE(50 == price(items));

    }
    SUBCASE("two items different types") {
        auto items  = {ItemQuantity(1, 25), ItemQuantity(1, 10)};
        REQUIRE(35 == price(items));
    }
    SUBCASE("five percent discount") {
        auto items  = {ItemQuantity(1, 100), ItemQuantity(1, 50)};
        REQUIRE(doctest::Approx(142).epsilon(0.01) == price(items));
    }
    SUBCASE("ten percent discount") {
        auto items  = {ItemQuantity(1, 200), ItemQuantity(1, 20)};
        REQUIRE(doctest::Approx(198).epsilon(0.01) == price(items));
    }
}



