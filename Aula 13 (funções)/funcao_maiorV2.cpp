/*4) Refaça o exercício anterior usando uma função que não retorna valor.*/

#include <iostream>
#include <iomanip>
using namespace std;

void maiorNum(double n1, double n2)
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
    
    cout << "O maior número é " << maior << endl;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    double num1, num2;
    cout << "Digite dois números: " << endl;
    cin >> num1 >> num2;
    
    maiorNum(num1, num2);
    
    return 0;   
}