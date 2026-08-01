/*3) Uma grande plataforma de compras online precisa calcular o valor final do carrinho de um cliente,
aplicando primeiro um cupom de desconto sobre o produto e, depois, adicionando o valor do frete baseado
na distância de entrega. Peça ao usuário o preço original do produto, o percentual de desconto do cupom (ex:
15 para 15%) e a distância até a sua casa em quilômetros.


Crie a primeira função chamada aplicarCupom, que recebe o preço do produto e o percentual de
desconto, retornando o preço do produto atualizado.
Crie a segunda função chamada calcularFrete, que recebe a distância em km e calcula o custo de
envio (considere o valor fixo de R$ 1,20 por quilômetro rodado).
Na main, utilize o retorno das duas funções para exibir o preço do produto com desconto, o valor do
frete e o valor total final da compra.*/

#include <iostream>
#include <iomanip>
using namespace std;


double aplicarCupom(double preco, double desconto)
{
    preco = preco - (preco * desconto/100);

    return preco;

}

double calcularFrete(double distancia)
{
    double frete=0;

    frete = distancia*1.20;

    return frete;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    double preco=0, desconto=0, distancia=0,val_final=0;

    cout << "Digite o preço do produto: R$ ";
    cin >> preco;

    cout << "Qual desconto deseja aplicar? (em %) ";
    cin >> desconto;

    cout << "Qual a distância de entrega? (em KM) ";
    cin >> distancia;

    cout << "Preço do produto com desconto de "<< desconto << "%: R$" << aplicarCupom(preco, desconto) << endl;
    cout << "Valor do frete para a distância de " << distancia << "km: R$" << calcularFrete(distancia) << endl;
    val_final = aplicarCupom(preco, desconto) + calcularFrete(distancia);
    cout << "Valor total final da compra: R$" << val_final << endl;

    return 0;

}