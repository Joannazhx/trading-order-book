//
//  main.cpp
//  UnitTest
//
//  Created by Joanna on 2020/8/4.
//  Copyright © 2020年 Joanna. All rights reserved.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(google_test, assertTrue) {
    ASSERT_TRUE(true);
}
