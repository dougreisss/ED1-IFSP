#include <iostream>
#include <iomanip>
#include <locale.h>

using namespace std;

#define qtdCartas 52
#define qtdBaralhos 2

#define qtdJogadores 4
#define qtdCartasMao 11

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "");

    int **matrizCartas = new int *[qtdBaralhos];
    int **matrizJogadores = new int *[qtdJogadores];
    int valorCarta = 1021;
    int valorCartaSegundaPassagem = 2021;
    int valorCartaTerceiraPassagem = 2981;
    int valorCartaQuartaPassagem = 3981;
    int cartaSorteada = 0;
    int baralhoSorteado = 0;
    bool check;

    for (int i = 0; i < qtdBaralhos; i++)
    {
        matrizCartas[i] = new int[qtdCartas];
    }

    for (int i = 0; i < qtdJogadores; i++)
    {
        matrizJogadores[i] = new int[qtdCartasMao];
    }

    for (int i = 0; i < qtdBaralhos; ++i)
    {
        if (i == 1)
        {
            valorCarta = 1012;
            valorCartaSegundaPassagem = 2002;
            valorCartaTerceiraPassagem = 2992;
            valorCartaQuartaPassagem = 3982;
        }

        for (int j = 0; j < qtdCartas; ++j)
        {
            switch (j)
            {
            case 12:
                valorCarta = valorCartaSegundaPassagem;
                break;
            case 24:
                valorCarta = valorCartaTerceiraPassagem;
                break;
            case 36:
                valorCarta = valorCartaQuartaPassagem;
                break;
            }

            matrizCartas[i][j] = valorCarta;
            valorCarta += 10;
            // cout << "baralho[" << i << "][" << j << "] = " << matrizCartas[i][j] << endl;
        }
    }

    for (int i = 0; i < qtdJogadores; i++)
    {
        for (int j = 0; j < qtdCartasMao; j++)
        {
            do
            {
                cartaSorteada = rand() % 52;
                baralhoSorteado = rand() % 2;
                check = true;

                if (matrizCartas[baralhoSorteado][cartaSorteada] == 0)
                {
                    check = false;
                }

            } while (!check);

            matrizJogadores[i][j] = matrizCartas[baralhoSorteado][cartaSorteada];
            matrizCartas[baralhoSorteado][cartaSorteada] = 0;

            cout << setw(5) << "mao[" << i << "][" << j << "]: " << matrizJogadores[i][j];
            cout << endl;
        }
    }

    delete[] matrizCartas;
    delete[] matrizJogadores;

    return 0;
}