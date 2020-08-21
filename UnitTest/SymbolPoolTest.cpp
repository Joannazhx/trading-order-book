//
//  MessageTest.cpp
//  UnitTest
//
//  Created by Joanna on 2020/8/5.
//  Copyright © 2020年 Joanna. All rights reserved.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "SymbolPool.hpp"

struct SymbolPoolTest : public testing::Test {
    SymbolPool *symbols;
    Symbol *symbol;

    void SetUp() {
        symbols = new SymbolPool();
    }
    void TearDown() {
        delete symbols;
    }
};

TEST_F(SymbolPoolTest, addSearchSymboyTest) {
    char sym_1[] = "VC0";
    char sym_2[] = "VC1";
    char side_s = 'S', side_b = 'B';
    price_type price = 100;
    int64_t size = 1000;
    symbols->addSnapshot(sym_1, side_b, price, size);
    symbols->addSnapshot(sym_1, side_s, price, size);
    symbols->addSnapshot(sym_2, side_b, price, size + 1);
    symbols->addSnapshot(sym_2, side_s, price, size + 1);
    ASSERT_EQ("[(100, 1000)], [(100, 1000)]",
              symbols->searchSymbol(sym_1).getString(1));
    ASSERT_EQ("[(100, 1001)], [(100, 1001)]",
              symbols->searchSymbol(sym_2).getString(1));
}

TEST_F(SymbolPoolTest, deleteSymboyTest) {
    char sym_1[] = "VC0";
    char sym_2[] = "VC1";
    char side_s = 'S', side_b = 'B';
    price_type price = 100;
    int64_t size = 1000;
    symbols->addSnapshot(sym_1, side_b, price, size);
    symbols->addSnapshot(sym_1, side_b, price, size);
    symbols->deleteSnapshot(sym_1, side_b, price, size);
    symbols->addSnapshot(sym_1, side_s, price, size);
    ASSERT_EQ("[(100, 1000)], [(100, 1000)]",
              symbols->searchSymbol(sym_1).getString(1));
    symbols->deleteSnapshot(sym_1, side_b, price, size);
    ASSERT_EQ("[], [(100, 1000)]",
              symbols->searchSymbol(sym_1).getString(1));
    symbols->deleteSnapshot(sym_1, side_s, price, size - 1);
    ASSERT_EQ("[], [(100, 1)]",
              symbols->searchSymbol(sym_1).getString(1));
}

TEST_F(SymbolPoolTest, updateSymboyTest) {
    char sym_1[] = "VC0";
    char sym_2[] = "VC1";
    char side_s = 'S', side_b = 'B';
    price_type price = 100, price_new = 99;
    int64_t size = 1000, size_new = 1;
    symbols->addSnapshot(sym_1, side_b, price, size);
    symbols->addSnapshot(sym_1, side_s, price, size);
    symbols-> updateSnapshot(sym_1, side_s, price, price_new, size, size_new);
    ASSERT_EQ("[(100, 1000)], [(99, 1)]",
              symbols->searchSymbol(sym_1).getString(1));
    symbols->addSnapshot(sym_1, side_s, price, size);
    symbols-> updateSnapshot(sym_1, side_s, price, price_new, size, size_new);
    ASSERT_EQ("[(100, 1000)], [(99, 2)]",
              symbols->searchSymbol(sym_1).getString(1));
}


