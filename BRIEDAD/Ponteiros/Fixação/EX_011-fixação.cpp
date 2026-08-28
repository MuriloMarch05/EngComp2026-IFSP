/*

11. Desenvolva um programa em C++ que declare três variáveis do tipo inteiro e três do tipo ponteiro de inteiro apontando para essas variáveis. 
Utilizando ponteiros, leia três números e os imprima em ordem crescente. O programa deve apresentar também o endereço de memória desses números.

*/
#include <iostream>
#include <clocale>
using namespace std;

void ordenar(int *pint1, int *pint2, int *pint3){

    int aux=0;

    if (*pint1 > *pint2){
        aux = *pint1;
        *pint1 = *pint2;
        *pint2 = aux;
    }

    if (*pint1 > *pint3){
        aux = *pint1;
        *pint1 = *pint3;
        *pint3 = aux;
    }

    if (*pint2 > *pint3){
        aux = *pint2;
        *pint2 = *pint3;
        *pint3 = aux;
    }
    
}

void imprimir(int *pint1, int *pint2, int *pint3){

    cout << "=== NÚMEROS EM ORDEM CRESCENTE ===" << endl;
    cout << "[1]: "<< *pint1 << " -> Endereço de memória: "<< pint1 << endl;
    cout << "[2]: "<< *pint2 << " -> Endereço de memória: "<< pint2 << endl;
    cout << "[3]: "<< *pint3 << " -> Endereço de memória: "<< pint3 << endl;
}

int main(){

    setlocale(LC_ALL, "Portuguese");

    //Variáveis
    int int1=0, int2=0, int3=0;
    // Ponteiros
    int *pint1, *pint2, *pint3;
    // Ponteiros recebem endereços
    pint1 = &int1;
    pint2 = &int2;
    pint3 = &int3;

    // Cadastro
    cout << "=== CADASTRE 3 NÚMEROS INTEIROS === " << endl;

        cout << "Número[1]: ";
        cin >> int1;

        cout << "Número[2]: ";
        cin >> int2;

        cout << "Número[3]: ";
        cin >> int3;

    ordenar(pint1, pint2, pint3); // Organiza em ordem crescente. 
    imprimir(pint1, pint2, pint3); // Imprime já ordenado.

    return 0;
}
