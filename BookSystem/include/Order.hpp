//
//  Order.hpp
//  Vivcourt
//
//  Created by Joanna on 2020/8/2.
//  Copyright © 2020年 Joanna. All rights reserved.
//

/**
 * each order has a unique order id
 * one Message is one "A"dd / "U"pdate / "E"excute / "D"elete for one order
 * get/set all related values
 */

#ifndef BOOKSYSTEM_INCLUDE_ORDER_HPP_
#define BOOKSYSTEM_INCLUDE_ORDER_HPP_

#include "Message.hpp"

class Order{
 private:
    id_type order_id = ID_DEFAULT;
    size_type order_size = SIZE_DEFAULT;
    price_type price = PRICE_DEFAULT;
    char side;
    char symbol[4] = "";

 public:
    Order() = default;
    Order(id_type id, size_type size, price_type price,
          const char, const char *symbol);

    // get
    id_type getId(void) const;
    const char getSide(void) const;
    size_type getSize(void) const;
    price_type getPrice(void) const;
    const char *getSymblo(void) const;

    // set
    void setPrice(price_type new_price);
    void setSize(size_type new_size);
    void decSize(size_type diff);
    void print(void) const;
};

#endif  // BOOKSYSTEM_INCLUDE_ORDER_HPP_
