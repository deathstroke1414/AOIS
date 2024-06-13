#include "pch.h"
#include "CppUnitTest.h"
#include "C:\AOIS\laba7\laba7\CM.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestGetValue)
		{
			ConstMatrix matrix;
			Assert::AreEqual(1, matrix.getValue(0, 0));
			Assert::AreEqual(0, matrix.getValue(1, 0));
		}

		TEST_METHOD(TestSetValue)
		{
			ConstMatrix matrix;
			matrix.setValue(0, 0, 0);
			Assert::AreEqual(0, matrix.getValue(0, 0));
		}

		TEST_METHOD(TestFindWordPosition)
		{
			ConstMatrix matrix;
			string word = "0000011000000000";
			int position = matrix.findWordPosition(word, true);
			Assert::AreNotEqual(5, position);

			position = matrix.findWordPosition(word, false);
			Assert::AreNotEqual(5, position);
		}

		TEST_METHOD(TestF1Function)
		{
			ConstMatrix matrix;
			string firstWord = "1010";
			string secondWord = "1100";
			string result = matrix.f1Function(firstWord, secondWord);
			Assert::AreEqual(string("1000"), result);
		}

		TEST_METHOD(TestF14Function)
		{
			ConstMatrix matrix;
			string firstWord = "1010";
			string secondWord = "1100";
			string result = matrix.f14Function(firstWord, secondWord);
			Assert::AreEqual(string("0111"), result);
		}

		TEST_METHOD(TestF3Function)
		{
			ConstMatrix matrix;
			string firstWord = "1010";
			string secondWord = "1100";
			string result = matrix.f3Function(firstWord, secondWord);
			Assert::AreEqual(firstWord, result);
		}

		TEST_METHOD(TestF12Function)
		{
			ConstMatrix matrix;
			string firstWord = "1010";
			string secondWord = "1100";
			string result = matrix.f12Function(firstWord, secondWord);
			Assert::AreEqual(string("0101"), result);
		}

		TEST_METHOD(TestSummAB)
		{
			ConstMatrix matrix;
			string key = "101";
			string result = matrix.summAB(key);
			Assert::AreEqual(16, (int)result.size());
		}

		TEST_METHOD(TestPrintMatrix)
		{
			ConstMatrix matrix;
			std::stringstream buffer;
			std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
			matrix.printMatrix();
			std::cout.rdbuf(old);

			std::string expectedOutput =
				"1 1 1 1 0 0 0 1 0 0 0 1 0 1 0 0 \n"
				"0 0 0 1 0 0 0 1 0 0 1 1 1 1 0 0 \n"
				"1 1 0 1 0 1 1 0 0 0 1 1 0 0 0 0 \n"
				"1 1 0 1 1 0 0 1 1 1 1 0 0 0 1 0 \n"
				"0 1 1 0 1 1 0 0 0 0 1 1 0 1 0 1 \n"
				"1 1 0 1 0 1 1 0 0 0 0 1 0 0 1 1 \n"
				"0 0 0 1 0 1 1 1 0 0 0 1 0 1 0 0 \n"
				"0 1 0 0 0 1 0 0 1 0 0 1 1 0 0 0 \n"
				"0 0 0 0 1 0 0 1 0 1 1 0 0 0 0 1 \n"
				"0 1 1 0 1 1 0 1 0 0 0 0 1 1 1 1 \n"
				"0 1 0 0 0 1 1 0 0 1 0 1 1 1 1 1 \n"
				"1 0 0 1 0 1 1 1 0 1 1 0 1 0 1 0 \n"
				"0 1 0 0 0 0 0 0 1 1 0 0 1 0 0 0 \n"
				"1 0 0 1 1 0 0 0 1 1 1 1 1 0 0 1 \n"
				"1 1 1 0 1 0 0 0 0 0 0 1 0 0 0 1 \n"
				"0 0 0 0 0 1 1 1 1 1 1 1 1 0 0 0 \n";

			Assert::AreEqual(expectedOutput, buffer.str());
		}

		TEST_METHOD(TestGetWordFromMatrix)
		{
			ConstMatrix matrix;
			string word = matrix.getWordFromMatrix(0);
			Assert::AreEqual(string("1011"), word.substr(0, 4));
		}

		TEST_METHOD(TestGetAddressRowWord)
		{
			ConstMatrix matrix;
			string rowWord = matrix.getAddressRowWord(0);
			Assert::AreEqual(string("10011110"), rowWord.substr(0, 8));
		}

		TEST_METHOD(TestSetWord)
		{
			ConstMatrix matrix;
			string newWord = "1010101010101010";
			matrix.setWord(0, newWord);
			for (int i = 0; i < 16; i++) {
				Assert::AreEqual(newWord[i] - '0', matrix.getValue(i, 0));
			}
		}
	};
}
