#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_1_rec/Lab_06_1_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest061rec
{
	TEST_CLASS(UnitTest061rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int n = 5;
			int x[n] = { 22, 6, -4, 0, -1 };
			int expectation = CountElements(x, n, 0, 0);
			int actual = 2;
			Assert::AreEqual(expectation, actual);
		}
	};
}
