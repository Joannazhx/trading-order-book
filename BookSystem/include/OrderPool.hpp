//
//  OrderPool.hpp
//  Vivcourt
//
//  Created by Joanna on 2020/8/2.
//  Copyright © 2020年 Joanna. All rights reserved.
//

/**
 * The OrderPool tracks all Orders.
 * "A"dd / "U"pdate / "E"excute / "D"elete orders
 * all order related information stored in unordered map orders
 *
 */

#ifndef BOOKSYSTEM_INCLUDE_ORDERPOOL_HPP_
#define BOOKSYSTEM_INCLUDE_ORDERPOOL_HPP_

#include <unordered_map>
#include "Order.hpp"
#include "Message.hpp"

class OrderPool{
 private:
    std::unordered_map<id_type, Order> orders;

 public:
    OrderPool() = default;

    /**
    * Look for the Order by the order id in the orders
    * @param[in] order_id : Unique to a symbol and side (i.e., bid or ask).
    *
    */
    Order searchOrder(id_type);

    /**
    * add  order into orders  map
    * @param[in] order_id : Unique to a symbol and side (i.e., bid or ask).
    * @param[in] order size
    * @param[in] order price
    * @param[in] side 'B' for buy side and 'S' for sell side.
    * @param[in] symbol
    *
    */
    void addOrder(id_type, size_type, price_type , const char, const char *);

    /**
    * update exsiting order with new price and size
    * @param[in] order_id : Unique to a symbol and side (i.e., bid or ask).
    * @param[in] order size
    * @param[in] order price
    *
    */
    void updateOrder(id_type, size_type, price_type);

    /**
    * execute part of full of exsiting order
    * if execute full order(size to 0) then delete the order
    * @param[in] order_id : Unique to a symbol and side (i.e., bid or ask).
    * @param[in] execute size
    *
    */
    void execOrder(id_type, size_type);

    /**
    * delete exsiting order
    * @param[in] order_id : Unique to a symbol and side (i.e., bid or ask).
    */
    void deleteOrder(id_type);

    // check is thw oreders map empty
    bool isEmpty(void) const;

    void print(void) const;
};
#endif  // BOOKSYSTEM_INCLUDE_ORDERPOOL_HPP_
