/*3) Elabore um programa que calcula o maior de dois números dados. O cálculo do
maior número será feito utilizando-se uma função com parâmetros e retornará o
maior valor.*/

#include <iostream>
#include <iomanip>
using namespace std;

double maiorNum(double n1, double n2)
{
    double maior;
    
    if (n1>n2)
    {
        maior = n1;
    }
    else if(n1<n2)
    {
        maior = n2;
    }
    
    return maior;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    double num1, num2;
    cout << "Digite dois números: " << endl;
    cin >> num1 >> num2;

    cout << "O maior número é "<< maiorNum(num1, num2);
    
    return 0;   
}