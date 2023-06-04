#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int dividir(int vetor[], int esq, int dir)
{
    int aux;
    int cont = esq;

    for (int i = esq + 1; i <= dir; i++)
    {

        if (vetor[i] < vetor[esq])
        {
            cont++;
            aux = vetor[i];
            vetor[i] = vetor[cont];
            vetor[cont] = aux;
        }
    }

    aux = vetor[esq];
    vetor[esq] = vetor[cont];
    vetor[cont] = aux;

    return cont;
}

void QuickSort(int vetor[], int esq, int dir)
{
    int pos;
    if (esq < dir)
    {
        pos = dividir(vetor, esq, dir);
        QuickSort(vetor, esq, pos - 1);
        QuickSort(vetor, pos + 1, dir);
    }
}

void printArray(int *arr, int n)
{
    for (int i = 0; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int vetor[] = {49, 38, 58, 87, 34, 93, 26, 13};
    int n = 7;

    cout << "Array original: ";
    printArray(vetor, n);

    QuickSort(vetor, 0, n);

    cout << "Array ordenado: ";
    printArray(vetor, n);

    return 0;
}