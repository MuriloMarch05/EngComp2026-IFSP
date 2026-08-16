/*Projeto cidade limpa - Bilac SP*/
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

struct Evento{
    int locx = 0;
    int locy = 0;
    int status = 0;
    int gravidade = 0;
    string Descricao = "0";
}Eventos[100];

struct Usuario{
    string nome, login, senha;
    int tipo; // 1 - Civil, 2 - Administrador
}Usuarios[100];

struct Cidade {
    int X, Y;
    string Rua, Bairro;
};
void ResolverProb(int Pos){
    int Res;
    cout<<"Resolver problema?\n[1] - Sim\n[2] - Não\n";
    cin>>Res;
    if(Res==1){
        Eventos[Pos].status=2;
    }
}
void BubbleSort(int tam){
    bool troca;
    for(int i=0;i<tam-1;i++){
        troca=false;
        for(int j=0;j<tam-i-1;i++){
            if(Eventos[j].gravidade>Eventos[j+1].gravidade){
                swap(Eventos[j], Eventos[j+1]);
                troca=true;
            }
        }
    }
    
}
void CadastroCivil(Evento E[], int tam, char C[][3]){
    cout<<"\nCoordenada X["<<tam<<"]: ";
    cin>>E[tam].locx;
    cout<<"\nCoordenada Y["<<tam<<"]: ";
    cin>>E[tam].locy;
    cin.ignore();
    cout<<"\nEvento adicionado ao bloco "<<C[E[tam].locx][E[tam].locy];
    cout<<"\nDescrição["<<tam<<"]: ";
    getline(cin, E[tam].Descricao);

}

void Imprimir(Evento E[], int tam, char C[][3]){
    int Cont;
    for(Cont=0;Cont<tam;Cont++){
        if(E[Cont].Descricao!="0"){
            cout<<"Eventos organizados em ordem crescente de gravidade e\n";
            cout<<"Localização ["<<Cont<<"]: Bloco "<<C[E[Cont].locx][E[Cont].locy]<<endl;
            cout<<"Status ["<<Cont<<"]: "<<E[Cont].status<<endl;
            cout<<"Gravidade ["<<Cont<<"]: "<<E[Cont].gravidade<<endl;
            cout<<"Descrição ["<<Cont<<"]: "<<E[Cont].Descricao<<endl;
        }
    }
}

int Registro(){
    string Codigo;
    cout<<"\nDigite um código de acesso\n";
    cin>>Codigo;
    system("cls");
    if(Codigo=="ADMIN2"){
        cout<<"Você ganhou acesso de ADM\n";
        return 2;
    }
    else{
        cout<<"Você ganhou acesso de civil\n";
        return 1;
    }
    system("cls");
}
void CadastroADM(Evento E[], int tam, char C[][3]){
    int Pos;
    cout<<"\nDigite o número do evento que deseja tratar\n";
    cin>>Pos;
    if(E[Pos].Descricao!="0" && Pos<=tam){
        cout<<"\nEvento localizado em "<<C[E[Pos].locx][E[Pos].locy]<<endl;
        cout<<"\nStatus (1 para não resolvido e 2 para resolvido) ["<<Pos<<"]: ";
        cin>>E[Pos].status;
        if(E[Pos].status==1){
            ResolverProb(Pos);
        }
        cout<<"\nGravidade["<<Pos<<"]: ";
        cin>>E[Pos].gravidade;
    }
    else{
        cout<<"\nNão há dados suficientes para avaliação\n";
    }
} 

int Cadastro(Evento E[], int tam, char C[][3]){
    int tipo;
    tipo = Registro();
    if(tipo==1){
        CadastroCivil(E, tam, C);
        /* A pessoa preenche todos os campos menos 
 Status e a Gravidade, que são setados por padrão como 0*/    
    }
    else{
        CadastroADM(E, tam, C);
        tam++;
    }
    BubbleSort(tam);
    return tam;
}


// Uma dúvida breno, não era mais fácil filtrar o que aparece para civil/admin 
// direto no menu? ao invés de ter funções para cada um

void Menu(Evento E[]){
    char Cidade[3][3]={{'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'F', 'H'}};
    int Op, tam=0;
    do{
        system("cls");
        cout<<"[1] - Registro\n[2] - Impressão\n[3] - Sair\n";
        cin>>Op;
        switch(Op){
            case 1: tam = Cadastro(E, tam, Cidade);
                    break;
            case 2: Imprimir(E, tam, Cidade);
                    break;
            case 3: 
                    break;
            default: cout<<"Opção inválida!\n";
        }
        system("pause");
    }while(Op!=3);
}

// Zerar(E);Programa principal
int main(){
    setlocale(LC_ALL, "Portuguese");
    Menu(Eventos);
    return 0;
}



