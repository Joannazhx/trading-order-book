//
//  MessageTest.cpp
//  UnitTest
//
//  Created by Joanna on 2020/8/4.
//  Copyright © 2020年 Joanna. All rights reserved.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Message.hpp"

struct MessageTest : public testing::Test {
    Message *empty_message;
    Message *message;

    void SetUp() {
        empty_message = new Message();
        message = new Message(1);
    }

    void TearDown() {
        delete empty_message;
        delete message;
    }
};

TEST_F(MessageTest, setMessTest) {
    const char symbol[]="VC0";
    message->setSeqNum(1);
    message->setMessSize(32);
    message->setType('A');
    message->setSymbol(*symbol);
    message->setOrderId(123456);
    message->setSide('B');
    message->setSize(100);
    message->setPrice(1000);
    std::string symbol_str(message->getSymbol());
    ASSERT_EQ("1,32,A,VC0,123456,B,100,1000", message->getString());
}

TEST_F(MessageTest, getSymbolTest) {
    const char symbol[]="VC0";
    message->setSymbol(*symbol);
    std::string symbol_str(message->getSymbol());
    ASSERT_EQ("VC0", symbol_str);
}

TEST_F(MessageTest, getsetSeqNumTest) {
    seq_num_type seq_num = 2;
    message->setSeqNum(seq_num);
    empty_message->setSeqNum(message->getSeqNum());
    ASSERT_EQ(seq_num, empty_message->getSeqNum());
}

TEST_F(MessageTest, getSetMessSizeTest) {
    mess_size_type mess_size = 24;
    message->setMessSize(mess_size);
    empty_message->setMessSize(message->getMessSize());
    ASSERT_EQ(mess_size, empty_message->getMessSize());
}

TEST_F(MessageTest, getSetTypeTest) {
    char type = 'U';
    message->setType(type);
    empty_message->setType(message->getType());
    ASSERT_EQ(type, empty_message->getType());
}

TEST_F(MessageTest, getSetOrderIdTest) {
    id_type order_id = 123456;
    message->setOrderId(order_id);
    empty_message->setOrderId(message->getOrderId());
    ASSERT_EQ(order_id, empty_message->getOrderId());
}

TEST_F(MessageTest, getSetSideTest) {
    char side = 'S';
    message->setSide(side);
    empty_message->setSide(message->getSide());
    ASSERT_EQ(side, empty_message->getSide());
}

TEST_F(MessageTest, getSetSizeTest) {
    size_type size = 1000;
    message->setSize(size);
    empty_message->setSize(message->getSize());
    ASSERT_EQ(size, empty_message->getSize());
}

TEST_F(MessageTest, getSetPriceTest) {
    price_type price = 5000;
    message->setPrice(price);
    empty_message->setPrice(message->getPrice());
    ASSERT_EQ(price, empty_message->getPrice());
}

TEST_F(MessageTest, getSetIsValidTest) {
    bool valid = false;
    message->setIsValid(valid);
    empty_message->setIsValid(message->isValid());
    ASSERT_EQ(valid, empty_message->isValid());
}

