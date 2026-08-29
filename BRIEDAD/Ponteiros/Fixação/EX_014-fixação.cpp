/*

14. Desenvolva um programa para testar as funções B seguir:
B. Uma função que receba dois números B e B, em seguida, faça troca destes dois números (todos os parâmetros devem
ser passados por referência).
B. Uma função que receba dois números B e B, em seguida, decremente o primeiro e incremente o segundo (todos os
parâmetros devem ser passados por referência).
c. Uma função que receba o raio, perímetro e área de um círculo. Em seguida, calcule e retorne nas variáveis perímetro e
área o respectivo perímetro e área do círculo (todos os parâmetros devem ser passados por referência).
d. Uma função que receba os valores a, b e c passados por valor, receba também dois valores x1 e x2 passados por
referência. Em seguida, calcule e retorne as duas raízes da equação do segundo grau nas variáveis x1 e x2.

*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <clocale>
using namespace std;

// Função A.
void troca(int &A, int &B){
    int aux=0;

    aux=A;
    A=B;
    B=aux;
}
// Função B.
void incdec(int &A, int &B){
    A--;
    B++;

}
// Função c.
void circulo(double &raio, double &perimetro, double &area){

    perimetro = 2*M_PI*raio;
    area = M_PI*raio*raio;

}
// Função d.
void bhaskara(double a, double b, double c, double &x1, double &x2){ // depois: mudar para bool, pois posso mostrar o resultado caso tenha duas raízes, se não tiver, não mostra.

    double delta = b*b - 4*a*c;

    if (delta >=0 ){
        x1=(-b+sqrt(delta)) / (2*a);
        x2= (-b-sqrt(delta)) / (2*a); 
    }
    else{
        cout << "A expressão não tem duas raízes reais." << endl;
    }


}
int main(){
    cout << fixed << setprecision(2);
    setlocale(LC_ALL, "Portuguese");
    // variaveis função A e B.
    int A=0, B=0;

    // variaveis função c.
    double raio=0, perimetro=0, area=0;

    // variaveis função d.
    double a=0, b=0, c=0, x1=0, x2=0;

    // Primeira função
    cout << "Digite dois números inteiros" << endl;
    cout << "A = ";
    cin >> A;
    cout << "B = ";
    cin >> B;
    troca(A,B);
    cout << "Valores trocados:\nA=" << A <<"\nB=" << B << endl;

    // Segunda função
    incdec(A,B);
    cout << "Valores incrementados / decrementados: " << endl;
    cout << "A-1 = " << A <<"\nB+1 = "<< B << endl;

    // Terceira função
    cout << "Agora, digite o raio de um círculo: ";
    cin >> raio;

    circulo(raio, perimetro, area);
    cout << "Área do cículo: " << area << "\nPerímetro: " << perimetro << endl;

    // Quarta função
    cout << "=== EQUAÇÃO DO SEGUNDO GRAU (ax² + bx + c = 0) ===" << endl;
    do{
        cout << "Coeficiente a: " << endl;
        cin >> a;
        if(a==0){
            cout << "O coeficiente de a nao pode ser 0." << endl;
        }
    }while (a==0);

    cout << "Coeficiente de b: " << endl;
    cin >> b;
    cout << "Termo independente c: " << endl;
    cin >> c;
    bhaskara(a,b,c,x1,x2);
    cout << "Raízes da expressão\nx1 = " << x1 << "\nx2 = " << x2 << endl;

    return 0;
}