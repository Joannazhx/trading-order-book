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
#include <Symbol.hpp>

struct SymbolTest : public testing::Test {
    Symbol *symbol;

    void SetUp() {
        symbol = new Symbol();
    }

    void TearDown() {
        delete symbol;
    }
};

TEST_F(SymbolTest, addNewTest) {
    price_type price = 100;
    int64_t diff_size = 100;
    char type = 'B';
    symbol->modify(price, diff_size, type);
    ASSERT_EQ("[(100, 100)], []",
              symbol->getString(1));
}

TEST_F(SymbolTest, LevelsOrderTest) {
    price_type price = 100;
    int64_t diff_size = 100;
    char type = 'B';
    char type_s = 'S';
    symbol->modify(price, diff_size, type);
    symbol->modify(price + 1, diff_size, type);
    ASSERT_EQ("[], []",
              symbol->getString(0));
    ASSERT_EQ("[(101, 100), (100, 100)], []",
              symbol->getString(2));
    ASSERT_EQ("[(101, 100)], []",
              symbol->getString(1));
    symbol->modify(price + 2, diff_size, type_s);
    symbol->modify(price + 3, diff_size, type_s);
    ASSERT_EQ("[(101, 100), (100, 100)], [(102, 100), (103, 100)]",
              symbol->getString(2));
    ASSERT_EQ("[(101, 100)], [(102, 100)]",
              symbol->getString(1));
}

TEST_F(SymbolTest, existOrderUpdateTEst) {
    price_type price = 100;
    int64_t diff_size = 100;
    char type = 'B';
    char type_s = 'S';
    symbol->modify(price, diff_size, type);
    symbol->modify(price , diff_size + 1, type);
    ASSERT_EQ("[(100, 201)], []", symbol->getString(1));
    symbol->modify(price, diff_size + 1, type_s);
    symbol->modify(price, -1 * diff_size  , type_s);
    ASSERT_EQ("[(100, 201)], [(100, 1)]", symbol->getString(1));
}

