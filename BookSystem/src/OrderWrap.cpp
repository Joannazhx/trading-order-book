//
//  OrderWrap.cpp
//  Vivcourt
//
//  Created by Joanna on 2020/8/3.
//  Copyright © 2020年 Joanna. All rights reserved.
//

#include "OrderWrap.hpp"
#include <iostream>
OrderWrap::OrderWrap(const int &_levels) {
    levels = _levels;
}

void OrderWrap::start() {
    while (!read.isEnd()) {
        mess = read.createMessage();
        if (mess.isValid()) {
            updateSymbols();
            updatOrderPool();
            updateOutput();
        }
    }
}

void  OrderWrap::updateOutput() {
    Symbol s = symbols.searchSymbol(mess.getSymbol());
    std::ostringstream out_line;
    out_line << mess.getSeqNum() << ", " << std::string(mess.getSymbol()) <<
            ", " << s.getString(levels) << std::endl;
    line = out_line.str();
    write.writeLine(out_line.str());
}

void OrderWrap::updatOrderPool() {
    char mess_type = mess.getType();
    if (mess_type == 'A') {
        orders.addOrder(mess.getOrderId(), mess.getSize(), mess.getPrice(),
                        mess.getSide(), mess.getSymbol());
    } else if (mess_type == 'D') {
        orders.deleteOrder(mess.getOrderId());
    } else if (mess_type == 'E') {
        orders.execOrder(mess.getOrderId(), mess.getSize());
    } else if (mess_type == 'U') {
        orders.updateOrder(mess.getOrderId(), mess.getSize(), mess.getPrice());
    }
}

void OrderWrap::updateSymbols(void) {
    char mess_type = mess.getType();
    if (mess_type == 'A') {
        symbols.addSnapshot(mess.getSymbol(), mess.getSide(), mess.getPrice(),
                            static_cast<int64_t>(mess.getSize()));
    } else if (mess_type == 'D') {
        Order order = orders.searchOrder(mess.getOrderId());
        symbols.deleteSnapshot(mess.getSymbol(), mess.getSide(),
                               order.getPrice(),
                               static_cast<int64_t>(order.getSize()));
    } else if (mess_type == 'E') {
        Order order = orders.searchOrder(mess.getOrderId());
        symbols.deleteSnapshot(mess.getSymbol(), mess.getSide(),
                               order.getPrice(),
                               static_cast<int64_t>(mess.getSize()));
    } else if (mess_type == 'U') {
        Order order = orders.searchOrder(mess.getOrderId());

        symbols.updateSnapshot(mess.getSymbol(), mess.getSide(),
                               order.getPrice(), mess.getPrice(),
                               static_cast<int64_t>(order.getSize()),
                               static_cast<int64_t>(mess.getSize()));
    }
}

void OrderWrap::setMessageHeader(seq_num_type seq_num,
                                 mess_size_type mess_size) {
    mess.setSeqNum(seq_num);
    mess.setMessSize(mess_size);
}

void OrderWrap::setMessage(const char &mess_type, const char &symbol,
                           id_type order_id, const char &side ,
                           size_type size, price_type price) {
    mess.setType(mess_type);
    mess.setSymbol(symbol);
    mess.setOrderId(order_id);
    mess.setSide(side);
    mess.setSize(size);
    mess.setPrice(price);
}

void OrderWrap::setMessage(const char &mess_type, const char &symbol,
                           id_type order_id, const char &side) {
    mess.setType(mess_type);
    mess.setSymbol(symbol);
    mess.setOrderId(order_id);
    mess.setSide(side);
}

void OrderWrap::setMessage(const char &mess_type, const char &symbol,
                           id_type order_id, const char &side,
                           size_type size) {
    mess.setType(mess_type);
    mess.setSymbol(symbol);
    mess.setOrderId(order_id);
    mess.setSide(side);
    mess.setSize(size);
}

