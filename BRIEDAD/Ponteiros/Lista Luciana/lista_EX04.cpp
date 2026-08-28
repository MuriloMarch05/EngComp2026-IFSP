/*

4 - Faça um programa que leia 2 valores inteiros e chame uma função que receba estas 2 variáveis
e troque o seu conteúdo, ou seja, esta função é chamada passando duas vaŕiaveis A e B por exemplo e,
após  a execução da função, A conterá o valor de B e B terá o valor de A.

*/

#include <iostream>
#include <clocale>
using namespace std;


void mudarValor(int *pA, int *pB){

    int aux = 0;

    aux = *pA;
    *pA = *pB;
    *pB = aux;

    cout << "Novo valor de A: " << *pA << "\nNovo valor de B: "<< *pB << endl;

}

int main(){
    setlocale(LC_ALL, "Portuguese");

    int A = 0, B = 0;

    int *ponteiroA;
    int *ponteiroB;

    ponteiroA = &A;
    ponteiroB = &B;

    cout << "Valor da varíavel A: ";
    cin >> A;

    cout << "Valor da variável B: ";
    cin >> B;

    mudarValor(ponteiroA, ponteiroB);

    return 0;
}