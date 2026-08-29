/*

12- Faça um programa em C++ que receba uma frase qualquer fornecida pelo usuário,
que calcule e mostre quantos caracteres essa frase possui. Esse programa deve conter
ponteiros para manusear a string. A frase deve possuir no máximo 50 caracteres.

*/

#include <iostream>
#include <clocale>
using namespace std;

int verificarFrase(char *p_frase, int op){

    int caracteres=0;

    if (op==1){
        while(*p_frase != '\0'){
            caracteres++;
            p_frase++;
        }
    }
    else{
        while(*p_frase != '\0'){
            if (*p_frase != ' '){
                caracteres+=1;
            }
            p_frase++;
        }
    }

    return caracteres;
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    int op=0;
    string frase;
    char *p_frase;

    do{

        cout << "Digite uma frase: ";
        getline(cin, frase);

        cout << "Contar espaços?\n[1]-Sim\n[2]-Não\nOpção: ";
        cin >> op;
        cin.ignore();

        if(frase.size()>50){
            cout << "Frase muito longa (50+). Tente novamente.\n";
        }

    }while(frase.size() > 50);
    
    p_frase = &frase[0]; // O ponteiro recebe o endereço de memória do primeiro elemento da string frase.

    cout << "A frase possui " << verificarFrase(p_frase, op) << " caracteres." << endl;

    return 0;
}
