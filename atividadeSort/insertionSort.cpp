#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void insertionSort(int *vetor, int n)
{
    int i, aux, j;
    for (i = 1; i < n; i++)
    {
        aux = vetor[i];
        j = i - 1;

        while (j >= 0 && vetor[j] > aux)
        {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = aux;
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

    insertionSort(vetor, n);

    cout << "Array após a ordenacao: ";
    printArray(vetor, n);

    return 0;
}
