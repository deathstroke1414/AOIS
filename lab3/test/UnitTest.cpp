#include "pch.h"
#include "CppUnitTest.h"
#include "C:\AOIS\laba3\laba3\logic.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:
        TEST_METHOD(TestConstructor)
        {
            string expr = "A&B|C";
            Logic logic(expr);

            Assert::AreEqual(expr, logic.expr);
            Assert::IsTrue(!logic.truthTable.empty());
            Assert::IsTrue(!logic.pdnf.empty());
            Assert::IsTrue(!logic.pcnf.empty());
            Assert::AreEqual(logic.index_form, logic.getIndexForm());
        }

        TEST_METHOD(TestSetExpr)
        {
            string expr1 = "A&B|C";
            string expr2 = "A|B&C";
            Logic logic(expr1);

            logic.setExpr(expr2);
            Assert::AreEqual(expr2, logic.expr);
        }

        TEST_METHOD(TestGetPDNF)
        {
            string expr = "A&B|C";
            Logic logic(expr);
            Assert::IsTrue(!logic.getPDNF().empty());
        }

        TEST_METHOD(TestGetPCNF)
        {
            string expr = "A&B|C";
            Logic logic(expr);
            Assert::IsTrue(!logic.getPCNF().empty());
        }

        TEST_METHOD(TestGetVars)
        {
            string expr = "A&B|C";
            Logic logic(expr);
            Assert::IsTrue(!logic.getVars().empty());
        }

        TEST_METHOD(TestMakeTable)
        {
            string expr = "A&B|C";
            Logic logic(expr);
            logic.makeTable();
            Assert::IsTrue(!logic.truthTable.empty());
        }

        TEST_METHOD(TestMakePDNF)
        {
            string expr = "A&B|C";
            Logic logic(expr);
            logic.makePDNF();
            Assert::IsTrue(!logic.pdnf.empty());
        }

        TEST_METHOD(TestMakePCNF)
        {
            string expr = "A&B|C";
            Logic logic(expr);
            logic.makePCNF();
            Assert::IsTrue(!logic.pcnf.empty());
        }

        TEST_METHOD(TestMakeIndexForm)
        {
            string expr = "A&B|C";
            Logic logic(expr);
            logic.makeIndexForm();
            Assert::AreEqual(logic.index_form, logic.getIndexForm());
        }

        TEST_METHOD(TestMakeVars)
        {
            string expr = "A&B|C";
            Logic logic(expr);
            logic.makeVars();
            Assert::IsTrue(!logic.vars.empty());
        }

        TEST_METHOD(TestMakeCarnoTable)
        {
            string expr = "A&B|C";
            Logic logic(expr);
            logic.makeCarnoTable();
            Assert::IsTrue(!logic.carno_table.empty());
        }

        TEST_METHOD(TestMakeNumPDNF)
        {
            string expr = "A&B|C";
            Logic logic(expr);
            logic.makeNumPDNF();
            Assert::IsTrue(!logic.num_pdnf.empty());
        }

        TEST_METHOD(TestMakeNumPCNF)
        {
            string expr = "A&B|C";
            Logic logic(expr);
            logic.makeNumPCNF();
            Assert::IsTrue(!logic.num_pcnf.empty());
        }
    };
}
