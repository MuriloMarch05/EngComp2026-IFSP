/*Exercício 7:** Crie um programa usando `switch-case` que receba um número de 1 a 4 e informe a estação do ano correspondente (1-Verão, 2-Outono, etc.). 
Inclua uma mensagem de erro para valores inválidos.*/

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese"); // Configura para exibir acentos corretamente
    int estacao;

    cout << "Digite um número de 1 a 4 para informar a estação do ano correspondente:\n";
    cout << "1 - Verão\n2 - Outono\n3 - Inverno\n4 - Primavera\n";
    cin >> estacao;

    switch(estacao)
    {
        case 1:
            cout << "Você escolheu Verão." << endl; break;
        case 2:
            cout << "Você escolheu Outono." << endl; break;
        case 3:
            cout << "Você escolheu Inverno." << endl; break;
        case 4:
            cout << "Você escolheu Primavera." << endl; break;
        default:
            cout << "Valor inválido." << endl;
    }
    return 0;
}