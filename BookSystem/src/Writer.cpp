//
//  Writer.cpp
//  Vivcourt
//
//  Created by Joanna on 2020/8/2.
//  Copyright © 2020年 Joanna. All rights reserved.
//

#include "Writer.hpp"


Writer::Writer(const std::string& f_name) {
    file_name = f_name;
    file.open(file_name);
    if (file.is_open())
        std::cout << "output file " << file_name << "opened" << std::endl;
    else
        std::cerr << "Can't open " << file_name << std::endl;
}

Writer::Writer() {
    file.open(file_name);
    if (file.is_open())
        std::cout << "output file : " << file_name << std::endl;
    else
        std::cerr << "Can't open " << file_name << std::endl;
}

void Writer::writeLine(const std::string &line) {
    file << line;
}

Writer::~Writer() {
    if (file.is_open()) {
        file.flush();
        file.close();
    }
}
