#include "ApprovalTests.hpp"
#include "doctest/doctest.h"
#include "item.h"
#include "shopping_basket.h"

using namespace std;


class BasketTestCase {
private:

public:
    BasketTestCase(vector<ItemQuantity> items, float expectedPrice) : _items(items), _expectedPrice(expectedPrice) {}

    vector<ItemQuantity> _items;
    float _expectedPrice;
};

#define DOCTEST_VALUE_PARAMETERIZED_DATA(data, data_container)                                  \
    static size_t _doctest_subcase_idx = 0;                                                     \
    std::for_each(data_container.begin(), data_container.end(), [&](BasketTestCase* in) {           \
        DOCTEST_SUBCASE((std::string(#data_container "[") +                                     \
                        std::to_string(_doctest_subcase_idx++) + "]").c_str()) { data = in; }  \
    });                                                                                         \
    _doctest_subcase_idx = 0

TEST_CASE("ShoppingBasket, Prices Parameterized") {
    BasketTestCase *basketCase;
    vector<BasketTestCase *> cases = {
            new BasketTestCase({ItemQuantity(1, 50)}, 50),
            new BasketTestCase({ItemQuantity(1, 50), ItemQuantity(2, 25)}, 100),
            new BasketTestCase({ItemQuantity(1, 50), ItemQuantity(2, 25), ItemQuantity(1, 25)}, 118.75),
            new BasketTestCase({ItemQuantity(1, 50), ItemQuantity(2, 25), ItemQuantity(1, 25), ItemQuantity(1, 10)}, 128.25),
            new BasketTestCase({ItemQuantity(1, 50), ItemQuantity(2, 25), ItemQuantity(1, 25), ItemQuantity(1, 10), ItemQuantity(1, 100)}, 211.5)
    };

    DOCTEST_VALUE_PARAMETERIZED_DATA(basketCase, cases);

    REQUIRE(doctest::Approx(basketCase->_expectedPrice) == price(basketCase->_items));

}
