#include "pch.h"
#include "CppUnitTest.h"
#include "../2024-ADS-Repeat-EmilyMcCormack/RPNCalculator.h"
#include <random> 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(TestAdd)
		{
			RPNCalculator<int> calc{};
			std::mt19937 rng{ std::random_device()() };
			// check 1000 random calculations
			for (auto i = 0; i < 1000; i++) {
				calc.clear();
				int a = rng();
				int b = rng();
				auto result = a + b;
				calc.push(a);
				calc.push(b);
				calc.add();
				Assert::AreEqual(result, calc.value());
			}
		}

		TEST_METHOD(TestSubtract)
		{

			RPNCalculator<int> calc{};
			std::mt19937 rng{ std::random_device()() };
			// check 1000 random calculations
			for (auto i = 0; i < 1000; i++) {
				calc.clear();
				int a = rng();
				int b = rng();
				auto result = a - b;
				calc.push(a);
				calc.push(b);
				calc.subtract();
				Assert::AreEqual(result, calc.value());
			}
		}

		TEST_METHOD(TestMultiply)
		{
			RPNCalculator<int> calc{};
			std::mt19937 rng{ std::random_device()() };
			// check 1000 random calculations
			for (auto i = 0; i < 1000; i++) {
				calc.clear();
				int a = rng();
				int b = rng();
				auto result = a * b;
				calc.push(a);
				calc.push(b);
				calc.multiply();
				Assert::AreEqual(result, calc.value());
			}
		}

		TEST_METHOD(TestDivide)
		{
			RPNCalculator<int> calc{};
			std::mt19937 rng{ std::random_device()() };
			// check 1000 random calculations
			for (auto i = 0; i < 1000; i++) {
				calc.clear();
				int a = rng();
				int b = rng();
				auto result = a / b;
				calc.push(a);
				calc.push(b);
				calc.divide();
				Assert::AreEqual(result, calc.value());
			}
		}
	};
}
