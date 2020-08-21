//
//  SymbolPool.cpp
//  Vivcourt
//
//  Created by Joanna on 2020/8/3.
//  Copyright © 2020年 Joanna. All rights reserved.
//

#include "SymbolPool.hpp"

Symbol SymbolPool::searchSymbol(const char *symbol) {
    std::string sy = std::string(symbol);
    auto symbol_it = snap_shots.find(sy);
    Symbol s;
    if (symbol_it != snap_shots.end()) {
        s = symbol_it->second;
    }
    return s;
}

void SymbolPool::addSnapshot(const char *symbol, const char side,
                             price_type price, int64_t size) {
    std::string sy = std::string(symbol);
    Symbol s = searchSymbol(symbol);
    s.modify(price, size, side);
    snap_shots[sy] = s;
}

void SymbolPool::deleteSnapshot(const char *symbol, const char side,
                                price_type price, int64_t size) {
    std::string sy = std::string(symbol);
    Symbol s = searchSymbol(symbol);
    s.modify(price, -1 * size, side);
    snap_shots[sy] = s;
}

void SymbolPool::updateSnapshot(const char *symbol, const char side,
                                price_type price_old, price_type price_new,
                                int64_t size_old, int64_t size_new) {
    deleteSnapshot(symbol, side, price_old, size_old);
    addSnapshot(symbol, side, price_new, size_new);
}

