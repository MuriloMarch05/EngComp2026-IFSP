/*

2- Escreva um programa que contenha duas variáveis inteiras. Compare seus endereços e exiba o maior endereço.

*/

#include <iostream>
using namespace std;

void maiorEndereco(int *p_int1, int *p_int2){
    
    cout << "------------------------------\n";
    cout << "Endereço do primeiro inteiro: " << p_int1 << endl;
    cout << "------------------------------\n";
    cout << "Endereço do segundo inteiro: " << p_int2 << endl;
    cout << "------------------------------\n";

    if (p_int1 > p_int2){
        cout << "O endereço do primeiro inteiro["<< *p_int1 << "]é maior." << endl;
    }
    else if (p_int1 < p_int2){
        cout << "O endereço do segundo inteiro ["<< *p_int2 << "]é maior. " << endl;
    }
    else{
        cout << "Os endereços de [" <<  *p_int1 << "] e [" << *p_int2 << "], são iguais." << endl; 
    }

}

int main(){

    int inteiro1, inteiro2;

    int *p_int1;
    int *p_int2;

    p_int1 = &inteiro1;
    p_int2 = &inteiro2;

    cout << "Digite um número inteiro: ";
    cin >> inteiro1;

    cout << "Digite outro número inteiro: ";
    cin >> inteiro2;

    maiorEndereco(p_int1, p_int2);

    return 0;

}