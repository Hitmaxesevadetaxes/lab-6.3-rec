#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\HP\source\repos\lab 6.3 rec\lab 6.3 rec\Source.cpp"
#include <vector>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::vector<int> arr = { 1, 2, 3, 4, 5, 6 };
			int initialMax = std::numeric_limits<int>::min();

			// Act
			int result = findMaxEvenRecursive(arr, 0, initialMax);

			// Assert
			Assert::AreEqual(6, result);
		}
	};
}
