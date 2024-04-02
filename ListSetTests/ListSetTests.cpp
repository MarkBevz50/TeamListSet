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
	TEST_CLASS(Methods)
	{
	public:
		TEST_METHOD(Add)
		{
			Set<int> A;
			A.Add(2);
			A.Add(3);
			A.Add(1);
			Assert::IsTrue(A.Size() == 3);
			A.Add(3);
			A.Add(2);
			A.Add(1);
			A.Add(1);
			A.Add(3);
			A.Add(2);
			Assert::IsTrue(A.Size() == 3);
			Assert::IsTrue(A.Contains(1));
			Assert::IsTrue(A.Contains(2));
			Assert::IsTrue(A.Contains(3));
		}

		TEST_METHOD(Remove)
		{
			Set<int> A;
			A.Add(1);
			A.Add(2);
			A.Remove(1);
			Assert::IsFalse(A.Contains(1));
			Assert::IsTrue(A.Contains(2));
		}

		TEST_METHOD(Size)
		{
			Set<int> A;
			A.Add(1);
			A.Add(2);
			Assert::AreEqual(A.Size(), static_cast<unsigned>(2));
		}

		TEST_METHOD(IsEmpty)
		{
			Set<int> A;
			Assert::IsTrue(A.IsEmpty());
			A.Add(1);
			Assert::IsFalse(A.IsEmpty());
		}

		TEST_METHOD(Contains)
		{
			Set<int> A;
			A.Add(1);
			A.Add(2);
			Assert::IsTrue(A.Contains(1));
			Assert::IsFalse(A.Contains(3));
		}

		TEST_METHOD(Intersection)
		{
			int arr[] = { 1, 2, 3 };
			Set<int> A{ arr, 3};
			int barr[] = { 2,3,4 };
			Set<int> B{ barr, 3 };
			Set<int> result = A.Intersection(B);
			Assert::IsTrue(result.Contains(2));
			Assert::IsTrue(result.Contains(3));
			Assert::IsFalse(result.Contains(1));
			Assert::IsFalse(result.Contains(4));
		}

		TEST_METHOD(Difference)
		{
			int arr[] = { 1, 2, 3 };
			Set<int> A{ arr, 3 };
			int barr[] = { 2,3,4 };
			Set<int> B{ barr, 3 };
			Set<int> result = A.Difference(B);
			Assert::IsTrue(result.Contains(1));
			Assert::IsFalse(result.Contains(2));
			Assert::IsFalse(result.Contains(3));
			Assert::IsFalse(result.Contains(4));
		}
	};
	
}
