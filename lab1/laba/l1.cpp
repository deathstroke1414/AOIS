#include <iostream>
#include "Windows.h"
#include "fun.h"

using namespace std;

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
    {
        std::bitset<8> result = addBinary(std::bitset<8>(num1), std::bitset<8>(num2));
        cout << "Результат в двоичной системе: " << result << endl;
        cout << "Результат: " << result.to_ulong() << endl;
    }

    cout << "Вычитание:" << endl;
    {
        std::bitset<8> result = subtractBinary(std::bitset<8>(num1), std::bitset<8>(num2));
        cout << "Результат в двоичной системе: " << result << endl;
        cout << "Результат: " << result.to_ulong() << endl;
    }

    cout << "Умножение:" << endl;
    {
        std::bitset<8> result = multiplyBinary(std::bitset<8>(num1), std::bitset<8>(num2));
        cout << "Результат в двоичной системе: " << result << endl;
        cout << "Результат: " << result.to_ulong() << endl;
    }

    cout << "Деление:" << endl;
    {
        std::bitset<8> result = divideBinary(std::bitset<8>(num1), std::bitset<8>(num2));
        cout << "Результат в двоичной системе: " << result << endl;
        cout << "Результат: " << result.to_ulong() << endl;
    }

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
