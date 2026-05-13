/*2) Faça um programa que ajude o DETRAN a saber o total de recursos que serão
arrecadados com a aplicação de multas de trânsito. O programa deve ler as seguintes
informações para cada motorista:
 O número da carteira de motorista (de 1 a 4327)
 O número de multas
 O valor de cada uma das multas
Deve ser impresso o valor da dívida para cada motorista e, ao final da leitura, o total de
recursos arrecadados (somatório de todas as multas). O programa deverá imprimir
também o número da carteira do motorista que obteve o maior número de multas. O
programa termina ao ler a carteira de motorista de valor 0.*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << fixed << setprecision(2);
    int carteira, qtdMultas, maiorQtd = -1, carteiraMaior;
    double valorMulta, somaMotorista, totalArrecadado = 0.0;

    while (carteira != 0)
    {
        somaMotorista = 0.0; // Reinicia a soma para cada motorista
        cout << "Digite o número da carteira (1 a 4327, ou 0 para encerrar): ";
        cin >> carteira;

        if(carteira == 0)
        {
            break;
        }

        cout << "Quantas multas? ";
        cin >> qtdMultas;

        if (qtdMultas > maiorQtd)
        {
            maiorQtd = qtdMultas;
            carteiraMaior = carteira;
        }

        for (int i = 0; i<qtdMultas; i++)
        {
            cout << "Valor da multa " << (i + 1) << ": R$ ";
            cin >> valorMulta;
            somaMotorista += valorMulta; // Acumula o valor das multas para o motorista atual
        }

        totalArrecadado += somaMotorista; // Acumula o valor total arrecadado
        cout << "Dívida do motorista " << carteira << ": R$ " << somaMotorista << endl;        
    }

        cout << "Total arrecadado com multas: R$ " << totalArrecadado << endl;
        cout << "Motorista com maior número de multas: " << carteiraMaior << endl;

    return 0;
}