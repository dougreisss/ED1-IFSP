#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

using namespace std;

#define MAX 30

struct Par
{
    int qtd;
    float valor[MAX];
};

struct Impar
{
    int qtd;
    float valor[MAX];
};

Par *IniciarPar()
{
    Par *par = new Par;

    par->qtd = 0;

    return par;
}

Impar *IniciarImpar()
{
    Impar *impar = new Impar;

    impar->qtd = 0;

    return impar;
}

int InserirPar(Par *par, int numero)
{

    int empilhar = (par->qtd < MAX);

    if (empilhar)
    {
        par->valor[par->qtd] = numero;
        par->qtd++;
    }

    return empilhar;
}

int InserirImpar(Impar *impar, int numero)
{

    int empilhar = (impar->qtd < MAX);

    if (empilhar)
    {
        impar->valor[impar->qtd] = numero;
        impar->qtd++;
    }

    return empilhar;
}

void ImprimirPar(Par *par)
{
    for (int i = par->qtd - 1; i >= 0; i--)
    {
        cout << par->valor[i] << " ";
    }
}

void ImprimirImpar(Impar *impar)
{

    for (int i = impar->qtd - 1; i >= 0; i--)
    {
        cout << impar->valor[i] << " ";
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Par *par = IniciarPar();
    Impar *impar = IniciarImpar();

    int valorNumero = 0;
    int valorAux = 0;

    cout << "Digite o 1º valor: ";
    cin >> valorNumero;

    if (valorNumero % 2 == 0)
    {
        InserirPar(par, valorNumero);
    }
    else
    {
        InserirImpar(impar, valorNumero);
    }

    for (int i = 2; i <= MAX; i++)
    {
        valorAux = valorNumero;

        do
        {
            cout << "Digite o " << i << "º valor:";
            cin >> valorNumero;
        } while (valorNumero <= valorAux);

        if (valorNumero % 2 == 0)
        {
            InserirPar(par, valorNumero);
        }
        else
        {
            InserirImpar(impar, valorNumero);
        }
    }

    cout << "Números Pares: ";
    ImprimirPar(par);
    cout << endl;
    cout << "Números Impares: ";
    ImprimirImpar(impar);

    free(par);
    free(impar);

    return 0;
}