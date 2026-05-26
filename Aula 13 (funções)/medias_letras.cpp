/*6) Elabore uma função que receba 3 notas de um aluno como parâmetro e uma
letra. Se a letra for ‘A’, a função deve calcular a média aritmética das notas do
aluno; se a letra for ‘P’, deverá calcular a média ponderada, com pesos 5, 3 e 2.
Retorne a média calculada para o programa principal.*/

#include <iostream>
#include <iomanip>
using namespace std;

void medias(double n1, double n2, double n3, char letra)
{
    double media;
    
    if (letra == 'A')
    {
        media = (n1+n2+n3)/3;
    }
    else if(letra == 'P')
    {
        media = ((n1*5)+(n2*3)+(n3*2))/ (5 + 3 + 2);
    }
    
    cout << "A média é: " << media << endl;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    double nota1,nota2,nota3;
    char letra;
    
    cout << "Digite as 3 notas: " << endl;
    cin >> nota1>>nota2>>nota3;
    
    cout << "Qual opção? (A/P)  ";
    cin >> letra;
    letra = toupper(letra);
    
    medias(nota1,nota2,nota3,letra);
    
    return 0;   
}