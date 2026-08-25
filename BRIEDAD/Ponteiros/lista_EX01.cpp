/*

1- Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro,
real e char. Associe as variáveis aos ponteiros (use &). Modifique os valores de cada variável usando
os ponteiros. Imprima os valores das variáveis antes e após a modificação.

*/

#include <iostream>
#include <clocale>
using namespace std;

void modVar(int *p_inteiro, double *p_real, char *p_char){

    cout << "--------------------------" << endl;
    cout << "Alterando as variáveis..." << endl;
    cout << "--------------------------" << endl;

    *p_inteiro += 10;

    *p_real += 5;

    *p_char = 'P';

    cout << "Novos valores: " << endl;
    cout << "Inteiro: "<< *p_inteiro << endl;
    cout << "Real: "<< *p_real << endl;
    cout << "Char: " << *p_char << endl;

}

int main(){

    setlocale(LC_ALL, "Portuguese");

    // variaveis
    int inteiro;
    double real;
    char caracter;
    // Ponteiros das variaveis
    int *p_inteiro;
    double *p_real;
    char *p_char;

    // Associando valores das variaveis aos ponteiros
    p_inteiro = &inteiro;
    p_real = &real;
    p_char = &caracter;

    // Cadastro
    cout << "Digite um valor inteiro: ";
    cin >> inteiro;

    cout << "Digite um valor real: ";
    cin >> real;

    cout << "Digite um caractere: ";
    cin >> caracter;

    cout << "\nValores antes das modificações\n";
    cout << "---------------------------------\n";
    cout << "Inteiro: " << inteiro << endl;
    cout << "Real: " << real << endl;
    cout << "Caractere: " << caracter << endl;

    modVar(p_inteiro, p_real, p_char);

    return 0;
}
