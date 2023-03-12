#include <iostream>
#include <iomanip>
#include <locale.h>

using namespace std;

#define fileiras 15
#define poltronas 40

void reservar(int **matriz, int &faturamento, int &qtdReservas)
{
    int fileira = 0;
    int poltrona = 0;

    cout << "Digite uma fileira: " << endl;
    cin >> fileira;

    cout << "Digite uma poltrona: " << endl;
    cin >> poltrona;

    if (fileira < 0 || fileira > 15)
    {
        cout << "Digite uma fileira valida" << endl;
        return;
    }

    if (poltrona < 0 || poltrona > 40)
    {
        cout << "Digite uma poltrona" << endl;
        return;
    }

    if (matriz[fileira][poltrona] == 1)
    {
        cout << "Este lugar está ocupado. Por favor, selecione outro." << endl;
    }
    else
    {
        matriz[fileira][poltrona] = 1;
        cout << "Lugar reservado com sucesso!" << endl;
        qtdReservas++;

        if (fileira > 0 && fileira < 6)
        {
            faturamento += 50;
        }
        else if (fileira >= 6 && fileira < 11)
        {
            faturamento += 30;
        }
        else if (fileira >= 11 && fileira < 16)
        {
            faturamento += 15;
        }
    }
}

void mapear(int **matriz)
{
    for (int i = 0; i < fileiras; i++)
    {
        for (int j = 0; j < poltronas; j++)
        {
            if (matriz[i][j] == 0)
            {
                cout << ". | ";
            }
            else
            {
                cout << "# | ";
            }
        }
    }
}

int main(int argc, char **argv)
{
    int opcaoMenu = -1;
    int **matriz = new int *[fileiras];
    int faturamento = 0;
    int qtdReservas = 0;

    for (int i = 0; i < fileiras; i++)
    {
        matriz[i] = new int[poltronas];
    }

    for (int i = 0; i < fileiras; i++)
    {
        for (int j = 0; j < poltronas; j++)
        {
            matriz[i][j] = 0;
        }
    }

    do
    {
        cout << "----------------------------------" << endl;
        cout << "0. " << setw(5) << "Finalizar" << endl;
        cout << "1. " << setw(5) << "Reservar poltrona" << endl;
        cout << "2. " << setw(5) << "Mapa de ocupação" << endl;
        cout << "3. " << setw(5) << "Faturamento" << endl;
        cout << "----------------------------------" << endl;

        cout << "Digite uma opção válida do menu: " << endl;
        cin >> opcaoMenu;

        switch (opcaoMenu)
        {
        case 0:
            break;
        case 1:
            reservar(matriz, faturamento, qtdReservas);
            break;
        case 2:
            mapear(matriz);
            break;
        case 3:
            cout << "Qtde de lugares ocupados: " << qtdReservas << endl;
            cout << "Valor da bilheteria: R$ " << faturamento << endl;
            break;
        default:
            cout << "Opção invalida!" << endl;
            break;
        }

    } while (opcaoMenu != 0);

    delete[] matriz;

    return 0;
}