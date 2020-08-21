//
//  MessageTest.cpp
//  UnitTest
//
//  Created by Joanna on 2020/8/5.
//  Copyright © 2020年 Joanna. All rights reserved.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include <OrderWrap.hpp>

struct OrderWrapTest : public testing::Test {
    OrderWrap *wrap;
    Message m;
    void SetUp() {
        wrap = new OrderWrap(5);
    }
    void TearDown() {
        delete wrap;
    }
};

TEST_F(OrderWrapTest, AddMessTypeTest) {
    char mess_type = 'A';
    char symbol[] = "VC0";
    id_type order_id = 6990022307456631368;
    char side = 'B';
    size_type size = 5000;
    price_type price = 318800;
    seq_num_type seq_num = 1;
    mess_size_type mess_size = 32;
    wrap->setMessageHeader(seq_num, mess_size);
    wrap->setMessage(mess_type, *symbol, order_id, side , size, price);
    wrap->updateSymbols();
    wrap->updatOrderPool();
    wrap->updateOutput();
    ASSERT_EQ("1, VC0, [(318800, 5000)], []\n", wrap->getOutLine());
}

TEST_F(OrderWrapTest, ExecMessTypeTest) {
    char mess_type = 'A';
    char symbol[] = "VC0";
    id_type order_id = 6990022307456631368;
    char side = 'B';
    size_type size = 5000;
    price_type price = 318800;
    seq_num_type seq_num = 1;
    mess_size_type mess_size = 32;
    wrap->setMessageHeader(seq_num, mess_size);
    wrap->setMessage(mess_type, *symbol, order_id, side , size, price);
    wrap->updateSymbols();
    wrap->updatOrderPool();
    wrap->updateOutput();

    mess_type = 'E';
    side = 'B';
    size = 291;
    seq_num = 3;
    mess_size = 24;
    wrap->setMessageHeader(seq_num, mess_size);
    wrap->setMessage(mess_type, *symbol, order_id, side , size);
    wrap->updateSymbols();
    wrap->updatOrderPool();
    wrap->updateOutput();
    ASSERT_EQ("3, VC0, [(318800, 4709)], []\n", wrap->getOutLine());
}

TEST_F(OrderWrapTest, UpdateMessTypeTest) {
    char mess_type = 'A';
    char symbol[] = "VC0";
    id_type order_id = 6990022307456647284;
    char side = 'B';
    size_type size = 2986;
    price_type price = 315000;
    seq_num_type seq_num = 2;
    mess_size_type mess_size = 32;
    wrap->setMessageHeader(seq_num, mess_size);
    wrap->setMessage(mess_type, *symbol, order_id, side , size, price);
    wrap->updateSymbols();
    wrap->updatOrderPool();
    wrap->updateOutput();

    ASSERT_EQ("2, VC0, [(315000, 2986)], []\n", wrap->getOutLine());
    mess_type = 'U';
    side = 'B';
    size = 888;
    price = 319000;
    seq_num = 7;
    mess_size = 32;
    wrap->setMessageHeader(seq_num, mess_size);
    wrap->setMessage(mess_type, *symbol, order_id, side , size, price);
    wrap->updateSymbols();
    wrap->updatOrderPool();
    wrap->updateOutput();
    ASSERT_EQ("7, VC0, [(319000, 888)], []\n", wrap->getOutLine());
}

TEST_F(OrderWrapTest, deleteMessTypeTest) {
    char mess_type = 'A';
    char symbol[] = "VC0";
    id_type order_id = 6990022307456647284;
    char side = 'B';
    size_type size = 2986;
    price_type price = 315000;
    seq_num_type seq_num = 2;
    mess_size_type mess_size = 32;
    wrap->setMessageHeader(seq_num, mess_size);
    wrap->setMessage(mess_type, *symbol, order_id, side , size, price);
    wrap->updateSymbols();
    wrap->updatOrderPool();
    wrap->updateOutput();

    ASSERT_EQ("2, VC0, [(315000, 2986)], []\n", wrap->getOutLine());
    mess_type = 'D';
    side = 'B';
    seq_num = 8;
    mess_size = 16;
    wrap->setMessageHeader(seq_num, mess_size);
    wrap->setMessage(mess_type, *symbol, order_id, side , size, price);
    wrap->updateSymbols();
    wrap->updatOrderPool();
    wrap->updateOutput();
    ASSERT_EQ("8, VC0, [], []\n", wrap->getOutLine());
}
