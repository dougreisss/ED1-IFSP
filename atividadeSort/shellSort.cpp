#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void shellSort(int arr[], int n)
{
    int k = 1;
    while (k < n / 3)
    {
        k = 3 * k + 1;
    }

    while (k >= 1)
    {
        for (int i = k; i < n; i++)
        {
            int aux = arr[i];
            int j = i;
            while (j >= k && arr[j - k] > aux)
            {
                arr[j] = arr[j - k];
                j -= k;
            }
            arr[j] = aux;
        }

        k /= 3;
    }
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int vetor[] = {49, 38, 58, 87, 34, 93, 26, 13};
    int n = 8;

    cout << "Array original: ";
    printArray(vetor, n);

    shellSort(vetor, n);

    cout << "Array ordenado: ";
    printArray(vetor, n);

    return 0;
}