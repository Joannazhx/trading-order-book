//
//  symbol.cpp
//  Vivcourt
//
//  Created by Joanna on 2020/8/3.
//  Copyright © 2020年 Joanna. All rights reserved.
//

#include "Symbol.hpp"

std::string Symbol::getString(const int &level) const {
    size_t buys_len = buys.size();
    size_t sells_len = sells.size();
    std::ostringstream string_buys, string_sells, output_string;

    std::map<real_prize_type, int64_t>::const_reverse_iterator
                                        buys_it = buys.rbegin();
    std::map<real_prize_type, int64_t>::const_iterator
                                        sells_it = sells.begin();

    string_buys << "[";
    string_sells << "[";
    for (int i = 0; i < level; i++) {
        if (i < buys_len) {
            if (buys_it != buys.rbegin())
                string_buys << ", ";
            string_buys << "(" << buys_it->first <<
                        ", "<< buys_it->second << ")";
            ++buys_it;
        }

        if (i < sells_len) {
            if (sells_it != sells.begin())
                string_sells << ", ";
            string_sells << "(" << sells_it->first <<
                        ", "<< sells_it->second << ")";
            ++sells_it;
        }
    }
    string_buys << "]";
    string_sells << "]";

    output_string << string_buys.str() << ", " << string_sells.str();
    return output_string.str();
}

void Symbol::modify(price_type price, int64_t diff_size, char type) {
    if (type == 'S') {
        sells[price] += diff_size;
        if (sells[price] == 0)
            sells.erase(price);
        else if (sells[price] < 0)
            std::cerr << "The volumn is negetive! " << std::endl;
    } else {
        buys[price] += diff_size;
        if (buys[price] == 0)
            buys.erase(price);
        else if (buys[price] < 0)
            std::cerr << "The volumn is negetive! " << std::endl;
    }
}
