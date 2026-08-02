/*

Exercício 1: Cadastro de Livros

- Struct Livro: Titulo, Autor, Ano (int), Preço (float)
- Vetor Biblioteca[20]
- Função Cadastrar (mesmo padrão do Tam)
- Função Imprimir_Vetor com Tipo (1 = tudo, 2 = só Título e Autor)
- Menu com Cadastrar / Imprimir / Sair 

*/

#include <iostream>
#include <cstdlib>
using namespace std;

struct Livro{
    string Titulo, Autor;
    int Ano;
    float Preco;
};

Livro Biblioteca[20];

int Cadastrar(Livro B[], int Tam){

    cout << "Título[" << Tam << "]: ";
    cin >> B[Tam].Titulo;
    cout << "Autor[" << Tam << "]: ";
    cin >> B[Tam].Autor;
    cout << "Ano[" << Tam << "]: ";
    cin >> B[Tam].Ano;
    cout << "Preço[" << Tam << "]: ";
    cin >> B[Tam].Preco;
    
    Tam++;

    return Tam;

}


void ImprimirReg(Livro B[], int Pos, int Tipo){

    cout << "Título[" << Pos << "]: " << B[Pos].Titulo << endl;
    cout << "Autor[" << Pos << "]: " << B[Pos].Autor << endl;
        
    if (Tipo==1){
        cout << "Ano[" << Pos << "]: " << B[Pos].Ano << endl;
        cout << "Preço[" << Pos << "]: " << B[Pos].Preco << endl;
        }
}



void ImprimirVetor(Livro B[], int Tam, int Tipo){
    int cont;
    for(cont=0;cont<Tam;cont++){
        ImprimirReg(B, cont, Tipo);
    }
}

void Menu(Livro B[]){
    int opcao, Tam = 0, opcaoTipo;

    do{
        system("clear");
        cout << "[1] - Cadastrar" << endl;
        cout << "[2] - Imprimir" << endl;
        cout << "[3] - Sair" << endl;
        cout << "Opção: ";
        cin >> opcao;


        switch(opcao){
            
            case 1:
                // Puxar a funcao de cadastro
                Tam = Cadastrar(B, Tam);
                break;
            
            case 2:
                // Puxar a funcao de impressao
                cout << "[1] - Total" << endl;
                cout << "[2] - Parcial" << endl;
                cin >> opcaoTipo;

                ImprimirVetor(B, Tam, opcaoTipo);
                break;

            case 3:
                break;

            default:
                cout << "Opção inválida." << endl;
        }
        
        cout << "Pressione ENTER para continuar...";
        cin.ignore();
        cin.get();

    }while(opcao!=3);

}

int main(){
    setlocale(LC_ALL, "Portuguese");

    Menu(Biblioteca);

    return 0;
}