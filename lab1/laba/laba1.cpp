#include <iostream>
#include <bitset>
#include <iomanip>
#include <cmath>
#include <string>
#include "Fun.h"
#include "Windows.h"

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
