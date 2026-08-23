/*
Exercício 1: Ranking de Alunos (Bubble Sort)

- Objetivo: Organizar uma lista de alunos pela nota final.

- Crie uma struct Aluno contendo nome (string), matricula (int) e nota (float)

- No main, peça ao usuário o número de alunos e use alocação dinâmica (new) para criar um vetor de estruturas do tamanho informado

- Implemente o algoritmo Bubble Sort para ordenar os alunos de forma que as maiores notas fiquem no início do vetor (ordem decrescente)

- Uso de Ponteiro: A função de ordenação deve receber como parâmetro um ponteiro para a estrutura aluno (ex: void ordenar(Aluno *v, int tam)) e realizar as comparações acessando os campos via ponto (v[j].nota)

*/


#include <iostream>
using namespace std;

struct Aluno{
    string nome;
    int matricula;
    double nota;
};

void bubbleSort(Aluno *vet, int tam){
    int i, j;
    Aluno aux;

    for (i=0;i<tam;i++){
        for(j=0; j<tam-i-1; j++){
            if(vet[j].nota < vet[j+1].nota){
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }

}

void preencherDados(Aluno *vet, int tam){

    for(int i = 0; i < tam; i++){
        cout << "Nome do aluno[" << i << "]: ";
        cin >> vet[i].nome;
        cout << "Matrícula do aluno[" << i << "]: ";
        cin >> vet[i].matricula;
        cout << "Nota do aluno["<< i << "]: ";
        cin >> vet[i].nota;
    }
}

void copiarVetor(Aluno *origem, Aluno *destino, int tam){
    for(int i = 0; i<tam; i ++){
        destino[i] = origem[i];
    }
}

void mostrarDados(Aluno *vet, int tam){

    for(int i = 0; i<tam; i++){
        cout << "Nome[" << i << "]: " << vet[i].nome << endl;
        cout << "Matrícula[" << i << "]: " << vet[i].matricula << endl;
        cout << "Nota[" << i << "]: " << vet[i].nota << endl;
    }
}


void menu(){
    int op;
    int tam;
    Aluno *listaAlunos = nullptr;

    do{
        cout << "-------------------\n";
        cout << "RANKING DE ALUNOS\n";
        cout << "-------------------\n";
        cout << "[1] - Cadastrar alunos\n";
        cout << "[2] - Mostrar alunos\n";
        cout << "[3] - Organizar\n";
        cout << "[4] - Sair\n";
        cout << "Opção: ";
        cin >> op;

        switch (op){

            case 1:
            if (listaAlunos != nullptr){
                delete [] listaAlunos;
            }
            
            cout << "Quantos alunos deseja cadastrar?: ";
            cin >> tam;

            listaAlunos = new Aluno[tam];

            preencherDados(listaAlunos, tam);
            cout << "Alunos cadastrados com sucesso!" << endl;

            break;

            case 2:
            if (listaAlunos == nullptr){
                cout << "Nenhum aluno cadastrado." << endl;
            }
            else{
                cout << "===== ALUNOS CADASTRADOS =====" << endl;
                mostrarDados(listaAlunos, tam);
            }
            break;

            case 3:
            if (listaAlunos == nullptr){
                cout << "Nenhum aluno cadastrado." << endl;
            }
            else{

                Aluno *copia;
                copia = new Aluno[tam];
                copiarVetor(listaAlunos, copia, tam);

                cout << "===== ANTES DA ORDENACAO =====" << endl;

                mostrarDados(copia, tam);
                
                cout << "===== DEPOIS DA ORDENACAO =====" << endl;

                bubbleSort(copia, tam);
                mostrarDados(copia,tam);


                delete[] copia;
            }

            break;

            case 4: 
            cout << "Encerrando programa..." << endl;
            break;

            default: 
            cout << "Opção inválida." << endl;
        }

    }while(op!=4);

    if (listaAlunos != nullptr){
        delete [] listaAlunos;
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    menu();

    return 0;
}