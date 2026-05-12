/*1) Crie um programa que calcule o desconto de uma compra baseado no valor total e no
método de pagamento.
 Se o valor for maior que R$ 500:
o Se pagar com Pix, dê 15% de desconto.
o Se pagar com Cartão, dê 5% de desconto.
 Se o valor for entre R$ 200 e R$ 500:
o Se pagar com Pix, dê 10% de desconto.
o Se pagar com Cartão, sem desconto.
 Se for menor que R$ 200:
o Sem descontos independentemente do método.*/


#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << fixed << setprecision(2);
    double val_tot, desconto; 
    char metodo;
    
    cout << "Digite o valor da sua compra: R$ ";
    cin >> val_tot;
    
    cout << "Metodo de pagamento: \n1-P\n2-C\n";
    cin >> metodo;
    metodo = toupper(metodo);
    
    if(val_tot>500)
    {
        if(metodo=='P')
        {
            desconto = val_tot*0.85;
            cout << "Valor com desconto no pix: R$ " << desconto << endl;
        }
        else if (metodo == 'C')
        {
            desconto = val_tot*0.95;
            cout << "Valor com desconto no cartao: R$ "<< desconto << endl;
        }
    }
    
    else if(val_tot >= 200 && val_tot <=500)
    {
        if (metodo=='P')
        {
            desconto = val_tot*0.90;
            cout << "Valor com desconto no pix: R$ " << desconto << endl;
        }
        else if(metodo=='C')
        {
            cout << "Valor sem desconto no cartao: R$ " << val_tot << endl;
        }
    }
    else if (val_tot<200)
    {
        cout << "Nesse valor, não há desconto. Você pagará: R$ " << val_tot << endl;
    }
    
    return 0;
}