//
//  symbol.hpp
//  Vivcourt
//
//  Created by Joanna on 2020/8/3.
//  Copyright © 2020年 Joanna. All rights reserved.
//

/**
 * For each unique Symbol eg.VC0 Class containing list of buys and sells
 * ordered by price descries and increase into 2 ordered maps.
 *
 */

#ifndef BOOKSYSTEM_INCLUDE_SYMBOL_HPP_
#define BOOKSYSTEM_INCLUDE_SYMBOL_HPP_
#include <iostream>
#include <map>
#include <string>
#include "Message.hpp"

typedef __int64_t real_prize_type;

class Symbol{
 private:
    // stock buys and sells hashmap, key is price
    std::map<real_prize_type, int64_t> buys;
    std::map<real_prize_type, int64_t> sells;

 public:
    Symbol() = default;
/**
 * order the sells and buys list according to price , get top levels
 * wrapped the answer as request :
 * [(bidPrice1, bidVolume1), ...], [(askPrice1, askVolume1), ...]
 * ordered by price descries and increase into 2 ordered maps.
 * on return top N(levels).
 *
 */
    std::string getString(const int &) const;

/**
 * update the buy and sell list
 * @param[in] price modify map corresponding to price
 * @param[in] size add (or delete if size is negative) the size corresponding to price
 * @param[in] side 0 for buy side and 1 for sell side.
 *
 */
    void modify(price_type, int64_t, char);
};

#endif  // BOOKSYSTEM_INCLUDE_SYMBOL_HPP_
