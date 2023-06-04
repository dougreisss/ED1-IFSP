#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void merge(int *vetor, int esq, int meio, int dir)
{
    int i, j, k;
    int n1 = meio - esq + 1;
    int n2 = dir - meio;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = vetor[esq + i];
    }

    for (j = 0; j < n2; j++)
    {
        R[j] = vetor[meio + 1 + j];
    }

    i = 0;
    j = 0;
    k = esq;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            vetor[k] = L[i];
            i++;
        }
        else
        {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        vetor[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        vetor[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *vetor, int esq, int dir)
{
    if (esq < dir)
    {
        int meio = esq + (dir - esq) / 2;

        mergeSort(vetor, esq, meio);
        mergeSort(vetor, meio + 1, dir);

        merge(vetor, esq, meio, dir);
    }
}

void printArray(int *vetor, int n)
{
    for (int i = 0; i < n; i++)
        cout << vetor[i] << " ";
    cout << endl;
}

int main()
{
    int vetor[] = {49, 38, 58, 87, 34, 93, 26, 13};
    int n = 8;

    cout << "Array antes da ordenacao: ";
    printArray(vetor, n);

    mergeSort(vetor, 0, n - 1);

    cout << "Array apos a ordenacao: ";
    printArray(vetor, n);

    return 0;
}