/*Faça um programa que carregue um vetor de 10 elementos inteiros e calcule: o maior elemento e a posição em que ele se encontra.*/

#include <iostream>
using namespace std;

int main()
{
    int vetor[10];
    int i, maior, posicao;
    
    cout << "Digite 10 números inteiros para preencher o vetor: ";
    for (i=0; i<10; i++)
    {
        cin >> vetor[i];
        
        if (i == 0) // Para o primeiro elemento, inicializamos o maior e a posição
        {
            maior = vetor[i];
            posicao = i;
        }
        else if (vetor[i] > maior) // Se o elemento atual for maior que o maior encontrado até agora, atualizamos o maior e a posição
        {
            maior = vetor[i];
            posicao = i;
        }
    }
    
    cout << "Vetor digitado: [ ";
    for (i=0;i<10;i++)
    {
        cout << vetor[i] << " ";
    }

    cout << "]\nO maior elemento digitado foi: " << maior << endl;
    cout << "Posição do elemento: " << posicao << endl;

    return 0;
}