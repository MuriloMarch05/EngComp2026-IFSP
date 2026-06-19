/*4) Um investidor possui diversos ativos digitais e precisa de um sistema para consolidar o valor total de sua
carteira de investimentos. Crie uma estrutura chamada Criptomoeda com os campos: nome (string),
quantidade (float) e precoUnitarioUSD (float).


No programa principal, declare um vetor para armazenar 5 criptomoedas e peça para o usuário cadastrar
os dados de cada uma.
Ao final, o programa deve calcular e exibir o valor total da carteira em dólares (somatório de quantidade
X precoUnitarioUSD de todas as moedas) e mostrar o nome da moeda na qual o usuário tem o maior
valor investido.*/

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;


struct criptomoeda
{
    string nome;
    float quantidade;
    float precoUnitarioUSD;

}carteira[5];

int main()
{
    setlocale(LC_ALL, "Portuguese");
    float soma=0, moeda_maior=0;
    string nome_maior;
    for(int i=0; i<5; i++)
    {
        cout << "Digite o nome da criptomoeda: ";
        cin >> carteira[i].nome;

        cout << "Digite a quantidade: ";
        cin >> carteira[i].quantidade;

        cout << "Digite o preço unitário: ";
        cin >> carteira[i].precoUnitarioUSD;

        soma = soma + (carteira[i].quantidade*carteira[i].precoUnitarioUSD);

    }

    cout << "Soma de todas as criptomoedas: USD$ ";
    cout << soma << endl;

    for (int i = 0; i<5; i++)
    {
        nome_maior = carteira[0].nome;
        moeda_maior = carteira[0].precoUnitarioUSD*carteira[0].quantidade;

        if (carteira[i].precoUnitarioUSD*carteira[i].quantidade > moeda_maior)
        {
            moeda_maior = carteira[i].precoUnitarioUSD*carteira[i].quantidade;
            nome_maior = carteira[i].nome;
        }
    }

    cout << "A carteira poussi no total: USD$ " << soma << endl;
    cout << "O maior valor investido está na criptomoeda: " << nome_maior << endl;

    return 0;
}