/*
Vamos tentar montar um código que usa qualquer um dos métodos de ordenação.

O usuário escolhe qual deseja utilizar.

*/

#include <iostream>
using namespace std;

// 1. Bubble Sort: Trocas sucessivas de vizinhos.
void bubbleSort(int *vet, int tamanho){

}

// 2. Busca o meior e coloca na posição correta.
void selectionSort(int *vet, int tamanho){

}

// 3. Insere o elemento na parte já ordenada.
void insertionSort(int *vet, int tamanho){

}

int preencherVetor(int *vet, int tamanho){

}

void mostrarVetor(int *vet, int tamanho){

}


void menu(){
    int op, tam = 5;
    int vet[14];

    do{

        cout << "MÉTODOS DE ORDENAÇÃO\n [1] - Preencher vetor\n[2] - Mostrar vetor original\n[3] - BubbleSort\n[4] - Selection Sort\n [5] - Insertion Sort\n[6] - Sair";
        cout << "\nOpção: ";
        cin >> op;

        switch (op){

            case 1: 
            preencherVetor();
            break;

            case 2:
            mostrarVetor();
            break;

            case 3:
            bubbleSort();
            break;

            case 4:
            selectionSort();
            break;

            case 5:
            insertionSort();
            break;

            case 6: break;

            default:
            cout << "Opção inválida." << endl;
        }

    }while(op!=6);
}


int main(){
    setlocale(LC_ALL, "Portuguese");

    menu();

    return 0;
}

/*
========================================================
RESUMO DOS MÉTODOS DE ORDENAÇÃO

SELECTION SORT
→ Procura o menor e coloca na posição correta.

BUBBLE SORT
→ Compara vizinhos e troca os que estão invertidos.
→ O maior vai "borbulhando" para o final.

INSERTION SORT
→ Pega um elemento e o insere na posição correta.
→ Desloca os elementos maiores para a direita.
========================================================
*/