/*Bubble Sort*/

#include <iostream>
using namespace std;


void bubbleSort(int *vet, int tamanho){
    int i, j, aux;
    for (i = 0; i<tamanho; i++){
        for(j=0;j<tamanho-i-1;j++){
            if(vet[j]>vet[j+1]){
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    int vet[5], tam = 5;

    
    for (int i = 0; i<5; i++){
        cout << "Preencha o vetor[" << i <<"]: ";
        cin >> vet[i];
    }

    cout << "\n--------------------------------\n";
    cout << "Vetor não organizado: ";

    for(int i = 0; i<5; i++){
        cout << vet[i] << " ";
    }

    bubbleSort(vet, tam);
    
    cout << "\n--------------------------------\n";
    cout << "Vetor organizado: ";

    for (int i = 0; i<5;i++){
        cout << vet[i] << " ";
    }

    cout << "\n--------------------------------\n";

    return 0;
}




