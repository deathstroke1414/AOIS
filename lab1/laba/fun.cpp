#include <iostream>
#include <bitset>
#include <iomanip>
#include <cmath>
#include "fun.h"

using namespace std;

void decimalToBinary(int num) {
    bitset<8> direct(num);
    bitset<8> inverse = ~direct;
    bitset<8> complement = inverse.to_ulong() + 1;

    cout << "Прямой код: " << direct << endl;
    cout << "Обратный код: " << inverse << endl;
    cout << "Дополнительный код: " << complement << endl << endl;
}

std::bitset<8> addBinary(std::bitset<8> a, std::bitset<8> b) {
    std::bitset<8> result;
    bool carry = false;

    for (int i = 0; i < 8; ++i) {
        bool bitA = a[i];
        bool bitB = b[i];
        result[i] = bitA ^ bitB ^ carry;
        carry = (bitA & bitB) | (carry & (bitA ^ bitB));
    }

    return result;
}

std::bitset<8> subtractBinary(std::bitset<8> a, std::bitset<8> b) {
    std::bitset<8> negB = addBinary(~b, std::bitset<8>(1));
    return addBinary(a, negB);
}

std::bitset<8> multiplyBinary(std::bitset<8> a, std::bitset<8> b) {
    std::bitset<8> product;

    for (int i = 0; i < 8; ++i) {
        if (b[i]) {
            product = addBinary(product, a << i);
        }
    }

    return product;
}

std::bitset<8> divideBinary(std::bitset<8> a, std::bitset<8> b) {
    std::bitset<8> quotient;
    std::bitset<8> remainder = a;

    for (int i = 7; i >= 0; --i) {
        if (remainder.to_ulong() >= (b << i).to_ulong()) {
            remainder = subtractBinary(remainder, b << i);
            quotient.set(i);
        }
    }

    return quotient;
}

void addFloatingPoint(float num1, float num2) {
    float sum = num1 + num2;
    cout << "Результат: " << sum << endl;
    decimalToBinary(*reinterpret_cast<int*>(&sum));
}

void addComplementary(int num1, int num2) {
    std::bitset<8> binaryNum1(num1);
    std::bitset<8> binaryNum2(num2);
    std::bitset<8> result = addBinary(binaryNum1, binaryNum2);

    cout << "Результат: " << result.to_ulong() << endl;
    cout << "Результат в двоичной системе: " << result << endl;
}

void subtractComplementary(int num1, int num2) {
    std::bitset<8> binaryNum1(num1);
    std::bitset<8> binaryNum2(num2);
    std::bitset<8> result = subtractBinary(binaryNum1, binaryNum2);

    cout << "Результат: " << result.to_ulong() << endl;
    cout << "Результат в двоичной системе: " << result << endl;
}

void multiplyDirect(int num1, int num2) {
    std::bitset<8> binaryNum1(num1);
    std::bitset<8> binaryNum2(num2);
    std::bitset<8> result = multiplyBinary(binaryNum1, binaryNum2);

    cout << "Произведение: " << result.to_ulong() << endl;
    cout << "Произведение в двоичной системе: " << result << endl;
}

void divideDirect(int num1, int num2) {
    std::bitset<8> binaryNum1(num1);
    std::bitset<8> binaryNum2(num2);
    std::bitset<8> result = divideBinary(binaryNum1, binaryNum2);

    cout << "Результат: " << result.to_ulong() << endl;
    cout << "Результат в двоичной системе: " << result << endl;
}
