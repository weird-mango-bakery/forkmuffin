#include <common/utils.h>
#include "gtest/gtest.h"


TEST(utils, stringToColor) {
   EXPECT_EQ(stringToColor("000000"), QColor(0, 0, 0));
   EXPECT_EQ(stringToColor("ff0080"), QColor(255, 0, 128));
   EXPECT_EQ(stringToColor("012345"), QColor(1, 35, 69));
}

TEST(utils, colorToString) {
    EXPECT_EQ(QString("000000"), colorToString({0, 0, 0}));
    EXPECT_EQ(QString("ff0080"), colorToString({255, 0, 128}));
    EXPECT_EQ(QString("012345"), colorToString({1, 35, 69}));
}
