/*2 - Elabore um programa que possua 5 registros c/ os seguintes campos:
nome da mercadoria, preço unitário, quantidade comprada e preço total
da compra. O preço total da compra será calculado pelo programa e o
restante dos campos o usuário é que irá digitar. Imprima no final o total
da compra, ou seja, o preço final das 5 mercadorias adquiridas.*/

#include <iostream>
#include <iomanip>
using namespace std;

// Definindo a estrutura para armazenar os dados das compras
struct compras{
    string nome;
    double precoUnit;
    int qtde;
}produtos[5]; // Array de 5 elementos do tipo compras

// Função principal
int main()
{
    setlocale(LC_ALL, "Portuguese");
    double total = 0.0; // Variável para armazenar o total da compra

    for (int i = 0; i<5; i++) // Loop para ler os dados de cada mercadoria
    {
        cout << "Digite o nome da  mercadoria no." << i+1 << endl;
        cin >> produtos[i].nome;

        cout << "Digite o preço unitário: R$ ";
        cin >> produtos[i].precoUnit;

        cout << "Quantidade comprada: ";
        cin >> produtos[i].qtde;

        total += produtos[i].precoUnit*produtos[i].qtde; // Calculando o preço total da compra e acumulando no total
    }


    cout << "Total da compra: R$ " << total;

    return 0;
}



