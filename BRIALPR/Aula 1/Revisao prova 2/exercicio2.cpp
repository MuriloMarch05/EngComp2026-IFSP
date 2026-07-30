/*2) Você irá programar um sistema de sensores monitora o volume de água em um reservatório de condomínio.
O síndico precisa receber alertas caso o nível chegue a patamares críticos. O usuário deve digitar a capacidade
máxima do reservatório (em litros) e a quantidade atual de água armazenada (em litros).
 Crie uma função chamada verificarNivel que receba a capacidade máxima e o nível atual, calculando a
porcentagem de água restante.
 No programa principal, avalie o retorno: se a porcentagem for menor ou igual a 20%, exiba a mensagem
"ALERTA: Ligar bomba - Nível crítico!". Se for maior ou igual a 95%, exiba "ALERTA: Reservatório
cheio - Risco de transbordo!". Caso contrário, exiba "Status: Nível seguro".*/

#include <iostream>
#include <iomanip>
using namespace std;

double verificarNivel(double cap_max, double nivel_atual)
{
    double porcentagem;

    porcentagem = (nivel_atual / cap_max) * 100;
    
    return porcentagem;
    
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    double cap_max=0, nivel_atual=0, porcentagem=0;
    
    cout << "Digite a capacidade maxima do reservatorio (Em litros): ";
    cin >> cap_max;
    
    cout << "Qual o nivel atual de agua? ";
    cin >> nivel_atual;

    porcentagem = verificarNivel(cap_max, nivel_atual);


    if (porcentagem <= 20)
    {
        cout << "Ligar Bomba - Nível crítico!" << endl;
    }

    else if (porcentagem >= 95)
    {
        cout << "ALERTA: Reservatório cheio - Risco de transbordo!" << endl;
    }

    else
    {
        cout << "Status: Nível seguro." << endl;
    }

    return 0;
}