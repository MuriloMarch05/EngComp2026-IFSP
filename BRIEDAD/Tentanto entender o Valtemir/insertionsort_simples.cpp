/*
==============
Insertion Sort
==============

- Selecionar um elemento por vez e inseri-lo em sua posição correta dentro de uma sublista já ordenada.

Lógica:
- Funciona de forma semelhante a alguém organizando cartas na mão.
- O algoritmo pega um elemento da parte desordenada e o compara com os elementos da parte ordenada (à esquerda), 
"empurrando" os maiores para frente até abrir espaço para inserir o novo elemento na posição exata.

Vantagem:
- Muito eficiente para vetores que já estão quase ordenados ou para conjuntos de dados pequenos. Método estável.

Desvantagem:
- Desempenho cai drasticamente à medida que o número de elementos aumenta e eles estão em ordem aleatória.

Quando usar?
- Para dados incrementais (um por um), visando mantê-los ordenados. Ou quando o vetor já está quase pronto.

*/

#include <iostream>
using namespace std;


void insertionSort(int *vet, int tamanho){

    int i, j, elemento;
    // i = índice do elemento que será inserido na parte ordenada
    // j = percorre a parte ordenada da direita para a esquerda
    // elemento = valor que será inserido na posição correta

    for(i = 1; i < tamanho; i++){
        // Considera o primeiro elemento (índice 0) como já ordenado.
        // A cada repetição, um novo elemento é retirado da parte
        // desordenada e inserido na posição correta da parte ordenada.

        elemento = vet[i];
        // Guarda o elemento que será inserido.
        // Ele precisa ser armazenado porque os elementos maiores
        // poderão ser deslocados para a direita.

        for(j = i - 1; j >= 0 && elemento < vet[j]; j--){
            // Percorre a parte ordenada da direita para a esquerda.
            // Enquanto encontrar elementos maiores que "elemento",
            // desloca esses elementos uma posição para a direita.

            vet[j + 1] = vet[j];
            // Desloca o elemento maior uma posição para a direita,
            // abrindo espaço para "elemento".
        }

        vet[j + 1] = elemento;
        // Insere "elemento" na posição correta.
        // Quando o for termina, j está uma posição antes
        // do local onde o elemento deve ser inserido.
    }

}

/*
Exemplo:

Vetor inicial:
[2, 5, 8, 3, 7]
 ↑        ↑
ordenado  elemento

elemento = 3

Compara 3 com 8:
3 < 8 → desloca o 8 para a direita

[2, 5, 8, 8, 7]

Compara 3 com 5:
3 < 5 → desloca o 5 para a direita

[2, 5, 5, 8, 7]

Compara 3 com 2:
3 > 2 → para.

Insere o 3 no espaço que ficou:

[2, 3, 5, 8, 7]
    ↑
   inserido

Agora temos:
[2, 3, 5, 8 | 7]
       ordenado

O processo continua com o 7.
*/

int main(){
    setlocale(LC_ALL, "Portuguese");
    int tam = 0;

    cout << "Qual o tamanho do vetor?: ";
    cin >> tam;

    int vet[tam];

    for (int i = 0; i<tam; i++){
        cout << "Preencha o vetor[" << i <<"]: ";
        cin >> vet[i];
    }

    cout << "\n--------------------------------\n";
    cout << "Vetor não organizado: ";

    for(int i = 0; i<tam; i++){
        cout << vet[i] << " ";
    }

    insertionSort(vet, tam);

    cout << "\n--------------------------------\n";
    cout << "SELECTION SORT EXECUTADO...";
    cout << "\n--------------------------------\n";
    cout << "Vetor organizado: ";

    for (int i = 0; i<tam;i++){
        cout << vet[i] << " ";
    }

    cout << "\n--------------------------------\n";

    return 0;
}