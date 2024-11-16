// Lab_06_1_rec

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void CreateArrayWithRandomElements(int* x, int numberOfElements, int Low, int High, int i);
void PrintArray(int* x, const int numberOfElements, int i);
int CountElements(int* x, int numberOfElements, int count, int i);
int SumElements(int* x, int numberOfElements, int sum, int i);
void TurnToZero(int* x, int numberOfElements, int i);

int main()
{
    srand((unsigned)time(NULL));

    const int n = 24;
    int x[n];

    int Low = -17;
    int High = 53;
    CreateArrayWithRandomElements(x, n, Low, High, 0);
    cout << "Array with Random elements:" << endl;
    PrintArray(x, n, 0);
    cout << "Count: " << setw(1) << CountElements(x, n, 0, 0) << endl;
    cout << "Sum: " << setw(1) << SumElements(x, n, 0, 0) << endl;
    TurnToZero(x, n, 0);
    PrintArray(x, n, 0);
}

void CreateArrayWithRandomElements(int* x, int numberOfElements, int Low, int High, int i) {
    if (i < numberOfElements) {
        x[i] = Low + rand() % (High - Low + 1);
        CreateArrayWithRandomElements(x, numberOfElements, Low, High, i + 1);
    }
}

void PrintArray(int* x, const int numberOfElements, int i) {
    if (i < numberOfElements) {
        cout << "{ x[" << setw(2) << i << "] = " << setw(3) << x[i] << " }  ";
        if ((i + 1) % 7 == 0) {
            cout << endl;
        }
        PrintArray(x, numberOfElements, i + 1);
    }
    else {
        cout << endl;
    }
}

int CountElements(int* x, int numberOfElements, int count, int i) {
    if (i < numberOfElements) {
        if (x[i] < 0 && !(x[i] % 3 == 0)) {
            count++;
        }
        return CountElements(x, numberOfElements, count, i + 1);
    }
    return count;
}

int SumElements(int* x, int numberOfElements, int sum, int i) {
    if (i < numberOfElements) {
        if (x[i] < 0 && !(x[i] % 3 == 0)) {
            sum += x[i];
        }
        return SumElements(x, numberOfElements, sum, i + 1);
    }
    return sum;
}

void TurnToZero(int* x, int numberOfElements, int i) {
    if (i < numberOfElements) {
        if (x[i] < 0 && !(x[i] % 3 == 0)) {
            x[i] = 0;
        }
        TurnToZero(x, numberOfElements, i + 1);
    }
}