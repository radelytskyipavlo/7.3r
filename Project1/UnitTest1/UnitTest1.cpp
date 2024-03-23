#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTest1 {
    TEST_CLASS(UnitTest1) {
public:
    TEST_METHOD(TestFirstZeroColumn) {
        const int rowCount = 3;   const int colCount = 3;
        int** a = new int* [rowCount];   for (int i = 0; i < rowCount; i++)
            a[i] = new int[colCount];
        a[0][0] = 1; a[0][1] = 0; a[0][2] = 3;
        a[1][0] = 4; a[1][1] = 5; a[1][2] = 6;   a[2][0] = 7; a[2][1] = 8; a[2][2] = 9;
        int result = ColumnWithMostZerosRec(a, rowCount);
        Assert::AreEqual(1, result);
        for (int i = 0; i < rowCount; i++)
            delete[] a[i];   delete[] a;
    }
    };
}
