#include "pch.h"
#include "CppUnitTest.h"
#include "../TeamListSet/set.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ListSetTests
{
	TEST_CLASS(Constructors)
	{
	public:
		TEST_METHOD(DefaultConstuctor)
		{
			Set<int> A;
			Assert::IsTrue(A.IsEmpty());
		}
		TEST_METHOD(ExplicitConstructor)
		{
			Set<int> A{1};
			Assert::IsTrue(A.Size() == 1);
			Assert::IsTrue(A.Contains(1));
		}
	};
	TEST_CLASS(Methods)
	{

	};
}
