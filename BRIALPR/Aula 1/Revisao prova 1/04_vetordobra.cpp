/*Desenvolver um programa que utilize a estrutura de dados vetor (array) para armazenar uma sequência numérica baseada em uma progressão geométrica simples.
Descrição:O programa deve ler um valor inteiro inicial V.Este valor V deve ser armazenado na primeira posição (índice 0) de um vetor N de 10 posições.
Cada uma das posições subsequentes do vetor (N[1] até N[9]) deve receber o dobro do valor armazenado na posição imediatamente anterior.
Ao final, o programa deve exibir todos os elementos do vetor, indicando o índice e o valor correspondente.*/

#include <iostream>
using namespace std;

int main() {
    int N[10];
    int valorInicial;

    cout << "Digite o valor inicial: ";
    cin >> valorInicial;

    // 1. Atribuir o valor lido à primeira posição
    N[0] = valorInicial;

    // 2. Preencher o restante do vetor
    // Começamos o loop do 1, pois a posição 0 já foi preenchida
    for (int i = 1; i < 10; i++) {
        N[i] = N[i - 1] * 2; // O valor atual é o anterior vezes 2
    }

    // 3. Mostrar o resultado
    for (int i = 0; i < 10; i++) {
        cout << "N[" << i << "] = " << N[i] << endl;
    }

    return 0;
}