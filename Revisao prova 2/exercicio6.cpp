/*6) Para cumprir as regras da Lei Geral de Proteção de Dados (LGPD), um e-commerce precisa ocultar parte
do e-mail do cliente na tela de confirmação de compra para que ninguém veja o endereço completo. Solicite
que o usuário digite o seu e-mail completo (ex: aluno.engenharia@provedor.com).


O programa deve processar essa string e substituir os caracteres do nome do e-mail por asteriscos (*),
preservando apenas as 3 primeiras letras e todo o domínio (o que vem depois do caractere @).
Exiba o e-mail mascarado na tela (ex: alu************@provedor.com).*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    string email;

    cout << "Digite o seu endereço de e-mail completo: ";
    getline(cin, email);

    for (int i = 3; email[i]!= '@'; i++)
    {
        email[i] = '*';
    }
    
    cout << "Email: " << email;

    return 0;
}