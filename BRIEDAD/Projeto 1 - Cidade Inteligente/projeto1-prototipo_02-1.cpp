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
    char Descricao[75] = "0";
}Eventos[100];

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
    for(int i=0; i<tam-1; i++){
        troca=false;
        for(int j=0; j<tam-i-1; j++){   // corrigido: j++
            if(Eventos[j].gravidade < Eventos[j+1].gravidade){ // Mudei aqui para ordem decrescente, pq não faz sentido listar do menor pro maior. - Murilo
                swap(Eventos[j], Eventos[j+1]);
                troca=true;
            }
        }
        if(!troca) break; // otimização: se não trocou nada, já está ordenado
    }
}

void CadastroCivil(Evento E[], int &tam, char C[][3]){
    do{
        cout<<"\nCoordenada X["<<tam<<"] (0-2): ";
        cin>>E[tam].locx;
        cout<<"\nCoordenada Y["<<tam<<"] (0-2): ";
        cin>>E[tam].locy;
        cin.ignore();
        if(E[tam].locx < 0 || E[tam].locx > 2 || E[tam].locy < 0 || E[tam].locy > 2){
            cout<<"\nCoordenadas inválidas, digite outra\n";
        }
    }while(E[tam].locx < 0 || E[tam].locx > 2 || E[tam].locy < 0 || E[tam].locy > 2);
    cout<<"\nEvento adicionado ao bloco "<<C[E[tam].locx][E[tam].locy];
    cout<<"\nDescrição["<<tam<<"]: ";
    cin.getline(E[tam].Descricao, 75);
    cin.ignore();
    tam++;

}
void Imprimir(Evento E[], int tam, char C[][3]){
    int Cont;
    if (tam==0){ // Se não tiver nada preenchido, não executa nada.
        cout << "Não há nada para mostrar.";
    }
    else{
    cout<<"Eventos organizados em ordem decrescente de gravidade:\n"; // Arrumei aqui, para não ficar repetindo dentro do for. - Murilo
    for(Cont=0;Cont<tam;Cont++){
        if(strcmp(E[Cont].Descricao, "0")!=0){
            cout << "---------------------------------" << endl; // Coloquei uma separação, só pra ficar melhor para ver.
            cout<<"Localização ["<<Cont<<"]: Bloco "<<C[E[Cont].locx][E[Cont].locy]<<endl;
            cout<<"Status ["<<Cont<<"]: "<<E[Cont].status<<endl;
            cout<<"Gravidade ["<<Cont<<"]: "<<E[Cont].gravidade<<endl;
            cout<<"Descrição ["<<Cont<<"]: "<<E[Cont].Descricao<<endl;
        }
    }
    }
}

void CadastroADM(Evento E[], int tam, char C[][3]){
    int Pos;
    cout<<"\nDigite o número do evento que deseja tratar\n";
    cin>>Pos;
    if(Pos >= 0 && Pos<tam && strcmp(E[Pos].Descricao, "0")!=0){ // Fiz uma condição pra garantir que o evento esteja no intervalo certo. Sem ser negativo ou maior do que o tam.
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

bool AutenticarADM(){ // Adicionei a opcao do ADM, só quando a pessoa selecionar esse acesso e digitar o código correto, aparece o MENU separado. - Murilo
    char Codigo[20];
    cout<<"\nDigite o código de acesso ADM: ";
    cin.getline(Codigo, 20);
    return (strcmp(Codigo, "ADMIN2")==0); // Se digitar exatamente isso, retorna 1 (verdadeiro). Se não, 0 (falso). - Murilo
}

void MenuADM(Evento E[], int &tam, char C[][3]){ // Menu específico para administradores. - Murilo
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
            case 1: CadastroADM(E, tam, C);
                    BubbleSort(tam);   // Só ordena depois que a gravidade muda
                    cin.ignore(); cin.get();
                    break;
            case 2: Imprimir(E, tam, C);
                    cin.ignore(); cin.get();
                    break;
            case 3: break;

            default: cout<<"Opção inválida!\n";
                    cin.ignore(); cin.get();
        }
    } while(Op!=3);
}

void Menu(Evento E[]){
    char Cidade[3][3]={{'A','B','C'},{'D','E','F'},{'G','H','I'}};
    int Op, tam=0;
    do{
        system("clear");
        cout << "=== CIDADE INTELIGENTE - BILAC ===" << endl;
        cout<<"[1] - Registro Civil\n[2] - Acesso Administrador\n[3] - Impressão\n[4] - Sair\n";
        cout << "Opção: ";
        cin>>Op;
        cin.ignore();
        switch(Op){
            case 1: CadastroCivil(E, tam, Cidade);
                    break;
            case 2: if(AutenticarADM()){
                        MenuADM(E, tam, Cidade);
                    } else {
                        cout<<"\nAcesso negado!\n";
                    }
                    break;
            case 3: Imprimir(E, tam, Cidade);
                    cin.ignore(); cin.get();
                    break;

            case 4: break;

            default: cout<<"Opção inválida!\n";
            cin.ignore(); cin.get();
        }
    } while(Op!=4);
}

// Zerar(E);Programa principal
int main(){
    setlocale(LC_ALL, "Portuguese");
    Menu(Eventos);
    return 0;
}
