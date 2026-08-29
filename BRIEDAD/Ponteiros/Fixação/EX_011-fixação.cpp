/*

11. Desenvolva um programa em C++ que declare três variáveis do tipo inteiro e três do tipo ponteiro de inteiro apontando para essas variáveis. 
Utilizando ponteiros, leia três números e os imprima em ordem crescente. O programa deve apresentar também o endereço de memória desses números.

*/
#include <iostream>
#include <clocale>
using namespace std;

void ordenar(int *p_int1, int *p_int2, int *p_int3){

    int aux=0;

    if (*p_int1 > *p_int2){
        aux = *p_int1;
        *p_int1 = *p_int2;
        *p_int2 = aux;
    }

    if (*p_int1 > *p_int3){
        aux = *p_int1;
        *p_int1 = *p_int3;
        *p_int3 = aux;
    }

    if (*p_int2 > *p_int3){
        aux = *p_int2;
        *p_int2 = *p_int3;
        *p_int3 = aux;
    }
    
}

void imprimir(int *p_int1, int *p_int2, int *p_int3){

    cout << "=== NÚMEROS EM ORDEM CRESCENTE ===" << endl;
    cout << "[1]: "<< *p_int1 << " -> Endereço de memória: "<< p_int1 << endl;
    cout << "[2]: "<< *p_int2 << " -> Endereço de memória: "<< p_int2 << endl;
    cout << "[3]: "<< *p_int3 << " -> Endereço de memória: "<< p_int3 << endl;
}

int main(){

    setlocale(LC_ALL, "Portuguese");

    //Variáveis
    int int1=0, int2=0, int3=0;
    // Ponteiros
    int *p_int1, *p_int2, *p_int3;
    // Ponteiros recebem endereços
    p_int1 = &int1;
    p_int2 = &int2;
    p_int3 = &int3;

    // Cadastro
    cout << "=== CADASTRE 3 NÚMEROS INTEIROS === " << endl;

        cout << "Número[1]: ";
        cin >> int1;

        cout << "Número[2]: ";
        cin >> int2;

        cout << "Número[3]: ";
        cin >> int3;

    ordenar(p_int1, p_int2, p_int3); // Organiza em ordem crescente. 
    imprimir(p_int1, p_int2, p_int3); // Imprime já ordenado.

    return 0;
}
