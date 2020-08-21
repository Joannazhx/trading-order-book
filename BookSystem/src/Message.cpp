//
//  Message.cpp
//  Vivcourt
//
//  Created by Joanna on 2020/8/2.
//  Copyright © 2020年 Joanna. All rights reserved.
//

#include "Message.hpp"
#include <iostream>

seq_num_type SEQ_NUM_DEFAULT = 0;
mess_size_type MESS_SIZE_DEFAULT = 0;

id_type ID_DEFAULT = 0;
price_type PRICE_DEFAULT = 0;
size_type SIZE_DEFAULT = 0;

Message::Message(const seq_num_type &r_seq_num) {
    seq_num = r_seq_num;
}

void Message::setSeqNum(const seq_num_type &r_seq_num) {
    seq_num = r_seq_num;
}

void Message::setMessSize(const mess_size_type &r_mess_size) {
    mess_size = r_mess_size;
}

void Message::setType(const char &r_type) {
    if (r_type == 'A' || r_type == 'D' || r_type == 'U' || r_type == 'E') {
        mess_type = r_type;
    } else {
        std::cerr << "Message Type error : " << r_type << std::endl;
    }
}

void Message::setSymbol(const char &r_symblo) {
    strncpy(symbol, &r_symblo, 3);
    symbol[3] = 0;
}

void Message::setOrderId(const id_type &r_order_id) {
    order_id = r_order_id;
}

void Message::setSide(const char &r_side) {
    side = r_side;
}

void Message::setSize(const size_type &r_size) {
    size = r_size;
}

void Message::setPrice(const price_type &r_price) {
    price = r_price;
}

void Message::setIsValid(bool valid) {
    is_valid = valid;
}

seq_num_type Message::getSeqNum(void) const {
    return seq_num;
}

mess_size_type Message::getMessSize(void) const {
    return mess_size;
}

char Message::getType(void) const {
    return mess_type;
}

const char *Message::getSymbol(void) const {
    return symbol;
}

id_type Message::getOrderId(void) const {
    return order_id;
}

const char Message::getSide(void) const {
    return side;
}

size_type Message::getSize(void) const {
    return size;
}

price_type Message::getPrice(void) const {
    return price;
}

bool Message::isValid(void) {
    return is_valid;
}

std::string Message::getString(void)const {
    std::ostringstream mess_string;
    mess_string << seq_num << "," << mess_size << "," << mess_type << "," <<
    symbol << "," << order_id << "," << side << "," << size << ","<< price;
    return mess_string.str();
}

void Message::print() const {
    std::cout << "Sequence No. : " << seq_num << std::endl;
    std::cout << "Message Size : " << mess_size << std::endl;
    std::cout << "Message Type : " << mess_type << std::endl;
    std::cout << "Symbol       : " << symbol << std::endl;
    std::cout << "Order Id     : " << order_id << std::endl;
    std::cout << "Side         : " << side << std::endl;
    std::cout << "Voloum       : " << size<< std::endl;
    std::cout << "Price        : " << price<< std::endl;
}


