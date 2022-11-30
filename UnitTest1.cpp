#include "pch.h"
#include "CppUnitTest.h"
#include "../лб 3 іпз/лб 3 іпз.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(calculatingTests) // ініциалізація класу, який порівнює результат обчисленого та очікуваного результату
	{
	public:

		TEST_METHOD(firstCalculatingTest)
		{
			int a = -2;
			int b = 8;
			int h = 1;
			int n = 5;
			int expected = 800;
			int actual = calculate(a, b, h, n);
			Assert::AreEqual(expected, actual);// порівнює, якщо очікувані дані дорівнюють фактичним
		}
	public:
		TEST_METHOD(secondCalculatingTest)
		{
			int a = -3;
			int b = 15;
			int h = 1;
			int n = 7;
			int expected = 536599;
			int actual = calculate(a, b, h, n);
			Assert::AreEqual(expected, actual);// порівнює, якщо очікувані дані дорівнюють фактичним
		}
	};

	TEST_CLASS(checkEnterData)
	{
	public:
		TEST_METHOD(firstCheckingEnterDataTRUE)
		{
			int a = -7;
			int b = 7;

			try
			{
				checkLoopBoundsValidity(a, b);
				Assert::IsTrue(true);// якщо checkUpperBoundValidity(n) правильне, тестування виконається правильно
			}

			catch (...)
			{
				Assert::Fail();// якщо дані checkUpperBoundValidity(n) не коректні, тестування виконається не правильно
			}
		}
	public:
		TEST_METHOD(secondCheckingEnterDataTRUE)
		{
			int h = -5;
			try
			{
				checkLoopStepValidity(h);
				Assert::IsTrue(true);// якщо checkUpperBoundValidity(n) правильне, тестування виконається правильно
			}
			catch (...)
			{
				Assert::Fail();// якщо дані checkUpperBoundValidity(n) не коректні, тестування виконається не правильно
			}
		}
	public:
		TEST_METHOD(firstcheckingEnterDataFalse)
		{
			int n = 3;
			try
			{
				checkUpperBoundValidity(n);
				Assert::IsTrue(true);// якщо checkUpperBoundValidity(n) правильне, тестування виконається правильно
			}
			catch (...)
			{
				Assert::Fail();// якщо дані checkUpperBoundValidity(n) не коректні, тестування виконається не правильно
			}

		}
	};
}














