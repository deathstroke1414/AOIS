#ifndef FUN_H
#define FUN_H
#include <bitset>

void decimalToBinary(int num);
std::bitset<8> addBinary(std::bitset<8> a, std::bitset<8> b);
std::bitset<8> subtractBinary(std::bitset<8> a, std::bitset<8> b);
std::bitset<8> multiplyBinary(std::bitset<8> a, std::bitset<8> b);
std::bitset<8> divideBinary(std::bitset<8> a, std::bitset<8> b);
void addFloatingPoint(float num1, float num2);

#endif
