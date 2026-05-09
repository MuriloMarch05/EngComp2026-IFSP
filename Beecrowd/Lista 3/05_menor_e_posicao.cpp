/*Faça um programa que leia um valor N. Este N será o tamanho de um vetor X[N]. 
A seguir, leia cada um dos valores de X, encontre o menor elemento deste vetor e a sua posição dentro do vetor, 
mostrando esta informação.*/

#include <iostream>
using namespace std;

int main()
{
    int N, i, menor, posicao;

    cout << "Digite o tamanho do vetor: ";
    cin >> N;
    int X[N]; // Declaração do vetor com tamanho N. "Por que não declarou antes?" 
            //Pois não seria possível determinar o tamanho do vetor sem antes ler o valor de N.

    for(i=0;i<N;i++)
    {
        cout << "Digite o valor do vetor: ";
        cin >> X[i];

        if(i == 0) // Inicializa o menor valor com o primeiro elemento do vetor.
        {
            menor = X[i];
        }
        else if (X[i] < menor) // Se o valor atual for menor que o menor valor, atualiza o menor valor e a posição.
        {
            menor = X[i];
            posicao = i; // Armazena o índice do menor valor.
        }
    }

    cout << "Menor valor: " << menor << endl;
    cout << "Posição do menor valor: " << posicao << endl;

    return 0;
}
