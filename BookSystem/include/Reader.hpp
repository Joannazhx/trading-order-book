//
//  Reader.hpp
//  Vivcourt
//
//  Created by Joanna on 2020/8/2.
//  Copyright © 2020年 Joanna. All rights reserved.
//
/**
* Reader read the input binary stream (cat input file | ./app levels)
* each meassage first 8 bytes header is seq Sequence No, messeage body size
* first read 8 bytes than read body size bytes.
*
*/

#ifndef BOOKSYSTEM_INCLUDE_READER_HPP_
#define BOOKSYSTEM_INCLUDE_READER_HPP_

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdint>

#include "Message.hpp"


extern int SEQ_NUM_LEN, MESS_SIZE_LEN,
           MESS_TYPE_LEN, SYMBOL_LEN, ORDER_ID_LEN, SIDE_LEN,
           RESERVED_1_LEN, SIZE_LEN, PRICE_LEN, RESERVED_2_LEN;

class Reader{
private:
   //read to the end of the input binary stream
   bool is_end = false;

public:
   Reader();

   virtual seq_num_type readSeq(void);
   virtual mess_size_type readMessageSize(void);

   virtual char* readMessageByLength(const int &, char *);
   virtual char* readMessageCharsByLength(const int &, char *);

   virtual size_type readSize(void);
   virtual price_type readPrice(void);
   virtual id_type readId(void);

   // skip Padding, all spaces bytes.
   void skipLength(const int &);

    /**
    * Reads from th input  binary stream and create a message
    * Creates a Message stores all information
    */
   Message createMessage(void);

   //sin read to the end of the input stream
   bool isEnd(void);
   void setIsEnd(bool);
};

#endif  // BOOKSYSTEM_INCLUDE_READER_HPP_
