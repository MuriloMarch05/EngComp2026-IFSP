/*

Faça um programa em C++ que:

1.Crie duas variáveis inteiras
2.Crie dois ponteiros para inteiros.
3.Faça cada ponteiro apontar para uma das variáveis.
4.Usando somente os ponteiros, troque os valores de A e B.
5.Ao final, mostre os valores trocados.
*/


#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");

    int A, B, Aux;
    int *ptA, *ptB;

    A = 20;
    B = 10;

    cout << "Valores antes\n" << "A: " << A << "\nB: " << B << endl;

    ptA = &A;
    ptB = &B;

    Aux = *ptA;
    *ptA = *ptB;
    *ptB = Aux;

    cout << "Valores depois\n" << "A: " << A << "\nB: " << B << endl;

    return 0;
}