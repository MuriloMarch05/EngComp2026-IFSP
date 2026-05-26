/*5) Faça uma função que recebe um valor inteiro e verifica se o valor é positivo ou
negativo. A função deve retornar um valor string.*/

#include <iostream>
#include <iomanip>
using namespace std;

void posNeg(int num)
{
    string carater;
    
    if (num > 0)
    {
        carater = "Positivo";
    }
    else if(num < 0)
    {
        carater = "Negativo";
    }
    
    cout << "O número " << num << " é:" << carater;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    double numero;
    cout << "Digite um número: " << endl;
    cin >> numero;
    
    posNeg(numero);
    
    return 0;   
}