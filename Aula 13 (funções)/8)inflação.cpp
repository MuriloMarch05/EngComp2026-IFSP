/*8) Fazer um programa que lê o preço de um produto e inflaciona esse preço em 10%
se ele for menor que 100 e em 20% se ele for maior ou igual a 100.*/

#include <iostream>
#include <iomanip> // Sempre que for utilizar casas decimais, inclua essa biblioteca.
using namespace std;

// Função que calcula o aumento

double inflacao(double preco) // Defini como double pois ele é mais exato do que o float.
{
    if (preco < 100) // Se o valor for menor que R$ 100:
    {
        preco = preco*1.1; // Ele calcula 10% de aumento.
    }

    else if (preco >= 100) // Se não, se o valor for maior ou igual a R$100:
    {
        preco = preco*1.2; // Calcula 20% de aumento.
    }

    return preco; // Não foi especificado no exercício se deveria haver retorno, então poderia ser feito das duas formas.
}

// Função principal

int main()
{
    setlocale(LC_ALL, "Portuguese");
    cout << fixed << setprecision(2);
    double preco;

    cout << "Qual é o preço do produto? R$ ";
    cin >> preco;

    cout << "O preço final com a inflação será de: R$ " << inflacao(preco);

    return 0;
}