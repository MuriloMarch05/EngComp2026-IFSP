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
    string Titulo, Autor, Categoria;
    int Ano;
    float Preco;
};

Livro Biblioteca[20];

int Cadastrar(Livro B[], int Tam){

    cout << "Título[" << Tam << "]: ";
    cin >> B[Tam].Titulo;
    cout << "Autor[" << Tam << "]: ";
    cin >> B[Tam].Autor;
    cout << "Categoria[" << Tam << "]: ";
    cin >> B[Tam].Categoria;
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
    cout << "Categoria["<< Pos << "]: " << B[Pos].Categoria << endl;
        
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


void BuscarLivro(Livro B[], int Tam, string Categoria){
    int cont;
    for(cont=0;cont<Tam;cont++){
        if(B[cont].Categoria == Categoria){
            ImprimirReg(B, cont, 1);
        }
    }
}

void Menu(Livro B[]){
    int opcao, Tam = 0, opcaoTipo;
    string categ;

    do{
        system("clear");
        cout << "------------------------------------" << endl;
        cout << "BIBLIOTECA" << endl;
        cout << "------------------------------------" << endl;
        cout << "[1] - Cadastrar" << endl;
        cout << "[2] - Imprimir" << endl;
        cout << "[3] - Buscar Livros" << endl;
        cout << "[4] - Sair" << endl;
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
                cout << "Qual categoria?: ";
                cin >> categ;
                BuscarLivro(B, Tam, categ);
                break;

            case 4:
                break;

            default:
                cout << "Opção inválida." << endl;
        }
        
        cout << "Pressione ENTER para continuar...";
        cin.ignore();
        cin.get();

    }while(opcao!=4);

}

int main(){
    setlocale(LC_ALL, "Portuguese");

    Menu(Biblioteca);

    return 0;
}