/*Elabore um programa que utilize `do-while` para garantir que o usuário digite um número estritamente negativo antes de encerrar.*/

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int vetor[10];
    int i = 0;

    cout << "Preencha o vetor com 10 números(negativos param o programa): " << endl;

    do
    {
        cin >> vetor[i];
        i++;

    } while (vetor[i-1] >= 0 && i < 10); // Continua enquanto o número for não-negativo e o vetor não estiver cheio
    
    cout << "Você digitou " << i-1 << " números." << endl; // i-1 porque o último número é o negativo que parou o programa
    
    if (i-1 != 0)
    {
        cout << "O vetor digitado foi: " << endl;
    }

    for(int j = 0; j < i-1; j++) // Exibe apenas os números válidos, usamos j para não confundir com o i do do-while
    {
        cout << vetor[j] << " ";
    }
    cout << endl;

    return 0;
}