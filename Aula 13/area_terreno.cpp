/*7) A imobiliária Central vende apenas terrenos retangulares. Faça um algoritmo para
ler as dimensões de um terreno e depois exibir a área do terreno.*/

#include <iostream>
#include <iomanip>
using namespace std;

double calcula_area(double b, double h)
{
    double area;
    
    area = b*h;
    
    return area;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    double base, altura;
    
    cout << "Quais são as dimensões do terreno em metros? " << endl;
    cin >> base >> altura;
    
    cout << "A área do terreno é : " << calcula_area(base,altura)<< "m²"<< endl;

    
    return 0;   
}