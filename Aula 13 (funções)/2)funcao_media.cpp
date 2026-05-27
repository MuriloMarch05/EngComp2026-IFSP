/*2) Faça uma função que receba 4 notas e retorne a média.*/

#include <iostream>
#include <iomanip>
using namespace std;

double calcula_media(double n1, double n2, double n3, double n4)
{
    double media;
    media = (n1+n2+n3+n4)/4;
    return media;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    double nota1,nota2,nota3,nota4;
    cout << "Digite as quatro notas para ver a média: " << endl;
    cin >> nota1>>nota2>>nota3>>nota4;

    cout << "A média final é "<< calcula_media(nota1,nota2,nota3,nota4);
    
    return 0;   
}