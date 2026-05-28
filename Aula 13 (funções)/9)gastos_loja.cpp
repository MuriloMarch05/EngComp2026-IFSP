/*9) Fazer um programa que solicita o total gasto pelo cliente de uma loja, imprime as
opções de pagamento, solicita a opção desejada e imprime o valor total das
prestações (se houverem).
A. Opção: a vista com 10% de desconto
B. Opção: em duas vezes (preço da etiqueta)
C. Opção: de 3 até 10 vezes com 3% de juros ao mês (somente para compras acima
de R$ 100,00).
OBS: fazer uma função que imprime as opções solicita a opção desejada e retorna a
opção escolhida. No programa principal, testar a opção escolhida e ativar a função
correspondente (uma função para cada opção).*/

#include <iostream>
#include <iomanip>
using namespace std;

// Função para o menu

char menu()
{
    setlocale(LC_ALL, "Portuguese");
    char opcao;

    cout << "Opções:\nA -> À vista\nB -> 2x sem juros\nC -> 3-10x com 3% de juros/m\n";
    cin >> opcao;
    opcao = toupper(opcao);
    return opcao;
}

// Função para a opção A

void opcaoA(double total)
{
    total = total*0.90;
    cout << "Preço final com desconto de 10% à vista: R$ " << total;
}

// Função para a opção B

void opcaoB(double total)
{
    cout << "Preço final de R$"<< total <<" sem desconto em 2x de R$ " << total/2; 
}

// Função para a opção C

void opcaoC(double total, int parcelas)
{  
    cout << "Quantas parcelas? (3-10x) ";
    cin >> parcelas;

    double juros;
    juros = total*parcelas*0.03;
    total = total + juros;

    cout << "Preço final de R$ " << total <<" parcelado em " << parcelas << "x de R$ " << total/parcelas << " com 3% de juros ao mês.";
}

// Função principal

int main()
{
    setlocale(LC_ALL, "Portuguese");
    double total;

    cout << "Digite o total gasto: R$ ";
    cin >> total;

    char escolha = menu();

    if (escolha == 'A')
    {
        opcaoA(total);
    }

    else if (escolha == 'B')
    {
        opcaoB(total);
    }

    else if (escolha == 'C')
    {
        if (total < 100)
        {
            cout << "Compras abaixo de R$100 não podem ser parceladas!";
        }

        else
        {
            opcaoC(total, 0);
        }
    }

    return 0;
}