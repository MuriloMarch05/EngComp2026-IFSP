/*Projeto cidade limpa - Bilac SP*/
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;

struct Evento{
    int locx = 0;
    int locy = 0;
    int status = 0;
    int gravidade = 0;
    int ordem = 0;
    char Descricao[75] = "0";
    Evento *prox;
};

typedef Evento eventos;

eventos* Inicializar_Lista(eventos *E){//Inicialização com uma cabeça de conteúdo irrelevante (iterações partem de seu campo prox)
    E=(eventos*)malloc(sizeof(eventos));
    E->prox=NULL;
    return E;
}

int Atribuir_Ordem(eventos *E){
    eventos *p;
    int i=1;
    for(p=E->prox;p!=NULL;p=p->prox){
        p->ordem=i;
        i++;
    }
    return i;
}
void ResolverProb(eventos *E, int Pos){
    int Res;
    eventos *p;
    p=E->prox;
    while(p->prox!=NULL && p->ordem!=Pos){
        p=p->prox;
    }
    cout<<"Resolver problema?\n[1] - Sim\n[2] - Não\n";
    cin>>Res;
    if(Res==1){
        p->status=2;
    }
}

void CadastroCivil(eventos* E, char C[][3]){
    if(E!=NULL){
        eventos *novo;
        novo=(eventos*)malloc(sizeof(eventos));
        do{
            cout<<"\nCoordenada X do evento cadastrado (0-2): ";
            cin>>novo->locx;
            cout<<"\nCoordenada Y do evento cadastrado (0-2): ";
            cin>>novo->locy;
            cin.ignore();
            if(novo->locx < 0 || novo->locx > 2 || novo->locy < 0 || novo->locy > 2){
                cout<<"\nCoordenadas inválidas, digite outra\n";
            }
        }while(novo->locx < 0 || novo->locx > 2 || novo->locy < 0 || novo->locy > 2);
        cout<<"\nEvento adicionado ao bloco "<<C[novo->locx][novo->locy];
        cout<<"\nDescrição: ";
        cin.getline(novo->Descricao, 75);
        cin.ignore();
        novo->prox=E->prox;
        E->prox=novo;
    }
    
}
void Imprimir(eventos* E, char C[][3]){
    eventos *p;
    if (E->prox==NULL){ // Se não tiver nada preenchido, não executa nada.
        cout << "Não há nada para mostrar.";
    }
    else{
    cout<<"Eventos organizados em ordem decrescente de gravidade:\n"; // Arrumei aqui, para não ficar repetindo dentro do for. - Murilo
    for(p=E->prox;p!=NULL;p=p->prox){
        if(strcmp(p->Descricao, "0")!=0){
            cout << "---------------------------------" << endl; // Coloquei uma separação, só pra ficar melhor para ver.
            cout<<"Localização: Bloco "<<C[p->locx][p->locy]<<endl;
            cout<<"Status: "<<p->status<<endl;
            cout<<"Gravidade: "<<p->gravidade<<endl;
            cout<<"Descrição "<<p->Descricao<<endl;
        }
    }
    }
}

void CadastroADM(eventos *E, char C[][3]){
    int Pos, max;
    max=Atribuir_Ordem(E);//Recebe o valor do maior inteiro delegado à ordenação de uma célula da lista que não sua cabeça para posterior comparação
    eventos *p;
    cout<<"\nDigite o número do evento que deseja tratar\n";
    cin>>Pos;
    p=E->prox;
    while(p->prox!=NULL && p->ordem!=Pos){
        p=p->prox;
    }
    if(Pos>=1 && strcmp(p->Descricao, "0")!=0 && Pos<=max){ // Fiz uma condição pra garantir que o evento esteja no intervalo certo. Sem ser negativo ou maior do que o tam.
        cout<<"\nEvento localizado em "<<C[p->locx][p->locy]<<endl;
        cout<<"\nStatus (1 para não resolvido e 2 para resolvido): ";
        cin>>p->status;
        if(p->status==1){
            ResolverProb(E, Pos);
        }
        cout<<"\nGravidade: ";
        cin>>p->gravidade;
    }
    else{
        cout<<"\nNão há dados suficientes para avaliação\n";
    }
}


bool AutenticarADM(){ // Adicionei a opcao do ADM, só quando a pessoa selecionar esse acesso e digitar o código correto, aparece o MENU separado. - Murilo
    char Codigo[20];
    cout<<"\nDigite o código de acesso ADM: ";
    cin.getline(Codigo, 20);
    return (strcmp(Codigo, "ADMIN2")==0); // Se digitar exatamente isso, retorna 1 (verdadeiro). Se não, 0 (falso). - Murilo
}

void MenuADM(eventos *E, char C[][3]){ // Menu específico para administradores. - Murilo
    int Op;
    do{
        system("clear"); // Aqui tá clear pq eu tava testando no terminal do Linux.
        cout<<"\n== MENU ADMINISTRADOR ==\n";
        cout<<"[1] - Tratar evento (status/gravidade)\n";
        cout<<"[2] - Imprimir eventos\n";
        cout<<"[3] - Voltar ao menu principal\n";
        cout << "Opção: ";
        cin>>Op;
        switch(Op){
            case 1: CadastroADM(E, C);// Só ordena depois que a gravidade muda
                    cin.ignore(); cin.get();
                    break;
            case 2: Imprimir(E, C);
                    cin.ignore(); cin.get();
                    break;
            case 3: break;

            default: cout<<"Opção inválida!\n";
                    cin.ignore(); cin.get();
        }
    } while(Op!=3);
}

void Menu(eventos* E){
    char Cidade[3][3]={{'A','B','C'},{'D','E','F'},{'G','H','I'}};
    int Op;
    do{
        system("clear");
        cout << "=== CIDADE INTELIGENTE - BILAC ===" << endl;
        cout<<"[1] - Registro Civil\n[2] - Acesso Administrador\n[3] - Impressão\n[4] - Sair\n";
        cout << "Opção: ";
        cin>>Op;
        cin.ignore();
        switch(Op){
            case 1: CadastroCivil(E, Cidade);
                    break;
            case 2: if(AutenticarADM()){
                        MenuADM(E, Cidade);
                    } else {
                        cout<<"\nAcesso negado!\n";
                    }
                    break;
            case 3: Imprimir(E, Cidade);
                    cin.ignore(); cin.get();
                    break;

            case 4: 
                    break;
            default: cout<<"Opção inválida!\n";
            cin.ignore(); cin.get();
        }
    } while(Op!=4);
}

// Zerar(E);Programa principal
int main(){
    eventos* Eventos;
    Eventos=Inicializar_Lista(Eventos);
    setlocale(LC_ALL, "Portuguese");
    Menu(Eventos);
    return 0;
}
