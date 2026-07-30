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
#include <limits>
using namespace std;

struct criptomoeda
{
    string nome;
    float quantidade;
    float precoUnit;

}carteira[5];

int main()
{
    cout << setprecision(2) << fixed;
    float valor_total=0, maior_valor=0;
    string maior_nome;

    for (int i = 0; i<5; i++)
    {
        cout << "Nome da criptomoeda: ";
        getline(cin, carteira[i].nome);

        cout << "Quantidade: ";
        cin >> carteira[i].quantidade;

        cout << "Preço unitário: USD$ ";
        cin >> carteira[i].precoUnit;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        valor_total += carteira[i].quantidade*carteira[i].precoUnit;
    
    }

    maior_valor = carteira[0].quantidade*carteira[0].precoUnit;
    maior_nome = carteira[0].nome;

    cout << "Valor total da carteira USD$ " << valor_total << endl;
    
    for (int i = 0; i<5; i++)
    {
        if (carteira[i].quantidade*carteira[i].precoUnit>maior_valor)
        {
            maior_valor = carteira[i].quantidade*carteira[i].precoUnit;
            maior_nome = carteira[i].nome;
        }
    }
    cout << "Criptomoeda com maior valor investido: " << maior_nome;

    return 0;
}