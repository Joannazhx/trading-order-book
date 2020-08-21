//
//  OrderTest.cpp
//  UnitTest
//
//  Created by Joanna on 2020/8/4.
//  Copyright © 2020年 Joanna. All rights reserved.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Order.hpp"

struct Order_Test : public testing::Test {
    Order *empty_order;
    Order *order;

    void SetUp() {
        id_type order_id = 12345;
        size_type order_size = 100;
        price_type price = 1000;
        char side = 'B';
        char symbol[] = "VC0";

        empty_order = new Order();
        order = new Order(order_id, order_size, price,  side, symbol);
    }

    void TearDown() {
        delete empty_order;
        delete order;
    }
};

TEST_F(Order_Test, decreaseSizeTest) {
    order->decSize(75);
    ASSERT_EQ(25, order->getSize());
}






