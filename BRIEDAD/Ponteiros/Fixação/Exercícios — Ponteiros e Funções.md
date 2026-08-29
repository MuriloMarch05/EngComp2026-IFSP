# Exercícios — Ponteiros e Funções

## 1. O que é um ponteiro? E para que serve um ponteiro?

Ponteiro é uma variável que armazena o endereço de memória de outra variável. Ele  
permite alterar diretamente o valor da variável na qual ele aponta. Além disso, é útil  
para alocação dinâmica de memória durante a execução do programa.

---

## 2. Quais das seguintes instruções são corretas para declarar um ponteiro?

a) `int _ptr x;`  
b) `int *ptr;` **X**  
c) `*int ptr;`  
d) `*x;`

---

## 3. Qual é a maneira correta de referenciar ch, assumindo que o endereço de ch foi atribuído ao ponteiro indica?

a) `*indica;` **X**  
b) `int *indica;`  
c) `*indic;`  
d) `ch`  
e) `*ch;`

---

## 4. Na expressão float *pont; o que é do tipo float?

a) a variável pont.  
b) o endereço de pont.  
c) a variável apontada por pont. **X**  
d) nenhuma das anteriores.

---

## 5. Assumindo que o endereço de num foi atribuído a um ponteiro pnum, quais das seguintes expressões são verdadeiras?

a) `num == &pnum`  
b) `num == *pnum` **X**  
c) `pnum == *num`  
d) `pnum == &num` **X**

---

## 6. Assumindo que queremos ler o valor de x, e o endereço de x foi atribuído a px, a instrução seguinte é correta? Por que?

```cpp
scanf ( “%d”, *px );
```

Não, a instrução está incorreta. A função scanf exige o endereço da variável onde o  
valor será armazenado. Como px já contém o endereço de x, o correto é utilizar  
`scanf("%d", px);`. Já que *px representa o valor armazenado em x, e não seu endereço.

---

## 7. Qual é a instrução que deve ser adicionada ao programa seguinte para que ele trabalhe corretamente?

```cpp
main ( ) {
    int j, *pj;
    *pj = 3;
}
```

Deve ser adicionada a seguinte instrução: `pj = &j`.

---

## 8. Qual o valor das seguintes expressões:

```cpp
int i = 3, j = 5;
int *p = &i, *q = &j;
```

### a) `p == &i`

Verdadeiro.

### b) `*p - *q`

-2

### c) `**&p`

3

---

## 9. Se i e j são variáveis inteiras e p e q são ponteiros para inteiros, quais das seguintes expressões de atribuição são ilegais?

a) `p = &i;`

b) `*q = &j;` **X**

c) `p = &*&i;`

d) `i = (*&)j;` **X**

e) `i = *&*&j;`

f) `q = &p;` **X**

g) `i = (*p) ++ + *q;`

---

## 10. Seja a seguinte seqüência de instruções em um programa C++:

```cpp
int *pti;
int i = 10;
pti = &i;
```

Qual afirmativa é falsa?

a) pti armazena o endereço de i

b) *pti é igual a 10

c) ao se executar *pti = 20; i passará a ter o valor 20

d) ao se alterar o valor de i, *pti será modificado

e) pti é igual a 10 **X**

---

# 11. Desenvolva um programa em C++ que declare três variáveis do tipo inteiro e três do tipo ponteiro de inteiro apontando para essas variáveis. Utilizando ponteiros, leia três números e os imprima em ordem crescente. O programa deve apresentar também o endereço de memória desses números.

```cpp
#include <iostream>
#include <clocale>
using namespace std;

// Função A.
void ordenar(int *p_int1, int *p_int2, int *p_int3) {
    int aux=0;

    if (*p_int1 > *p_int2) {
        aux = *p_int1;
        *p_int1 = *p_int2;
        *p_int2 = aux;
    }

    if (*p_int1 > *p_int3) {
        aux = *p_int1;
        *p_int1 = *p_int3;
        *p_int3 = aux;
    }

    if (*p_int2 > *p_int3) {
        aux = *p_int2;
        *p_int2 = *p_int3;
        *p_int3 = aux;
    }
}

void imprimir(int *p_int1, int *p_int2, int *p_int3) {
    cout << "=== NÚMEROS EM ORDEM CRESCENTE ===" << endl;
    cout << "[1]: "<< *p_int1 << " -> Endereço de memória: "<< p_int1 << endl;
    cout << "[2]: "<< *p_int2 << " -> Endereço de memória: "<< p_int2 << endl;
    cout << "[3]: "<< *p_int3 << " -> Endereço de memória: "<< p_int3 << endl;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    //Variáveis
    int int1=0, int2=0, int3=0;

    // Ponteiros
    int *p_int1, *p_int2, *p_int3;

    // Ponteiros recebem endereços
    p_int1 = &int1;
    p_int2 = &int2;
    p_int3 = &int3;

    // Cadastro
    cout << "=== CADASTRE 3 NÚMEROS INTEIROS === " << endl;
    cout << "Número[1]: ";
    cin >> int1;

    cout << "Número[2]: ";
    cin >> int2;

    cout << "Número[3]: ";
    cin >> int3;

    ordenar(p_int1, p_int2, p_int3); // Organiza em ordem crescente.
    imprimir(p_int1, p_int2, p_int3); // Imprime já ordenado.

    return 0;
}
```

---

# 12. Faça um programa em C++ que receba uma frase qualquer fornecida pelo usuário, que calcule e mostre quantos caracteres essa frase possui. Esse programa deve conter ponteiros para manusear a string. A frase deve possuir no máximo 50 caracteres.

```cpp
#include <iostream>
#include <clocale>
using namespace std;

int verificarFrase(char *p_frase, int op) {
    int caracteres=0;

    if (op==1) {
        while(*p_frase != '\0') {
            caracteres++;
            p_frase++;
        }
    }
    else {
        while(*p_frase != '\0') {
            if (*p_frase != ' ') {
                caracteres+=1;
            }

            p_frase++;
        }
    }

    return caracteres;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int op=0;
    string frase;
    char *p_frase;

    do {
        cout << "Digite uma frase: ";
        getline(cin, frase);

        cout << "Contar espaços?\n[1]-Sim\n[2]-Não\nOpção: ";
        cin >> op;
        cin.ignore();

        if(frase.size()>50) {
            cout << "Frase muito longa (50+). Tente novamente.\n";
        }

    } while(frase.size() > 50);

    p_frase = &frase[0]; // O ponteiro recebe o endereço de memória do primeiro
                          // elemento da string frase.

    cout << "A frase possui " << verificarFrase(p_frase, op) << " caracteres." <<
    endl;

    return 0;
}
```

---

# 13. Desenvolva um programa em C++ que leia seis números e armazene-os em um vetor. Esse programa deve conter ponteiros para manusear o vetor e imprimir os seus valores. O programa deve apresentar também o endereço de memória desses números.

```cpp
#include <iostream>
#include <clocale>
using namespace std;

void imprimirVetor(int *p_vet) {
    for(int i = 0;i<6;i++) {
        cout << "Elemento["<<i<<"]: " << *p_vet << " -> Endereço: " << p_vet << endl;
        p_vet++;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int vetor[6];
    int *p_vet;

    cout << "Digite seis números inteiros: " << endl;

    for(int i = 0;i<6;i++) {
        cout << "Número["<< i << "]: ";
        cin >> vetor[i];
    }

    p_vet = &vetor[0];

    cout << "------------------------------------------\n";

    imprimirVetor(p_vet);

    return 0;
}
```

---

# 14. Desenvolva um programa para testar as funções a seguir:

### a.

Uma função que receba dois números a e b, em seguida, faça troca destes dois  
números (todos os parâmetros devem ser passados por referência).

### b.

Uma função que receba dois números a e b, em seguida, decremente o primeiro e  
incremente o segundo (todos os parâmetros devem ser passados por referência).

### c.

Uma função que receba o raio, perímetro e área de um círculo. Em seguida, calcule e  
retorne nas variáveis perímetro e área o respectivo perímetro e área do círculo (todos  
os parâmetros devem ser passados por referência).

### d.

Uma função que receba os valores a, b e c passados por valor, receba também dois  
valores x1 e x2 passados por referência. Em seguida, calcule e retorne as duas raízes  
da equação do segundo grau nas variáveis x1 e x2.

```cpp
#include <iostream>
#include <iomanip>
#include <cmath>
#include <clocale>
using namespace std;

// Função A.
void troca(int &A, int &B) {
    int aux=0;

    aux=A;
    A=B;
    B=aux;
}

// Função B.
void incdec(int &A, int &B) {
    A--;
    B++;
}

// Função c.
void circulo(double &raio, double &perimetro, double &area) {
    perimetro = 2*M_PI*raio;
    area = M_PI*raio*raio;
}

// Função d.
void bhaskara(double a, double b, double c, double &x1, double &x2) {
    // depois: mudar para bool, pois posso mostrar o resultado caso tenha duas raízes, se não
    // tiver, não mostra.

    double delta = b*b - 4*a*c;

    if (delta >=0 ) {
        x1=(-b+sqrt(delta)) / (2*a);
        x2= (-b-sqrt(delta)) / (2*a);
    }
    else {
        cout << "A expressão não tem duas raízes reais." << endl;
    }
}

int main() {
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

    do {
        cout << "Coeficiente a: " << endl;
        cin >> a;

        if(a==0) {
            cout << "O coeficiente de a nao pode ser 0." << endl;
        }

    } while (a==0);

    cout << "Coeficiente de b: " << endl;
    cin >> b;

    cout << "Termo independente c: " << endl;
    cin >> c;

    bhaskara(a,b,c,x1,x2);

    cout << "Raízes da expressão\nx1 = " << x1 << "\nx2 = " << x2 << endl;

    return 0;
}
```

---

# 15. Desenvolva um programa que leia a quantidade total de segundos e converta para Horas, Minutos e Segundos. Imprima o resultado da conversão no formato HH:MM:SS. Para isso, utilize a função com protótipo void converteHora(int total_segundos, int *hora, int *min, int *seg).

```cpp
#include <iostream>
#include <iomanip>
#include <clocale>
using namespace std;

void converteHora(int total_segundos, int *hora, int *min, int *seg) {
    int resto;

    *hora = total_segundos / 3600;
    resto = total_segundos % 3600;
    *min = resto / 60;
    *seg = resto % 60;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int total_segundos=0, hora=0, min=0, seg=0;

    cout << "=== CONVERTER SEGUNDOS EM HORAS ===" << endl;

    cout << "Quantos segundos? ";
    cin >> total_segundos;

    cout << "=== CONVERSÃO FINALIZADA ===" << endl;

    converteHora(total_segundos, &hora, &min, &seg);

    cout << setfill('0') << setw(2) << hora << ":" << setw(2) << min << ":" << setw(2)
    << seg << endl;

    return 0;
}
```
