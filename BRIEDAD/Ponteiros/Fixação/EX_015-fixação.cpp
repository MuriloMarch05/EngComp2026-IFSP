/*

15. Desenvolva um programa que leia a quantidade total de segundos e converta para Horas, Minutos e Segundos. Imprima
o resultado da conversão no formato HH:MM:SS. Para isso, utilize a função com protótipo void converteHora(int
total_segundos, int *hora, int *min, int *seg).

*/
#include <iostream>
#include <iomanip>
#include <clocale>
using namespace std;


void converteHora(int total_segundos, int *hora, int *min, int *seg){

    int resto;

    *hora = total_segundos / 3600;

    resto = total_segundos % 3600;

    *min = resto / 60;

    *seg = resto % 60;

}

int main(){
    setlocale(LC_ALL, "Portuguese");

    int total_segundos=0, hora=0, min=0, seg=0;

    cout << "=== CONVERTER SEGUNDOS EM HORAS ===" << endl;
    cout << "Quantos segundos? ";
    cin >> total_segundos;

    cout << "=== CONVERSÃO FINALIZADA ===" << endl;
    converteHora(total_segundos, &hora, &min, &seg);

    cout << setfill('0') << setw(2) << hora << ":" << setw(2) << min << ":" << setw(2) << seg << endl;

    return 0;
}