/*
Fazer um programa para simular uma agenda de telefones. Para cada pessoa deve-se ter os seguintes dados:
Nome;
E-mail;
Telefone;
Cidade;
Estado (2 caracteres, exemplo "SP");
Idade;
Definir a estrutura acima (struct Contato) e a variável Agenda com capacidade de agendar até 10 pessoas (Contato Agenda[10]);
Definir uma função (sem retorno) para leitura dos dados do vetor Agenda;
Definir uma função (sem retorno) que busque (no vetor Agenda) as pessoas maiores de 18 anos e que pertençam a um estado fornecido pelo usuário (parâmetro de entrada). Imprimir os dados das pessoas encontradas na própria função;
Definir uma função (com retorno) que encontre e retorne a posição (no vetor Agenda) da pessoa mais velha. Imprimir os dados da pessoa depois da chamada da função (na opção do menu) e usando o vetor Agenda e a posição retornada;
Definir uma função (sem retorno) de impressão de todo o vetor Agenda com um parâmetro de entrada (int) que aceite 2 opções: 1 (todos os dados) e 2 (somente nome, telefone e email);
Implementar um menu para executar as opções acima com esquema de repetição das opções e uma opção de saída. No programa principal, só pode haver a chamada do menu.
*/

#include <iostream>
using namespace std;

struct Contato{
    string Nome, Email, Telefone, Cidade, Estado;
    int Idade;
};


int Cadastrar(Contato A[], int Tam){
    cout << "Nome:[" << Tam << "]: ";
    cin >> A[Tam].Nome;
    cout << "E-mail[" << Tam << "]: ";
    cin >> A[Tam].Email;
    cout << "Telefone[" << Tam << "]: ";
    cin >> A[Tam].Telefone; 
    cout << "Cidade[" << Tam << "]: ";
    cin >> A[Tam].Cidade;
    cout << "Estado[" << Tam << "]: ";
    cin >> A[Tam].Estado;
    cout << "Idade[" << Tam << "]: ";
    cin >> A[Tam].Idade;
    
    Tam++;
    return Tam;
}

void Imprimir_Reg(Contato A[],int Pos, int Tipo){
    
    cout << "Nome[" << Pos << "]: " << A[Pos].Nome << endl;
    cout << "E-mail["<< Pos << "]: " << A[Pos].Email << endl;
    cout << "Telefone[" << Pos << "]: " << A[Pos].Telefone << endl;

    if (Tipo == 1){
        cout << "Cidade[" << Pos << "]: " << A[Pos].Cidade << endl;
        cout << "Estado[" << Pos << "]: " << A[Pos].Estado << endl;
        cout << "Idade[" << Pos << "]: " << A[Pos].Idade << endl;
    }
    
}

void Imprimir_Vetor(Contato A[], int Tam, int Tipo){
    int cont;
    
    for(cont=0;cont<Tam;cont++){
        Imprimir_Reg(A, cont, Tipo);
    }
    
}

void BuscaEstado(Contato A[], int Tam, string Estado){
    int cont;
    for (cont=0;cont<Tam;cont++){
        if(A[cont].Idade >= 18 && A[cont].Estado == Estado){
            Imprimir_Reg(A, cont, 1);
        }
    }
    
}

int BuscaMaisVelho(Contato A[], int Tam){
    int Maisvelho = 0, cont;

    for (cont = 1; cont<Tam; cont++){
        if (A[cont].Idade > A[Maisvelho].Idade){
            Maisvelho = cont;
        }
    }

    return Maisvelho;
    
}

void Menu(Contato A[]){
    int Op, Tam=0, OpImp, PosMaisVelho;
    string EstadoBusca;
    
    do{
        system("clear");
        cout << "[1] - Cadastrar" << endl;
        cout << "[2] - Imprimir" << endl;
        cout << "[3] - Busca por Estado" << endl;
        cout << "[4] - Mais velho" << endl;
        cout << "[5] - Sair" << endl;
        cout << "Opção: ";
        cin >> Op;

        // Processamento
        switch(Op){
            
            case 1:
                Tam = Cadastrar(A, Tam);
                break;
                case 2:
                cout << "[1] - Total" << endl;
                cout << "[2] - Parcial" << endl;
                cout << "Opção: ";
                cin >> OpImp;
                Imprimir_Vetor(A, Tam, OpImp);
                break;
                
                case 3:
                cout << "Qual Estado? (sigla):  ";
                cin >> EstadoBusca;
                BuscaEstado(A, Tam, EstadoBusca);
                break;
                
            case 4:
            PosMaisVelho = BuscaMaisVelho(A, Tam);
                Imprimir_Reg(A, PosMaisVelho, 1);
                break;

            case 5:
            break;

            default:
            cout << "Opção inválida." << endl;
        }
        
    }while(Op!=5);
}

Contato Agenda[10];

int main(){
    setlocale(LC_ALL, "Portuguese");
    
    Menu(Agenda);
    
    return 0;
}