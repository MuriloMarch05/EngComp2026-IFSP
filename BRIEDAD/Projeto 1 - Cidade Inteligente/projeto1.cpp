/*Projeto cidade limpa - Bilac SP*/
#include <iostream>
#include <string.h>
using namespace std;

struct Evento{
    int locx = -1;
    int locy = -1;
    int status = 0;
    int gravidade = 0;
    string Descricao = "0";
}Eventos[100];

struct Usuario{
    string nome, login, senha;
    int tipo; // 1 - Civil, 2 - Administrador
}Usuarios[100];

struct PontoCidade {
    int X, Y;
    string Rua, Bairro;
};

void CadastroCivil(Evento E[], int tam){
    cout<<"\nCoordenada X["<<tam<<"]: ";
    cin>>E[tam].locx;
    cout<<"\nCoordenada Y["<<tam<<"]: ";
    cin>>E[tam].locy;
    cout<<"\nDescrição["<<tam<<"]: ";
    cin>>E[tam].Descricao;

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
void CadastroADM(Evento E[], int tam){
    if(E[tam].status!=0){
        cout<<"\nStatus["<<tam<<"]: ";
        cin>>E[tam].status;
        cout<<"\nGravidade["<<tam<<"]: ";
        cin>>E[tam].gravidade;
    }
    else{
        cout<<"\nNão há dados suficientes para avaliação\n";
    }
} 

int Cadastro(Evento E[], int tam){
    int tipo;
    tipo = Registro();
    if(tipo==1){
        CadastroCivil(E, tam);
        /* A pessoa preenche todos os campos menos 
 Status e a Gravidade, que são setados por padrão como 0*/    
    }
    else{
        CadastroADM(E, tam);
    }
    tam++;
    return tam;
}

void Imprimir(Evento E[], int tam){
    cout<< "impressão"<<endl; /*será finalizada depois da conclusão das funções de cadastro*/
    
    cout<<"Descrisão do evento: "<< "\n" << E[tam].Descricao << endl;
}

// Uma dúvida breno, não era mais fácil filtrar o que aparece para civil/admin 
// direto no menu? ao invés de ter funções para cada um

void Menu(Evento E[], int tipoUsuario){
    int Op, tam=0;
    do{
        system("cls");
        cout<<"[1] - Registro\n[2] - Impressão\n[3] - Sair\n";
        cin>>Op;
        switch(Op){
            case 1: tam = Cadastro(E, tam);
                    break;
            case 2: Imprimir(E, tam);
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
    Menu(E);
    return 0;
}



