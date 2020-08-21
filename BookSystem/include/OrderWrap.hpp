//
//  OrderWrap.hpp
//  Vivcourt
//
//  Created by Joanna on 2020/8/3.
//  Copyright © 2020年 Joanna. All rights reserved.
//

#ifndef BOOKSYSTEM_INCLUDE_ORDERWRAP_HPP_
#define BOOKSYSTEM_INCLUDE_ORDERWRAP_HPP_

#include <string>
#include "Order.hpp"
#include "OrderPool.hpp"
#include "SymbolPool.hpp"
#include "Reader.hpp"
#include "Message.hpp"
#include "Writer.hpp"

class OrderWrap{
 private:
    Message mess;
    OrderPool orders;
    SymbolPool symbols;
    Reader read;
    Writer write;
    std::string line = "";
    int levels;

 public:
    void setMessageHeader(seq_num_type seq_num, mess_size_type mess_size);
    void setMessage(const char &, const char &, id_type,
                    const char &, size_type, price_type);
    void setMessage(const char &, const char &, id_type, const char &);
    void setMessage(const char &, const char &, id_type,
                    const char &, size_type);

    std::string getOutLine() {
        return line;
    }

    explicit  OrderWrap(const int &_levels);
    void start(void);

    void updatOrderPool(void);
    void updateSymbols(void);
    void updateOutput(void);
};

#endif  // BOOKSYSTEM_INCLUDE_ORDERWRAP_HPP_
