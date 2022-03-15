#include <gtest/gtest.h>
#include <tuple>

#include "item.h"
#include "shopping_basket.h"

using namespace std;

class BasketCase {
private:

public:
    BasketCase(vector<ItemQuantity> items, float expectedPrice) : _items(items), _expectedPrice(expectedPrice) {}

    vector<ItemQuantity> _items;
    float _expectedPrice;
};

class ShoppingBasketTest : public testing::TestWithParam<const BasketCase *> {
public:
};

// Not sure why this is not used to print each basket case
std::ostream& operator<<(std::ostream &strm, const BasketCase &basketCase) {
    return strm << " BasketCase " << " expected price " << basketCase._expectedPrice;
}

INSTANTIATE_TEST_CASE_P
(
        ShoppingBasketTests,
        ShoppingBasketTest,
        ::testing::Values(

                new BasketCase({ItemQuantity(1, 50)}, 50),
                new BasketCase({ItemQuantity(1, 50), ItemQuantity(2, 25)}, 100),
                new BasketCase({ItemQuantity(1, 50), ItemQuantity(2, 25), ItemQuantity(1, 25)}, 118.75),
                new BasketCase({ItemQuantity(1, 50), ItemQuantity(2, 25), ItemQuantity(1, 25), ItemQuantity(1, 10)},
                               128.25),
                new BasketCase({ItemQuantity(1, 50), ItemQuantity(2, 25), ItemQuantity(1, 25), ItemQuantity(1, 10),
                                ItemQuantity(1, 100)}, 211.5)

        ));



TEST_P(ShoppingBasketTest, Price) {
    const BasketCase *basketCase = GetParam();
    ASSERT_NEAR(basketCase->_expectedPrice, price(basketCase->_items), 0.01);
}
