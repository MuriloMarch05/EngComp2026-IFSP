/******************************************************************************
 * INTRODUÇÃO À ALGORITMOS E LÓGICA DE PROGRAMAÇÃO
 * Baseado na Aula 1 - Profa. Karina
 * 
 * 1. CONCEITOS BÁSICOS
 * O computador é uma máquina criada para auxiliar o homem, sendo rápido e 
 * versátil. No entanto, ele não possui iniciativa, independência, criatividade 
 * ou inteligência própria.
 * 
 * Para que ele execute tarefas, deve receber instruções nos mínimos detalhes 
 * através de PROGRAMAS e LINGUAGENS DE PROGRAMAÇÃO.
 * 
 * 2. FINALIDADE DO COMPUTADOR: PROCESSAMENTO DE DADOS
 * O fluxo de funcionamento segue três etapas fundamentais:
 *    ENTRADA -> PROCESSAMENTO -> SAÍDA
 *    (Dados)    (Transformação)  (Resposta/Exibição)
 * 
 * 3. O QUE É UM ALGORITMO?
 * É uma sequência de passos que visa atingir um objetivo bem definido.
 * Um algoritmo não é a solução única de um problema; diferentes algoritmos 
 * podem resolver o mesmo problema.
 * 
 * Exemplo do dia a dia (Descrição Narrativa): Fritar um ovo
 *    Passo 1 - Pegar a frigideira, o ovo, o óleo e o sal.
 *    Passo 2 - Colocar o óleo na frigideira e ligar o fogo.
 *    Passo 3 - Quebrar o ovo na frigideira e temperar com sal.
 *    Passo 4 - Apagar o fogo quando estiver pronto e servir.
 * 
 * 4. ETAPAS PARA O DESENVOLVIMENTO DE UM PROGRAMA
 * Para criar um software, seguimos este ciclo:
 *    a) Análise: Estudar o enunciado para definir Entradas, Processamento e Saídas.
 *    b) Algoritmo: Descrever a solução usando ferramentas (narrativa, fluxograma).
 *    c) Codificação: Transformar o algoritmo em código (ex: Linguagem C++).
 * 
 * 5. TIPOS DE ALGORITMOS MAIS UTILIZADOS
 *    - Descrição Narrativa: Linguagem natural (como a receita acima).
 *    - Fluxograma: Uso de símbolos gráficos para representar o fluxo.
 *    - Pseudocódigo (Portugol): Uso de regras e palavras reservadas (ex: leia, escreva).
 * 
 * EXEMPLO DE ALGORITMO: MULTIPLICAÇÃO DE 2 NÚMEROS
 * 
 *    - Descrição Narrativa:
 *      1. Receber os dois números.
 *      2. Multiplicar os números.
 *      3. Mostrar o resultado.
 * 
 *    - Pseudocódigo:
 *      var N1, N2, M: inteiro
 *      Inicio
 *         escreva("Digite 2 números")
 *         leia(N1, N2)
 *         M = N1 * N2
 *         escreva("Multiplicação = ", M)
 *      Fim
 ******************************************************************************/

#include <iostream>

using namespace std;

int main() {
    // Exemplo Simples em C++ (Codificação)
    int n1, n2, m;

    cout << "Digite o primeiro numero: ";
    cin >> n1;
    cout << "Digite o segundo numero: ";
    cin >> n2;

    m = n1 * n2; // Processamento

    cout << "Resultado da multiplicacao: " << m << endl; // Saída

    return 0;
}

