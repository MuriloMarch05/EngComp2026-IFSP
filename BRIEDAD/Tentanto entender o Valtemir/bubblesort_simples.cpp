/*
===============
  Bubble Sort
===============

- Método mais simples, porém, o menos eficiente para muitos dados.

Lógica:
- O algoritmo percorre o vetor *várias vezes*, comparando elementos vizinhos. Se o primeiro for maior que o segundo, eles trocam de lugar.
- Esse processo faz com que o maior elemento "flutue" como uma bolha para o final do vetor a cada iteração.

Vantagem:
- Muito simples de entender e implementar.

Desvantagem:
- Ineficiente, pois exige muitas comparações e trocas.

Quando usar?
- Usamos apenas para fins didáticos ou quando temos poucos dados.

*/

#include <iostream>
using namespace std;


void bubbleSort(int *vet, int tamanho){

    int i, j, aux;
    // i = contador das passagens pelo vetor
    // j = percorre o vetor comparando elementos vizinhos
    // aux = variável auxiliar usada durante a troca

    for (i = 0; i < tamanho; i++){
        // A cada passagem, um dos maiores elementos
        // é colocado em sua posição correta no final do vetor.

        for (j = 0; j < tamanho - i - 1; j++){
            // Percorre a parte ainda desordenada do vetor,
            // comparando elementos adjacentes.
            // A cada passagem, o final do vetor já possui
            // elementos ordenados, por isso ele é ignorado.

            if (vet[j] > vet[j + 1]){
                // Se o elemento atual for maior que seu vizinho
                // à direita, os dois estão na ordem errada.

                aux = vet[j];
                // Guarda temporariamente o valor atual.

                vet[j] = vet[j + 1];
                // O elemento atual recebe o valor do vizinho.

                vet[j + 1] = aux;
                // O vizinho recebe o valor que estava originalmente
                // em vet[j], completando a troca.
            }
        }
    }
}

/*
Exemplo:

Vetor inicial:
[5, 2, 8, 1, 4]

Primeira passagem:

5 > 2 → troca:
[2, 5, 8, 1, 4]

5 > 8 → não troca:
[2, 5, 8, 1, 4]

8 > 1 → troca:
[2, 5, 1, 8, 4]

8 > 4 → troca:
[2, 5, 1, 4, 8]
             ↑
        maior elemento
        chegou ao final.

Segunda passagem:
[2, 5, 1, 4 | 8]
              ↑
          já está ordenado

O processo continua até todo o vetor
estar ordenado.
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

    bubbleSort(vet, tam);

    cout << "\n--------------------------------\n";
    cout << "BUBBLE SORT EXECUTADO...";
    cout << "\n--------------------------------\n";
    cout << "Vetor organizado: ";

    for (int i = 0; i<tam;i++){
        cout << vet[i] << " ";
    }

    cout << "\n--------------------------------\n";

    return 0;
}
