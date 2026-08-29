/* 

13- Desenvolva um programa em C++ que leia seis números e armazene-os em um vetor.
Esse programa deve conter ponteiros para manusear o vetor e imprimir os seus valores.
O programa deve apresentar também o endereço de memória desses números.

*/
#include <iostream>
#include <clocale>
using namespace std;

void imprimirVetor(int *p_vet){

    for(int i = 0;i<6;i++){
        cout << "Elemento["<<i<<"]: " << *p_vet << " -> Endereço: " << p_vet << endl;
        p_vet++;
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    int vetor[6];
    int *p_vet;

    cout << "Digite seis números inteiros: " << endl;

    for(int i = 0;i<6;i++){
        cout << "Número["<< i << "]: ";
        cin >> vetor[i];
    }

    p_vet = &vetor[0];

    cout << "------------------------------------------\n";
    imprimirVetor(p_vet);

    return 0;
}
