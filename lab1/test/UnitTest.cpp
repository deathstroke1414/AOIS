#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <bitset>
#include <iomanip>
#include <cmath>
#include "Windows.h"
#include "C:\AOIS\l1\\l1\\fun.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        TEST_METHOD(TestDecimalToBinary)
        {
            stringstream buffer;
            streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

            decimalToBinary(5);

            string expectedOutput = "Прямой код: 00000101\nОбратный код: 11111010\nДополнительный код: 11111011\n\n";
            Assert::AreEqual(expectedOutput, buffer.str());

            cout.rdbuf(oldCout);
        }

        TEST_METHOD(TestAddComplementary)
        {
            stringstream buffer;
            streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

            addComplementary(5, 3);

            string expectedOutput = "Результат: 8\nРезультат в двоичной системе: 00001000\n";
            Assert::AreEqual(expectedOutput, buffer.str());

            cout.rdbuf(oldCout);
        }

        TEST_METHOD(TestSubtractComplementary)
        {
            stringstream buffer;
            streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

            subtractComplementary(5, 3);

            string expectedOutput = "Результат: 2\nРезультат в двоичной системе: 00000010\n";
            Assert::AreEqual(expectedOutput, buffer.str());

            cout.rdbuf(oldCout);
        }

        TEST_METHOD(TestMultiplyDirect)
        {
            stringstream buffer;
            streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

            multiplyDirect(5, 3);

            string expectedOutput = "Произведение: 15\nПроизведение в двоичной системе: 00001111\n";
            Assert::AreEqual(expectedOutput, buffer.str());

            cout.rdbuf(oldCout);
        }

        TEST_METHOD(TestDivideDirect)
        {
            stringstream buffer;
            streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

            divideDirect(5, 3);

            string expectedOutput = "Результат: 1\nРезультат в двоичной системе: 00000001\n";
            Assert::AreEqual(expectedOutput, buffer.str());

            cout.rdbuf(oldCout);
        }

        TEST_METHOD(TestAddFloatingPoint)
        {
            stringstream buffer;
            streambuf* oldCout = cout.rdbuf(buffer.rdbuf());

            addFloatingPoint(5.5f, 3.2f);

            string expectedOutput = "Результат: 8.7\nПрямой код: 00110011\nОбратный код: 11001100\nДополнительный код: 11001101\n\n";
            Assert::AreEqual(expectedOutput, buffer.str());

            cout.rdbuf(oldCout);
        }

        TEST_METHOD(TestAddBinary)
        {
            bitset<8> a(5); 
            bitset<8> b(3); 
            bitset<8> result = addBinary(a, b);

            bitset<8> expected("00001000");
            Assert::AreEqual(expected.to_string(), result.to_string());
        }

        TEST_METHOD(TestSubtractBinary)
        {
            bitset<8> a(5);
            bitset<8> b(3); 
            bitset<8> result = subtractBinary(a, b);

            bitset<8> expected("00000010");
            Assert::AreEqual(expected.to_string(), result.to_string());
        }

        TEST_METHOD(TestMultiplyBinary)
        {
            bitset<8> a(5);  
            bitset<8> b(3);  
            bitset<8> result = multiplyBinary(a, b);

            bitset<8> expected("00001111");
            Assert::AreEqual(expected.to_string(), result.to_string());
        }

        TEST_METHOD(TestDivideBinary)
        {
            bitset<8> a(5);
            bitset<8> b(3);
            bitset<8> result = divideBinary(a, b);

            bitset<8> expected("00000001");
            Assert::AreEqual(expected.to_string(), result.to_string());
        }
    };
}
