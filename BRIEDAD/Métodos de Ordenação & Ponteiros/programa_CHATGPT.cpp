/*
========================================================
PROGRAMA DE ESTUDO - MÉTODOS DE ORDENAÇÃO

O usuário pode:

1. Criar/preencher um vetor com tamanho escolhido.
2. Visualizar o vetor original.
3. Ordenar usando Bubble Sort.
4. Ordenar usando Selection Sort.
5. Ordenar usando Insertion Sort.
6. Comparar o tempo dos três métodos.
7. Receber uma recomendação de método.
8. Criar outro vetor e repetir os testes.

Os três métodos utilizados são:

- Bubble Sort
- Selection Sort
- Insertion Sort
========================================================
*/

#include <iostream>
#include <chrono>
#include <iomanip>
#include <clocale>

using namespace std;


// ========================================================
// 1. BUBBLE SORT
// ========================================================

void bubbleSort(int *vet, int tamanho){

    int i, j, aux;

    for (i = 0; i < tamanho; i++){

        for (j = 0; j < tamanho - i - 1; j++){

            if (vet[j] > vet[j + 1]){

                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
        }
    }
}


// ========================================================
// 2. SELECTION SORT
// ========================================================

void selectionSort(int *vet, int tamanho){

    int i, j, min, localTroca, trocou;

    for (i = 0; i < tamanho - 1; i++){

        min = vet[i];
        localTroca = i;
        trocou = 0;

        for (j = i + 1; j < tamanho; j++){

            if (vet[j] < min){

                min = vet[j];
                localTroca = j;
                trocou = 1;
            }
        }

        if (trocou){

            vet[localTroca] = vet[i];
            vet[i] = min;
        }
    }
}


// ========================================================
// 3. INSERTION SORT
// ========================================================

void insertionSort(int *vet, int tamanho){

    int i, j, elemento;

    for (i = 1; i < tamanho; i++){

        elemento = vet[i];

        for (j = i - 1; j >= 0 && elemento < vet[j]; j--){

            vet[j + 1] = vet[j];
        }

        vet[j + 1] = elemento;
    }
}


// ========================================================
// PREENCHER VETOR
// ========================================================

void preencherVetor(int *vet, int tamanho){

    cout << "\nDigite os " << tamanho << " elementos:\n";

    for (int i = 0; i < tamanho; i++){

        cout << "Elemento [" << i << "]: ";
        cin >> vet[i];
    }
}


// ========================================================
// MOSTRAR VETOR
// ========================================================

void mostrarVetor(int *vet, int tamanho){

    cout << "[";

    for (int i = 0; i < tamanho; i++){

        cout << vet[i];

        if (i < tamanho - 1){
            cout << ", ";
        }
    }

    cout << "]\n";
}


// ========================================================
// COPIAR VETOR
// ========================================================

void copiarVetor(int *origem, int *destino, int tamanho){

    for (int i = 0; i < tamanho; i++){

        destino[i] = origem[i];
    }
}


// ========================================================
// RECOMENDAÇÃO
// ========================================================

void recomendarMetodo(int tamanho){

    cout << "\nRECOMENDACAO PARA " << tamanho << " ELEMENTOS:\n";

    if (tamanho <= 20){

        cout << "-> Insertion Sort\n";
        cout << "   Bom para vetores pequenos e simples.\n";
    }

    else if (tamanho <= 1000){

        cout << "-> Insertion Sort ou Selection Sort\n";
        cout << "   Para esse tamanho, os tres ainda sao viaveis,\n";
        cout << "   mas o Insertion Sort costuma ser uma boa escolha.\n";
    }

    else{

        cout << "-> Entre os tres estudados, Insertion Sort\n";
        cout << "   tende a ser uma escolha mais interessante.\n";
        cout << "   Porem, para grandes quantidades de dados,\n";
        cout << "   o ideal seria utilizar algoritmos mais eficientes,\n";
        cout << "   como Quick Sort ou Merge Sort.\n";
    }

    cout << "\nOBS: Os tres algoritmos possuem complexidade O(n²)\n";
    cout << "no pior caso. Portanto, nenhum deles e realmente\n";
    cout << "ideal para vetores muito grandes.\n";
}


// ========================================================
// TESTAR UM MÉTODO E MEDIR O TEMPO
// ========================================================

long long testarBubbleSort(int *vet, int tamanho){

    auto inicio = chrono::high_resolution_clock::now();

    bubbleSort(vet, tamanho);

    auto fim = chrono::high_resolution_clock::now();

    return chrono::duration_cast<chrono::nanoseconds>
           (fim - inicio).count();
}


long long testarSelectionSort(int *vet, int tamanho){

    auto inicio = chrono::high_resolution_clock::now();

    selectionSort(vet, tamanho);

    auto fim = chrono::high_resolution_clock::now();

    return chrono::duration_cast<chrono::nanoseconds>
           (fim - inicio).count();
}


long long testarInsertionSort(int *vet, int tamanho){

    auto inicio = chrono::high_resolution_clock::now();

    insertionSort(vet, tamanho);

    auto fim = chrono::high_resolution_clock::now();

    return chrono::duration_cast<chrono::nanoseconds>
           (fim - inicio).count();
}


// ========================================================
// COMPARAR OS TRÊS MÉTODOS
// ========================================================

void compararMetodos(int *original, int tamanho){

    // Cria três cópias do vetor original.
    int *vetBubble = new int[tamanho];
    int *vetSelection = new int[tamanho];
    int *vetInsertion = new int[tamanho];

    copiarVetor(original, vetBubble, tamanho);
    copiarVetor(original, vetSelection, tamanho);
    copiarVetor(original, vetInsertion, tamanho);


    // Mede o tempo de cada método.

    long long tempoBubble =
        testarBubbleSort(vetBubble, tamanho);

    long long tempoSelection =
        testarSelectionSort(vetSelection, tamanho);

    long long tempoInsertion =
        testarInsertionSort(vetInsertion, tamanho);


    // Mostra os resultados.

    cout << "\n============================================\n";
    cout << "COMPARACAO DOS METODOS\n";
    cout << "============================================\n";

    cout << fixed << setprecision(3);

    cout << "Bubble Sort:    "
         << tempoBubble / 1000000.0
         << " ms\n";

    cout << "Selection Sort: "
         << tempoSelection / 1000000.0
         << " ms\n";

    cout << "Insertion Sort: "
         << tempoInsertion / 1000000.0
         << " ms\n";


    // Descobre o mais rápido.

    cout << "\nMais rapido neste teste: ";

    if (tempoBubble <= tempoSelection &&
        tempoBubble <= tempoInsertion){

        cout << "Bubble Sort\n";
    }

    else if (tempoSelection <= tempoBubble &&
             tempoSelection <= tempoInsertion){

        cout << "Selection Sort\n";
    }

    else{

        cout << "Insertion Sort\n";
    }


    // Libera a memória.

    delete[] vetBubble;
    delete[] vetSelection;
    delete[] vetInsertion;
}


// ========================================================
// MENU
// ========================================================

void menu(){

    int op;
    int *vet = nullptr;
    int tamanho = 0;


    do{

        cout << "\n\n============================================\n";
        cout << "       METODOS DE ORDENACAO\n";
        cout << "============================================\n";

        cout << "[1] - Criar/preencher vetor\n";
        cout << "[2] - Mostrar vetor original\n";
        cout << "[3] - Bubble Sort\n";
        cout << "[4] - Selection Sort\n";
        cout << "[5] - Insertion Sort\n";
        cout << "[6] - Comparar os tres metodos\n";
        cout << "[7] - Receber recomendacao\n";
        cout << "[8] - Sair\n";

        cout << "\nOpcao: ";
        cin >> op;


        switch (op){

            case 1:

                // Se já existir um vetor, libera a memória.
                if (vet != nullptr){

                    delete[] vet;
                }

                cout << "\nDigite o tamanho do vetor: ";
                cin >> tamanho;

                if (tamanho <= 0){

                    cout << "Tamanho invalido.\n";
                    vet = nullptr;
                    tamanho = 0;
                    break;
                }

                // Cria um vetor com o tamanho escolhido.
                vet = new int[tamanho];

                preencherVetor(vet, tamanho);

                cout << "\nVetor criado com sucesso!\n";

                break;


            case 2:

                if (vet == nullptr){

                    cout << "\nNenhum vetor foi criado.\n";
                }

                else{

                    cout << "\nVetor original:\n";
                    mostrarVetor(vet, tamanho);
                }

                break;


            case 3:

                if (vet == nullptr){

                    cout << "\nNenhum vetor foi criado.\n";
                }

                else{

                    int *copia = new int[tamanho];

                    copiarVetor(vet, copia, tamanho);

                    cout << "\nAntes:\n";
                    mostrarVetor(copia, tamanho);

                    long long tempo = testarBubbleSort(copia, tamanho);

                    cout << "\nDepois:\n";
                    mostrarVetor(copia, tamanho);

                    cout << "\nTempo: "
                         << tempo / 1000000.0
                         << " ms\n";

                    delete[] copia;
                }

                break;


            case 4:

                if (vet == nullptr){

                    cout << "\nNenhum vetor foi criado.\n";
                }

                else{

                    int *copia = new int[tamanho];

                    copiarVetor(vet, copia, tamanho);

                    cout << "\nAntes:\n";
                    mostrarVetor(copia, tamanho);

                    long long tempo =
                        testarSelectionSort(copia, tamanho);

                    cout << "\nDepois:\n";
                    mostrarVetor(copia, tamanho);

                    cout << "\nTempo: "
                         << tempo / 1000000.0
                         << " ms\n";

                    delete[] copia;
                }

                break;


            case 5:

                if (vet == nullptr){

                    cout << "\nNenhum vetor foi criado.\n";
                }

                else{

                    int *copia = new int[tamanho];

                    copiarVetor(vet, copia, tamanho);

                    cout << "\nAntes:\n";
                    mostrarVetor(copia, tamanho);

                    long long tempo =
                        testarInsertionSort(copia, tamanho);

                    cout << "\nDepois:\n";
                    mostrarVetor(copia, tamanho);

                    cout << "\nTempo: "
                         << tempo / 1000000.0
                         << " ms\n";

                    delete[] copia;
                }

                break;


            case 6:

                if (vet == nullptr){

                    cout << "\nNenhum vetor foi criado.\n";
                }

                else{

                    compararMetodos(vet, tamanho);
                }

                break;


            case 7:

                if (vet == nullptr){

                    cout << "\nNenhum vetor foi criado.\n";
                }

                else{

                    recomendarMetodo(tamanho);
                }

                break;


            case 8:

                cout << "\nEncerrando programa...\n";

                break;


            default:

                cout << "\nOpcao invalida.\n";
        }


    } while (op != 8);


    // Libera o vetor principal antes de encerrar.
    if (vet != nullptr){

        delete[] vet;
    }
}


// ========================================================
// MAIN
// ========================================================

int main(){

    setlocale(LC_ALL, "Portuguese");

    menu();

    return 0;
}