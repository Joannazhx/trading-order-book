//
//  Reader.cpp
//  Vivcourt
//
//  Created by Joanna on 2020/8/2.
//  Copyright © 2020年 Joanna. All rights reserved.
//

#include "Reader.hpp"


int SEQ_NUM_LEN = 4 , MESS_SIZE_LEN = 4,
    MESS_TYPE_LEN = 1, SYMBOL_LEN = 3, ORDER_ID_LEN = 8, SIDE_LEN = 1,
    RESERVED_1_LEN = 3, SIZE_LEN = 8, PRICE_LEN = 4, RESERVED_2_LEN = 4;



Reader::Reader() = default;

seq_num_type Reader::readSeq() {
    seq_num_type read_seq;
    std::cin.read(reinterpret_cast<char*>(&read_seq), SEQ_NUM_LEN);
    return read_seq;
}

mess_size_type Reader::readMessageSize() {
    mess_size_type read_mess_size;
    std::cin.read(reinterpret_cast<char*>(&read_mess_size), MESS_SIZE_LEN);
    return read_mess_size;
}

id_type Reader::readId(void) {
    id_type order_id;
    std::cin.read(reinterpret_cast<char*>(&order_id), ORDER_ID_LEN);
    return order_id;
}

size_type Reader::readSize() {
    size_type read_size;
    std::cin.read(reinterpret_cast<char*>(&read_size), SIZE_LEN);
    return read_size;
}

price_type Reader::readPrice() {
    price_type price;
    std::cin.read(reinterpret_cast<char*>(&price), PRICE_LEN);
    return price;
}

char* Reader::readMessageByLength(const int &length, char *mess) {
    std::cin.read(mess, length);
    return mess;
}

char* Reader::readMessageCharsByLength(const int &length, char *mess) {
    char temp[64];
    std::cin.read(temp, length);
    strncpy(mess, temp, length + 1);
    mess[length] = 0;
    return mess;
}


Message Reader::createMessage(void) {
    Message mess;
    seq_num_type read_seq = readSeq();
    if (std::cin.eof()) {
        std::cout << "finish process input binary stream" << std::endl;
        mess.setIsValid(false);
        setIsEnd(true);
        return mess;
    }
    mess_size_type read_mess_size = readMessageSize();
    mess.setSeqNum(read_seq);
    mess.setMessSize(read_mess_size);
    char mess_type[MESS_TYPE_LEN + 1];
    readMessageCharsByLength(MESS_TYPE_LEN, mess_type);
    mess.setType(mess_type[0]);

    char symblo[SYMBOL_LEN + 1];
    readMessageCharsByLength(SYMBOL_LEN, symblo);
    mess.setSymbol(*symblo);

    id_type order_id = readId();
    mess.setOrderId(order_id);

    char side[SIDE_LEN + 1];
    readMessageCharsByLength(SIDE_LEN, side);
    mess.setSide(*side);

    char reserve1[RESERVED_1_LEN + 1];
    readMessageCharsByLength(RESERVED_1_LEN, reserve1);

    switch (mess_type[0]) {
        case 'D':
            break;
        case 'E': {
            size_type size = readSize();
            mess.setSize(size);
        }break;
        case 'U':
        case 'A': {
            size_type size = readSize();
            mess.setSize(size);
            price_type price = readPrice();
            mess.setPrice(price);

            char reserve2[RESERVED_2_LEN + 1];
            readMessageCharsByLength(RESERVED_2_LEN, reserve2);
        }break;
    }
    return mess;
}

bool Reader::isEnd() {
    return is_end;
}

void Reader::setIsEnd(bool end) {
    is_end = end;
}
