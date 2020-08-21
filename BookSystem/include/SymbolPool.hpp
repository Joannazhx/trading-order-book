//
//  SymbolPool.hpp
//  Vivcourt
//
//  Created by Joanna on 2020/8/3.
//  Copyright © 2020年 Joanna. All rights reserved.
//
/**
 * For each stock with unique Symbol eg.VC0 Class containing list of buys and sells
 * Symbol pool maintain the hashmap which sorted buy and sell information for every stock
 */
#ifndef BOOKSYSTEM_INCLUDE_SYMBOLPOOL_HPP_
#define BOOKSYSTEM_INCLUDE_SYMBOLPOOL_HPP_

#include <iostream>
#include <unordered_map>
#include <string>
#include "Message.hpp"
#include "Symbol.hpp"

class SymbolPool{
 private:
    std::unordered_map<std::string, Symbol> snap_shots;

 public:
    SymbolPool() = default;

    Symbol searchSymbol(const char *);

    /**
     * add the stock sells and buys information
     *
     * @param[in] symbol modify map corresponding to price, size, 'B'uy /'S'ell
     * @param[in] side : 'B'uy /'S'ell which side
     * @param[in] price
     * @param[in] trading size
     *
     */
    void addSnapshot(const char *, const char, price_type, int64_t);

    /**
     * delete the N size in M price
     * @param[in] symbol modify map corresponding to price, size, 'B'uy /'S'ell
     * @param[in] side : 'B'uy /'S'ell which side
     * @param[in] price
     * @param[in] delete/execute size
     *
     */
    void deleteSnapshot(const char *, const char, price_type, int64_t);

    /**
     * update the M1 price N1 size to M2 price N2 size
     * @param[in] symbol modify map corresponding to price, size, 'B'uy /'S'ell
     * @param[in] side : 'B'uy /'S'ell which side
     * @param[in] old price  M1
     * @param[in] new price  M2
     * @param[in] old size N1
     * @param[in] new size N2
     */
    void updateSnapshot(const char *, const char, price_type, price_type,
                        int64_t, int64_t);
};


#endif  // BOOKSYSTEM_INCLUDE_SYMBOLPOOL_HPP_
