#include "C:\AOIS\laba1test\laba1\laba1.cpp"
#include "gtest/gtest.h"

TEST(DecimalToBinaryTest, test1) {
    int num = 10;

    ASSERT_EQ(decimalToBinary(num), "00001010 11110101 11110100");
}

TEST(AddComplementaryTest, test2) {
    int num1 = 5, num2 = 3;

    ASSERT_EQ(addComplementary(num1, num2), "8 00001000 11110111 11110110");
}


TEST(SubtractComplementaryTest, test3) {
    int num1 = 8, num2 = 3;

    ASSERT_EQ(subtractComplementary(num1, num2), "5 00000101 11111010 11111001");
}


TEST(MultiplyDirectTest, test4) {
    int num1 = 4, num2 = 2;

    ASSERT_EQ(multiplyDirect(num1, num2), "8 00001000 11110111 11110110");
}


TEST(DivideDirectTest, test5) {
    int num1 = 8, num2 = 2;

    ASSERT_EQ(divideDirect(num1, num2), "4.000000");
}

TEST(AddFloatingPointTest, test6) {
    float num1 = 3.5, num2 = 2.5;

    ASSERT_EQ(addFloatingPoint(num1, num2), "6.000000 00000000 11111111 11111110");
}

