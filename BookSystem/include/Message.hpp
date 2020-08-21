//
//  Message.hpp
//  Vivcourt
//
//  Created by Joanna on 2020/8/2.
//  Copyright © 2020年 Joanna. All rights reserved.
//
/**
* Reader read all needed information and create message
* message used to update orders and symbols
*
*/
#ifndef BOOKSYSTEM_INCLUDE_MESSAGE_HPP_
#define BOOKSYSTEM_INCLUDE_MESSAGE_HPP_

#include <iostream>
#include <sstream>
#include <string>
#include <cstdint>

typedef unsigned int seq_num_type;
typedef unsigned int  mess_size_type;
typedef unsigned long id_type;
typedef unsigned long size_type;
typedef unsigned int price_type;

extern seq_num_type SEQ_NUM_DEFAULT;
extern mess_size_type MESS_SIZE_DEFAULT;
extern id_type ID_DEFAULT;
extern size_type SIZE_DEFAULT;
extern price_type PRICE_DEFAULT;


class Message{
 private:
        seq_num_type seq_num = SEQ_NUM_DEFAULT;
        mess_size_type mess_size = MESS_SIZE_DEFAULT;

        char mess_type = 0;
        char symbol[4] = "";
        id_type order_id = ID_DEFAULT;
        char side = 0;
        size_type size = SIZE_DEFAULT;
        price_type price = PRICE_DEFAULT;
        bool is_valid = true;

 public:
    Message() = default;
    explicit Message(const seq_num_type &);

    //set message information
    void setSeqNum(const seq_num_type &);
    void setMessSize(const mess_size_type &);
    void setType(const char &);
    void setSymbol(const char &);
    void setOrderId(const id_type &);
    void setSide(const char &);
    void setSize(const size_type &);
    void setPrice(const price_type &);
    void setIsValid(bool is_valid);

    //get message information
    seq_num_type getSeqNum(void) const;
    mess_size_type getMessSize(void) const;
    char getType(void) const;
    const char *getSymbol(void) const;
    id_type getOrderId(void) const;
    const char getSide(void) const;
    size_type getSize(void) const;
    price_type getPrice(void) const;
    bool isValid(void);

    void print(void) const;

    std::string getString(void) const;
};
#endif  // BOOKSYSTEM_INCLUDE_MESSAGE_HPP_
