#include "Fun.h"
#include <iostream>
#include <bitset>
#include <iomanip>
#include <cmath>
#include <string>
#include "Windows.h"

using namespace std;

string decimalToBinary(int num) {
    bitset<8> direct(num);
    bitset<8> inverse = ~direct;
    bitset<8> complement = ~(num + 1);
    string s = direct.to_string() + " " + inverse.to_string() + " " + complement.to_string();

    cout << "Прямой код: " << direct << endl;
    cout << "Обратный код: " << inverse << endl;
    cout << "Дополнительный код: " << complement << endl << endl;
    return s;
}

string addComplementary(int num1, int num2) {
    int sum = num1 + num2;
    cout << "Результат: " << sum << endl;
    string s = to_string(sum) + " " + decimalToBinary(sum);
    return s;
}

string subtractComplementary(int num1, int num2) {
    int negNum2 = ~num2 + 1;
    string s = addComplementary(num1, negNum2);
    return s;
}

string multiplyDirect(int num1, int num2) {
    int product = num1 * num2;
    cout << "Произведение: " << product << endl;
    string s = to_string(product) + " " + decimalToBinary(product);
    return s;
}

string divideDirect(int num1, int num2) {
    double quotient = static_cast<double>(num1) / num2;
    cout << "Результат: " << fixed << setprecision(5) << quotient << endl;//точность 5 знаков
    string s = to_string(quotient);
    return s;
}

string addFloatingPoint(float num1, float num2) {
    float sum = num1 + num2;
    cout << "Результат: " << sum << endl;
    string s = to_string(sum) + " " + decimalToBinary(*reinterpret_cast<int*>(&sum));// IEEE-754
    return s;
}