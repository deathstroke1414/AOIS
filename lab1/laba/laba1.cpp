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
    bitset<8> complement = ~(num+1);
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

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Ввод числа №1" << endl;
    int num1;
    cin >> num1;
    cout << "Число введено: " << num1 << endl;
    decimalToBinary(num1);

    cout << "Ввод числа №2" << endl;
    int num2;
    cin >> num2;
    cout << "Число введено: " << num2 << endl;
    decimalToBinary(num2);

    cout << "Сложение:" << endl;
    addComplementary(num1, num2);
    cout << "Вычитание:" << endl;
    subtractComplementary(num1, num2);
    cout << "Усножение:" << endl;
    multiplyDirect(num1, num2);
    cout << "Деление:" << endl;
    divideDirect(num1, num2);

    cout << "Сложение с плавающей точкой:" << endl;
    float floatNum1, floatNum2;
    cout << "Ввод числа №1" << endl;
    cin >> floatNum1;
    cout << "Число введено: " << floatNum1 << endl;
    decimalToBinary(*reinterpret_cast<int*>(&floatNum1));

    cout << "Ввод числа №2" << endl;
    cin >> floatNum2;
    cout << "Число введено: " << floatNum2 << endl;
    decimalToBinary(*reinterpret_cast<int*>(&floatNum2));

    addFloatingPoint(floatNum1, floatNum2);


    return 0;
}
