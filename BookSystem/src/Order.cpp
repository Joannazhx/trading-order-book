//
//  Order.cpp
//  Vivcourt
//
//  Created by Joanna on 2020/8/2.
//  Copyright © 2020年 Joanna. All rights reserved.
//

#include "Order.hpp"
#include <iostream>

Order::Order(id_type id, size_type i_size, price_type i_price,
             const char i_side, const char *i_symbol) {
    order_id = id;
    order_size = i_size;
    price = i_price;
    side = i_side;
    strncpy(symbol, i_symbol, 3);
    symbol[3] = 0;
}

id_type Order::getId(void) const {
    return order_id;
}

const char Order::getSide(void) const {
    return side;
}

size_type Order::getSize(void) const {
    return order_size;
}

price_type Order::getPrice(void) const {
    return price;
}

const char *Order::getSymblo(void) const {
    return symbol;
}

void Order::setPrice(price_type new_price) {
    price = new_price;
}

void Order::setSize(size_type new_size) {
    order_size = new_size;
}

void Order::decSize(size_type size) {
    __int64_t new_size = order_size - size;
    if (new_size < 0)
        std::cerr << "Executed volume over the order's totoal volum"
        << std::endl;
    order_size = order_size - size;
}

void Order::print(void) const {
    std::cout << "Symbol       : " << symbol << std::endl;
    std::cout << "Order Id     : " << order_id << std::endl;
    std::cout << "Voloum       : " << side << std::endl;
    std::cout << "price        : " << price << std::endl;
    std::cout << "Size         : " << order_size<< std::endl;
}

