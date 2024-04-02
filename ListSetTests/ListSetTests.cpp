#include "pch.h"
#include "CppUnitTest.h"
#include "../TeamListSet/set.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//namespace ListSetTests
//{
//	TEST_CLASS(Constructors)
//	{
//	public:
//		TEST_METHOD(DefaultConstuctor)
//		{
//			Set<int> A;
//			Assert::IsTrue(A.IsEmpty());
//		}
//		TEST_METHOD(ExplicitConstructor)
//		{
//			Set<int> A{1};
//			Assert::IsTrue(A.Size() == 1);
//			Assert::IsTrue(A.Contains(1));
//		}
//	};
//	TEST_CLASS(Methods)
//	{
//
//	};
//}
namespace SetTests {
    TEST_CLASS(Constructors) {
public:
    TEST_METHOD(DefaultConstructor) {
        Set<int> A;
        Assert::IsTrue(A.IsEmpty());
        Assert::AreEqual(static_cast<unsigned>(0), A.Size());
    }

    TEST_METHOD(ExplicitConstructor) {
        Set<int> A;
        A.Add(1);
        Assert::IsTrue(A.Size() == 1);
        Assert::IsTrue(A.Contains(1));
    }

    TEST_METHOD(SequenceConstructor) {
        Set<int> mySet;
        int values[] = { 1, 2, 3, 4, 5 };
        int size = sizeof(values) / sizeof(values[0]);
        for (int i = 0; i < size; ++i) {
            mySet.Add(values[i]);
        }
        Assert::IsTrue(mySet.Size() == size);
        for (int i = 0; i < size; ++i) {
            Assert::IsTrue(mySet.Contains(values[i]));
        }
    }
    };

    TEST_CLASS(Methods) {
public:
    TEST_METHOD(Add) {
        Set<int> A;
        A.Add(1);
        Assert::IsTrue(A.Contains(1));
    }

    TEST_METHOD(Contains) {
        Set<int> A;
        A.Add(1);
        A.Add(2);
        A.Add(3);
        Assert::IsTrue(A.Contains(1));
        Assert::IsTrue(A.Contains(2));
        Assert::IsTrue(A.Contains(3));
        Assert::IsFalse(A.Contains(4));
    }

    TEST_METHOD(Difference) {
        Set<int> A;
        A.Add(1);
        A.Add(2);
        A.Add(3);
        Set<int> B;
        B.Add(2);
        B.Add(3);
        B.Add(4);
        Set<int> result = A.Difference(B);
        Assert::IsFalse(result.Contains(1));
        Assert::IsFalse(result.Contains(2));
        Assert::IsFalse(result.Contains(3));
        Assert::IsTrue(result.Contains(4));
    }

    TEST_METHOD(Intersection) {
        Set<int> A;
        A.Add(1);
        A.Add(2);
        A.Add(3);
        Set<int> B;
        B.Add(2);
        B.Add(3);
        B.Add(4);
        Set<int> result = A.Intersection(B);
        Assert::IsFalse(result.Contains(1));
        Assert::IsTrue(result.Contains(2));
        Assert::IsTrue(result.Contains(3));
        Assert::IsFalse(result.Contains(4));
    }

    TEST_METHOD(Remove) {
        Set<int> A;
        A.Add(1);
        A.Add(2);
        A.Add(3);
        A.Remove(2);
        Assert::IsFalse(A.Contains(2));
        Assert::IsTrue(A.Size() == 2);
    }

    TEST_METHOD(Size) {
        Set<int> A;
        A.Add(1);
        A.Add(2);
        A.Add(3);
        Assert::IsTrue(A.Size() == 3);
    }

    TEST_METHOD(IsEmpty) {
        Set<int> A;
        Assert::IsTrue(A.IsEmpty());
        Set<int> B;
        B.Add(1);
        Assert::IsFalse(B.IsEmpty());
    }
    };
}
