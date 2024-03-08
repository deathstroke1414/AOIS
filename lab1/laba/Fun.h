#pragma once
#include <iostream>
#include <bitset>
#include <iomanip>
#include <cmath>
#include <string>
#include "Windows.h"

using namespace std;

string decimalToBinary(int num);

string addComplementary(int num1, int num2);

string subtractComplementary(int num1, int num2);

string multiplyDirect(int num1, int num2);

string divideDirect(int num1, int num2);

string addFloatingPoint(float num1, float num2);