#include "pch.h"
#include "CppUnitTest.h"
#include "C:\AOIS\testLaba2\testLaba2\laba2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testLaba2
{
    TEST_CLASS(StackTests)
    {
    public:
        TEST_METHOD(DeleteFunctionTest)
        {
            Stack* stack = nullptr;
            char output;
            stack = add(stack, 'a');
            stack = del(stack, &output);
            Assert::AreEqual(output, 'a');
            Assert::IsNull(stack);
        }

        TEST_METHOD(AddFunctionTest)
        {
            Stack* stack = nullptr;
            stack = add(stack, 'b');
            Assert::AreEqual(stack->info, 'b');
            Assert::IsNull(stack->next);
        }
    };

    TEST_CLASS(PriorityTests)
    {
    public:
        TEST_METHOD(PriorityFunctionTest)
        {
            Assert::AreEqual(prioritet('!'), 5);
            Assert::AreEqual(prioritet('>'), 2);
            Assert::AreEqual(prioritet('&'), 4);
            Assert::AreEqual(prioritet('|'), 3);
            Assert::AreEqual(prioritet('('), 1);
        }

        TEST_METHOD(InvalidPriorityFunctionTest)
        {
            Assert::AreEqual(prioritet('x'), 0);
        }
    };

    TEST_CLASS(ResultTests)
    {
    public:
        TEST_METHOD(ResultFunctionTest)
        {
            Assert::IsFalse(result("ab&"));
            Assert::IsTrue(result("!a"));
        }

        TEST_METHOD(SingleOperandTest)
        {
            mas[int('a')] = true;
            Assert::IsFalse(result("a"));
            Assert::IsTrue(result("!a"));
        }

        TEST_METHOD(BasicOperationsTest)
        {
            mas[int('a')] = true;
            mas[int('b')] = false;
            Assert::IsFalse(result("ab&"));
            Assert::IsTrue(result("!a"));
        }

        TEST_METHOD(ComplexExpressionsTest)
        {
            mas[int('a')] = true;
            mas[int('b')] = false;
            mas[int('c')] = true;
            Assert::IsFalse(result("a|(b&c)"));
            Assert::IsTrue(result("!((a&b)|c)"));
            Assert::IsFalse(result("(a>b)"));
            Assert::IsTrue(result("(a-b)"));
        }
    };

    TEST_CLASS(EvaluateTests)
    {
    public:
        TEST_METHOD(EvaluateFunctionTest)
        {
            OutStr = "";
            evaluate("a&b");
            Assert::AreEqual(OutStr.c_str(), "ab&");

            OutStr = "";
            evaluate("!a");
            Assert::AreEqual(OutStr.c_str(), "a!");

            OutStr = "";
            evaluate("a|(b&c)");
            Assert::AreEqual(OutStr.c_str(), "abc&|");

            OutStr = "";
            evaluate("!((a&b)|c)");
            Assert::AreEqual(OutStr.c_str(), "ab&c|!");

            OutStr = "";
            evaluate("(a>b)");
            Assert::AreEqual(OutStr.c_str(), "ab>");

            OutStr = "";
            evaluate("(a-b)");
            Assert::AreEqual(OutStr.c_str(), "ab-");
        }
    };

    TEST_CLASS(TruthTableTests)
    {
    public:
        TEST_METHOD(TruthTableFunctionTest)
        {
            printTruthTable("a&b");
            Assert::AreEqual(static_cast<int>(sdnf.size()), 1);
            Assert::AreEqual(static_cast<int>(sknf.size()), 3);

            printTruthTable("!a");
            Assert::AreEqual(static_cast<int>(sdnf.size()), 2);
            Assert::AreEqual(static_cast<int>(sknf.size()), 4);

            printTruthTable("a|(b&c)");
            Assert::AreEqual(static_cast<int>(sdnf.size()), 7);
            Assert::AreEqual(static_cast<int>(sknf.size()), 7);

            printTruthTable("!((a&b)|c)");
            Assert::AreEqual(static_cast<int>(sdnf.size()), 10);
            Assert::AreEqual(static_cast<int>(sknf.size()), 12);

            printTruthTable("(a>b)");
            Assert::AreEqual(static_cast<int>(sdnf.size()), 13);
            Assert::AreEqual(static_cast<int>(sknf.size()), 13);

            printTruthTable("(a-b)");
            Assert::AreEqual(static_cast<int>(sdnf.size()), 16);
            Assert::AreEqual(static_cast<int>(sknf.size()), 14);
        }
    };

    TEST_CLASS(UnusedCodeTests)
    {
    public:
        TEST_METHOD(ChdAndChkNotEmptyTest)
        {
            Assert::IsFalse(chd.empty());
            Assert::IsFalse(chk.empty());
        }

        TEST_METHOD(IndNotEmptyTest)
        {
            Assert::IsFalse(ind.empty());
        }
    };
}
