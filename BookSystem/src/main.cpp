//
//  main.cpp
//  Vivcourt
//
//  Created by Joanna on 2020/8/1.
//  Copyright © 2020年 Joanna. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "OrderWrap.hpp"

int main(int argc, const char * argv[]) {
    std::cout << "Hello, VivCourt!\n";

    if (argc== 1) {
        std::cout << "Please input top level!\n";
        return 0;
    }

    std::string level = argv[1];
    size_t l = atoi(level.c_str());
    OrderWrap o(l);
    o.start();

    return 0;
}
