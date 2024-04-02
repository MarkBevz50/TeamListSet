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
			Assert::IsFalse(A.Contains(0));
		}
		TEST_METHOD(ExplicitConstructor)
		{
			Set<int> A{ 1 };
			Assert::IsTrue(A.Size() == 1);
			Assert::IsTrue(A.Contains(1));
			Assert::IsFalse(A.Contains(0));
		}
		TEST_METHOD(CopyConstructor)
		{
			Set<int> A{ 1 };
			Set<int> B{ A };
			Assert::IsTrue(B.Size() == 1);
			Assert::IsTrue(B.Contains(1));
			Assert::IsFalse(B.Contains(0));
		}
		TEST_METHOD(IterableConstructor)
		{
			int arr[] = { 1, 2, 3, 4 };
			Set<int> A{ arr, 4 };
			Assert::IsTrue(A.Size() == 4);
			Assert::IsTrue(A.Contains(1));
			Assert::IsTrue(A.Contains(2));
			Assert::IsTrue(A.Contains(3));
			Assert::IsTrue(A.Contains(4));
			Assert::IsFalse(A.Contains(0));
		}
		TEST_METHOD(Destructor)
		{
			Set<int> A;
			A.Add(1);
			Assert::IsFalse(A.IsEmpty());
			Assert::IsFalse(A.Contains(0));
			A.~Set();
			Assert::IsTrue(A.IsEmpty());
			Assert::IsFalse(A.Contains(0));
		}
	};
	TEST_CLASS(Operators)
	{
		TEST_METHOD(OperatorEquals)
		{
			int arr[] = { 1, 2, 3, 4 };
			Set<int> A{ arr, 4 };
			Set<int> B{ A };
			Assert::AreNotEqual(A.Get(1), B.Get(1));
			Assert::AreEqual(A.IsEmpty(), B.IsEmpty());
			Assert::AreEqual(A.Size(), B.Size());
		}
	};
}
