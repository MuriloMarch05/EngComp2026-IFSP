/*
===============
Selection Sort
===============

- Foca em encontrar o menor elemento e colocá-lo na posição correta.

Lógica:
- O vetor é dividido imaginariamente em uma parte ordenada e outra desordenada. 
- O algoritmo busca o menor valor em toda a parte desordenada e o troca com o elemento que está no início dessa parte.
- Assim, a cada passo, um novo elemento é adicionado à parte ordenada.

Vantagem:
- Realiza o número mínimo de trocas.

Desvantagem:
- Pode ser instável (não preserva a ordem original de elementos com valores iguais).

Quando usar?
- Quando o custo de mover itens na memória é alto, mas o cursto de compará-los é baixo.

*/

#include <iostream>
using namespace std;


void selectionSort(int *vet, int tamanho){
    int i, j, min, localTroca, trocou;
    // i = início da parte desordenada
    // j = percorre a parte desordenada procurando o menor valor
    // min = menor valor encontrado
    // localTroca = índice onde está o menor valor encontrado
    // trocou = indica se foi encontrada uma posição diferente de i para troca

    for (i = 0; i < tamanho - 1; i++){
        // Tudo à esquerda de i já está ordenado.
        // A partir de i começa a parte ainda desordenada.

        min = vet[i];
        // Inicialmente, considera o próprio elemento de i como o menor.

        localTroca = i;
        // Guarda o índice do menor valor encontrado.
        // Inicialmente, o menor está em i.

        trocou = 0;
        // Ainda não foi encontrada nenhuma posição diferente de i
        // contendo um valor menor.

        for (j = i + 1; j < tamanho; j++){
            // Percorre o restante da parte desordenada,
            // procurando um valor menor que min.

            if (vet[j] < min){
                // Encontrou um valor menor que o menor atual.

                min = vet[j];
                // Atualiza o menor valor encontrado.

                localTroca = j;
                // Guarda a posição onde está esse novo menor valor.

                trocou = 1;
                // Indica que foi encontrado um elemento menor
                // e, portanto, haverá uma troca.
            }
        }

        if (trocou){
            // Se foi encontrado um elemento menor que vet[i],
            // coloca esse menor elemento na posição i.

            vet[localTroca] = vet[i];
            // O valor que estava em i vai para a posição
            // onde estava o menor elemento.

            vet[i] = min;
            // O menor elemento encontrado vai para a posição i.
        }
    }
}

/*
Exemplo:

Vetor inicial:
[7, 3, 5, 2, 9]
 ↑
 i

Procura o menor elemento:
[7, 3, 5, 2, 9]
          ↑
        menor = 2

Troca o 7 pelo 2:
[2, 3, 5, 7, 9]
 ↑
 i

Agora o 2 está na posição correta.
A parte à esquerda de i está ordenada.

Próxima passagem:
[2 | 3, 5, 7, 9]
     ↑
     i

E o processo se repete.
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

    selectionSort(vet, tam);

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