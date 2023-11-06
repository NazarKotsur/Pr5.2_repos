#include "pch.h"
#include "CppUnitTest.h"
#include "../Pr5.2/Pr5.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest52
{
	TEST_CLASS(UnitTest52)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double x = 2;
			double eps = 0.00001;
			int n = 0;
			double s = 0;
			double expected = log((static_cast<double>(x) + 1) / (static_cast<double>(x) - 1));
			double actual = S(x, eps, n, s);
		}
	};
}
