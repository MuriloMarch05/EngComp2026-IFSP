/*Escreva um algoritmo que leia um inteiro N (0 ≤ N ≤ 100), correspondente a ordem de uma matriz M de inteiros, e construa a matriz de acordo com o exemplo abaixo.

Entrada
A entrada consiste de vários inteiros, um valor por linha, correspondentes as ordens das matrizes a serem construídas. 
O final da entrada é marcado por um valor de ordem igual a zero (0).

Saída
Para cada inteiro da entrada imprima a matriz correspondente, de acordo com o exemplo. 
Os valores das matrizes devem ser formatados em um campo de tamanho 3 justificados à direita e separados por espaço. 
Após o último caractere de cada linha da matriz não deve haver espaços em branco. 
Após a impressão de cada matriz deve ser deixada uma linha em branco.*/

#include <iostream>
#include <iomanip> // Necessário para o setw()
#include <algorithm> // Necessário para a função min()

using namespace std;

int main() {
    int N;

    // O loop roda enquanto a entrada for diferente de 0
    while (cin >> N && N != 0) {
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                
                // A LÓGICA DA "CEBOLA":
                // Calculamos a distância de (i, j) para as 4 bordas:
                // Cima: i + 1
                // Esquerda: j + 1
                // Baixo: N - i
                // Direita: N - j
                
                int valor = i + 1; // Começa chutando que é a distância do topo
                
                if (j + 1 < valor) 
                {
                    valor = j + 1;
                }
                if (N - i < valor) 
                {
                    valor = N - i;
                }
                if (N - j < valor) 
                {
                    valor = N - j;
                }
                
                // FORMATAÇÃO:
                // O primeiro elemento da linha não tem espaço antes
                if (j == 0) {
                    cout << setw(3) << valor;
                } else {
                    // Os demais têm um espaço de separação
                    cout << " " << setw(3) << valor;
                }
            }
            cout << endl; // Quebra a linha ao fim de cada linha da matriz
        }
        cout << endl; // Quebra uma linha extra após a matriz inteira (exigência do problema)
    }

    return 0;
}