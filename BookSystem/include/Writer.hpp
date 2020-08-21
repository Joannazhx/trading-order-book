//
//  Writer.hpp
//  Vivcourt
//
//  Created by Joanna on 2020/8/2.
//  Copyright © 2020年 Joanna. All rights reserved.
//

#ifndef BOOKSYSTEM_INCLUDE_WRITER_HPP_
#define BOOKSYSTEM_INCLUDE_WRITER_HPP_

#include <iostream>
#include <fstream>
#include <string>


class Writer{
 private:
    std::string file_name = "output.log";
    std::ofstream file;

 public:
    Writer();
    explicit Writer(const std::string &file_name);
    ~Writer();

    // Write string to output stream
    void writeLine(const std::string &);
};

#endif  // BOOKSYSTEM_INCLUDE_WRITER_HPP_
