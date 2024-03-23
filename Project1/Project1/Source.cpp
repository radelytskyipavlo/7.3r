#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < N - 1)
        CreateRow(a, rowNo, N, Low, High, colNo + 1);
}

void CreateRows(int** a, const int K, const int N, const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, N, Low, High, 0);
    if (rowNo < K - 1)
        CreateRows(a, K, N, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < N - 1)
        PrintRow(a, rowNo, N, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int K, const int N, int rowNo)
{
    PrintRow(a, rowNo, N, 0);
    if (rowNo < K - 1)
        PrintRows(a, K, N, rowNo + 1);
    else
        cout << endl;
}

void Rotate90DegreesRec(int**& a, const int n, int numberOfRepetitions, int layer = 0, int j = 0, int repeat = 0) {
    if (repeat >= numberOfRepetitions) return;

    if (layer < n / 2) {
        if (j < n - layer - 1) {
            int temp = a[layer][j];
            a[layer][j] = a[n - j - 1][layer];
            a[n - j - 1][layer] = a[n - layer - 1][n - j - 1];
            a[n - layer - 1][n - j - 1] = a[j][n - layer - 1];
            a[j][n - layer - 1] = temp;

            Rotate90DegreesRec(a, n, numberOfRepetitions, layer, j + 1, repeat);
        }
        else {
            Rotate90DegreesRec(a, n, numberOfRepetitions, layer + 1, layer + 1, repeat);
        }
    }
    else if (repeat < numberOfRepetitions - 1) {
        Rotate90DegreesRec(a, n, numberOfRepetitions, 0, 0, repeat + 1);
    }
}

int ColumnWithMostZerosRec(int** a, int n) {
    int maxZeros = 0;
    int columnIndex = -1;
    for (int j = 0; j < n; j++) {
        int currentZeros = 0;
        for (int i = 0; i < n; i++) {
            if (a[i][j] == 0) {
                currentZeros++;
            }
        }
        if (currentZeros > maxZeros) {
            maxZeros = currentZeros;
            columnIndex = j;
        }
        else if (currentZeros == maxZeros && currentZeros != 0) {
            columnIndex = j;
        }
    }
    return columnIndex;
}

int main() {
    srand((unsigned)time(NULL));
    int Low = -5;
    int High = 5;
    int n, numberOfRepetitions;
    cout << "n = "; cin >> n;
    cout << "k = "; cin >> numberOfRepetitions;

    int** a = new int* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
    }

    CreateRows(a, n, n, Low, High, 0);
    PrintRows(a, n, n, 0);

    Rotate90DegreesRec(a, n, numberOfRepetitions);

    PrintRows(a, n, n, 0);

    int colWithMostZeros = ColumnWithMostZerosRec(a, n);
    cout << "The number of the last column, which includes the highest amount of zeros: "
        << colWithMostZeros + 1 << endl;

    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
