#include "ApprovalTests.hpp"
#include "doctest/doctest.h"
#include "item.h"
#include "shopping_basket.h"


TEST_CASE("ShoppingBasket, Price_boundaries") {
    std::vector<ItemQuantity> items = {};
    REQUIRE(doctest::Approx(0) == price(items));
    items.emplace_back(1, 50);
    REQUIRE(doctest::Approx(50) == price(items));
    items.emplace_back(1, 50);
    REQUIRE(doctest::Approx(100) == price(items));
    items.emplace_back(1, 50);
    REQUIRE(doctest::Approx(150 - 7.5) == price(items));
    items.emplace_back(1, 50);
    REQUIRE(doctest::Approx(200 - 10) == price(items));
    items.emplace_back(1, 50);
    REQUIRE(doctest::Approx(250 - 25) == price(items));
}

