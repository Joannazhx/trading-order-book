//
//  MessageTest.cpp
//  UnitTest
//
//  Created by Joanna on 2020/8/5.
//  Copyright © 2020年 Joanna. All rights reserved.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <OrderPool.hpp>
#include <Message.hpp>

struct OrderPoolTest : public testing::Test {
    OrderPool *pool;
    void SetUp() {
        pool = new OrderPool();
    }
    void TearDown() {
        delete pool;
    }
};

TEST_F(OrderPoolTest, emptyOrderPoolTest) {
    ASSERT_EQ(true, pool->isEmpty());
}


TEST_F(OrderPoolTest, addSearchOrderTest) {
    id_type order_id = 12345;
    size_type order_size = 100;
    price_type price = 1000;
    char side = 'B';
    char symbol[] = "VC0";
    pool->addOrder(order_id, order_size, price, side, symbol);
    ASSERT_EQ(order_id, pool->searchOrder(order_id).getId());
    ASSERT_EQ(order_size, pool->searchOrder(order_id).getSize());
    ASSERT_EQ(price, pool->searchOrder(order_id).getPrice());
    ASSERT_EQ(side, pool->searchOrder(order_id).getSide());
    std::string s(pool->searchOrder(order_id).getSymblo());
    ASSERT_EQ("VC0", s);
}

TEST_F(OrderPoolTest, addUpdateOrderTest) {
    id_type order_id = 12345;
    size_type order_size = 100;
    price_type price = 1000;
    char side = 'B';
    char symbol[] = "VC0";
    pool->addOrder(order_id, order_size, price, side, symbol);
    size_type new_size = 1;
    price_type new_price = 100;
    pool->updateOrder(order_id, new_size, new_price);
    ASSERT_EQ(order_id, pool->searchOrder(order_id).getId());
    ASSERT_EQ(side, pool->searchOrder(order_id).getSide());
    ASSERT_EQ(new_size, pool->searchOrder(order_id).getSize());
    ASSERT_EQ(new_price, pool->searchOrder(order_id).getPrice());
    std::string s(pool->searchOrder(order_id).getSymblo());
    ASSERT_EQ("VC0", s);
}

TEST_F(OrderPoolTest, addUpdateSize0OrderTest) {
    id_type order_id = 12345;
    size_type order_size = 100;
    price_type price = 1000;
    char side = 'B';
    char symbol[] = "VC0";
    pool->addOrder(order_id, order_size, price, side, symbol);
    size_type new_size = 0;
    price_type new_price = 100;
    pool->updateOrder(order_id, new_size, new_price);
    ASSERT_EQ(ID_DEFAULT, pool->searchOrder(order_id).getId());
}

TEST_F(OrderPoolTest, addExecTest) {
    id_type order_id = 12345;
    size_type order_size = 100;
    price_type price = 1000;
    char side = 'B';
    char symbol[] = "VC0";
    pool->addOrder(order_id, order_size, price, side, symbol);
    size_type exec_size = 10;
    pool->execOrder(order_id, exec_size);
    ASSERT_EQ(order_id, pool->searchOrder(order_id).getId());
    ASSERT_EQ(order_size - exec_size, pool->searchOrder(order_id).getSize());
    ASSERT_EQ(price, pool->searchOrder(order_id).getPrice());
    ASSERT_EQ(side, pool->searchOrder(order_id).getSide());
    std::string s(pool->searchOrder(order_id).getSymblo());
    ASSERT_EQ("VC0", s);
}

TEST_F(OrderPoolTest, addExec0Test) {
    id_type order_id = 12345;
    size_type order_size = 100;
    price_type price = 1000;
    char side = 'B';
    char symbol[] = "VC0";
    pool->addOrder(order_id, order_size, price, side, symbol);
    pool->execOrder(order_id, order_size);
    ASSERT_EQ(ID_DEFAULT, pool->searchOrder(order_id).getId());
}

TEST_F(OrderPoolTest, deleteOrderTest) {
    id_type order_id = 12345;
    size_type order_size = 100;
    price_type price = 1000;
    char side = 'B';
    char symbol[] = "VC0";
    pool->addOrder(order_id, order_size, price, side, symbol);
    pool->deleteOrder(order_id);
    ASSERT_EQ(ID_DEFAULT, pool->searchOrder(order_id).getId());
}
