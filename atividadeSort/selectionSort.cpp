#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void selectionSort(int *vetor, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (vetor[j] < vetor[minIndex])
            {
                minIndex = j;
            }
        }
        swap(vetor[i], vetor[minIndex]);
    }
}

void printArray(int *vetor, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << vetor[i] << " ";
    }
    cout << endl;
}

int main()
{
    int vetor[] = {49, 38, 58, 87, 34, 93, 26, 13};
    int n = 8;

    cout << "Array antes da ordenacao: ";
    printArray(vetor, n);

    selectionSort(vetor, n);

    cout << "Array apos a ordenacao: ";
    printArray(vetor, n);

    return 0;
}
