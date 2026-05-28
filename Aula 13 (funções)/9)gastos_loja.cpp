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
    opcao = toupper(opcao); // Converte a opção para maiúscula para facilitar a comparação posteriormente.

    return opcao; // Retorna a opção escolhida pelo usuário para ser utilizada no programa principal.
}

// Função para a opção A

void opcaoA(double total)
{
    total = total*0.90; // Calcula o valor com desconto de 10%
    cout << "Preço final com desconto de 10% à vista: R$ " << total;
}

// Função para a opção B

void opcaoB(double total)
{
    cout << "Preço final de R$"<< total <<" sem desconto em 2x de R$ " << total/2; // Apenas mostra o valor total e o valor de cada parcela.
}

// Função para a opção C

void opcaoC(double total, int parcelas) //  Nesse caso, precisamos passar o número de parcelas como parâmetro para a função.
{  
    cout << "Quantas parcelas? (3-10x) ";
    cin >> parcelas;

    double juros;
    juros = total*parcelas*0.03; // Calcula o valor total do juros, considerando o valor total, o número de parcelas e a taxa.
    total = total + juros;

    cout << "Preço final de R$ " << total <<" parcelado em " << parcelas << "x de R$ " << total/parcelas << " com 3% de juros ao mês.";
}

// Função principal

int main()
{
    setlocale(LC_ALL, "Portuguese");
    double total;

    cout << "Digite o total gasto: R$ "; // Registramos o valor total gasto pelo cliente para ser utilizado nas funções de cálculo de acordo com a opção escolhida.
    cin >> total;

    char escolha = menu(); // Chamamos a função do menu.

// Verificamos a opção escolhida e chamamos a função correspondente para realizar o cálculo e exibir o resultado.
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
        if (total < 100) // Verificamos se o valor total é menor que R$100,00, pois nesse caso a opção C não é válida.
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