//
//  OrderPool.cpp
//  Vivcourt
//
//  Created by Joanna on 2020/8/2.
//  Copyright © 2020年 Joanna. All rights reserved.
//

#include "OrderPool.hpp"

Order OrderPool::searchOrder(id_type order_id) {
    auto order_it = orders.find(order_id);
    Order order;
    if (order_it != orders.end()) {
        order = order_it->second;
    }
    return order;
}

void OrderPool::addOrder(id_type order_id, size_type size, price_type price,
                         const char side, const char *symbol) {
    Order order(order_id, size, price, side, symbol);
    orders[order_id] = order;
}

void OrderPool::updateOrder(id_type order_id, size_type new_size,
                            price_type new_price) {
    orders[order_id].setSize(new_size);
    orders[order_id].setPrice(new_price);
    if (orders[order_id].getSize() == 0) {
        deleteOrder(order_id);
    }
}

void OrderPool::execOrder(id_type order_id, size_type size) {
     orders[order_id].decSize(size);
    if (orders[order_id].getSize() == 0)
        deleteOrder(order_id);
}

void OrderPool::deleteOrder(id_type order_id) {
    orders.erase(order_id);
}

bool OrderPool::isEmpty(void) const {
    return orders.empty();
}

void OrderPool::print(void) const {
    std::cout << "order ids " << std::endl;
    for (auto iter : orders) {
        std::cout << iter.first << std::endl;
    }
}







