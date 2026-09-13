#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

#define LINHAS 10
#define COLUNAS 10
struct Localizacao{
    char rua[50];
    int numero;
};
struct Evento{
    int id; // Gerado automaticamente
    char tipo[30]; // Dado pelo usuário
    char descricao[100]; // Dado pelo usuário
    int prioridade; // Definido pelo ADM
    int status; // Sempre nasce como 1
    Localizacao endereco; // Rua + Numero -> dado pelo usuário
    int locx, locy; // coordenada da matriz
    Evento *Prox;
};
struct Lista{
    Evento *Inicio;
};
struct Regiao{
    char ruas[4][50]; // N, S, L, O
    Lista *Eventos;
};

Regiao cidade[LINHAS][COLUNAS];
int proximo_id = 1; // contador global

// Reaproveitando as mesmas funçoes da atividade
// Bloco 1 - Estrutura e Lista básica

void Ini_Lista(Lista *L){ // Inicializa a lista vazia
    L->Inicio = NULL;
}

int Lista_Vazia(Lista *L){ // Verifica se a lista está vazia ou não
    int Ret = 1;

    if (L->Inicio != NULL){
        Ret = 0;
    }
    return Ret;
}

Lista * Criar_Lista(){
    Lista *L;

    L = (Lista*) malloc(sizeof(Lista));

    if (L != NULL){
        Ini_Lista(L);
    }
    return L;
}

void Liberar_Lista(Lista *L){
    Evento *Atual;
    Evento *Prox;

    Atual = L->Inicio;

    while(Atual != NULL){
        Prox = Atual->Prox;
        free(Atual);
        Atual = Prox;
    }

    L->Inicio = NULL;
}

// Bloco 2 - Evento

Evento* Criar_Evento(const char tipo[], const char descricao[], const char rua[], int numero, int locx, int locy){

    Evento *E;

    E = (Evento*) malloc(sizeof(Evento));

    if (E != NULL){

        E->id = proximo_id++; // gera o id incrementado
        strcpy(E->tipo, tipo);
        strcpy(E->descricao, descricao);
        E->prioridade = 0; // Padrao, depois o adm muda
        E->status = 1; // inicialmente 1 = nao resolvido
        strcpy(E->endereco.rua, rua);
        E->endereco.numero = numero;
        E->locx = locx;
        E->locy = locy;
        E->Prox = NULL;
    }

    return E;
}

void Inserir_Evento(Lista *L, Evento *Novo){

    if (Novo != NULL){
        Novo->Prox = L->Inicio;
        L->Inicio = Novo;
    }

}

Evento* Buscar_Evento(Lista *L, int id){

    Evento *Atual;

    Atual = L->Inicio;

    while (Atual != NULL){
        if(Atual->id == id){
            return Atual;
        }
        Atual = Atual->Prox;
    }

    return NULL;

}

void Remover_Evento(Lista *L, int id){

    Evento *Atual;
    Evento *Anterior;

    Atual = L->Inicio;
    Anterior = NULL;

    while(Atual != NULL && Atual->id != id){

        Anterior = Atual;
        Atual = Atual->Prox;

    }

    if (Atual == NULL){
        cout << "Evento com ID " << id << " não encontrado." << endl;
    }

    else{
        if (Anterior == NULL){
            L->Inicio = Atual->Prox; // Removendo o primeiro.
        }

        else{
            Anterior->Prox = Atual->Prox; // removendo no meio ou no final da lista.
        }
        free(Atual);
        cout << "Evento removido com sucesso." << endl;
    }
}

// Bloco 3 - Cidade (matriz)
void Inicializar_Cidade(){
    for(int i=0; i<LINHAS; i++){
        for(int j=0; j<COLUNAS; j++){
            cidade[i][j].Eventos = Criar_Lista();
            strcpy(cidade[i][j].ruas[0], ""); // Norte
            strcpy(cidade[i][j].ruas[1], ""); // Sul
            strcpy(cidade[i][j].ruas[2], ""); // Leste
            strcpy(cidade[i][j].ruas[3], ""); // Oeste
        }
    }
}

void Liberar_Cidade(){
    for(int i=0; i<LINHAS; i++){
        for(int j=0; j<COLUNAS; j++){
            Liberar_Lista(cidade[i][j].Eventos); // Libera os nós
            free(cidade[i][j].Eventos); // Libera a struct lista
            cidade[i][j].Eventos = NULL;
        }
    }
}

void Imprimir_Lista(Lista *L){
    
    Evento *Atual;

    Atual = L->Inicio;

    while (Atual != NULL){

        cout << "ID: " << Atual->id << endl;
        cout << "Tipo: " << Atual->tipo << endl;
        cout << "Gravidade: " << Atual->prioridade << endl;
        cout << "Status: " << Atual->status << endl;
        cout << "Rua: " << Atual->endereco.rua << endl;
        cout << "Número: " << Atual->endereco.numero << endl;
        cout << "Descrição: " << Atual->descricao << endl;

        Atual = Atual->Prox;
    }

}
// Bloco 4 - cadastros, etc.
void Cadastro_Civil(){
    int x, y, numero, escolha;
    char tipo[30], rua[50], descricao[100];

    cout << "Coordenada X (0-" << LINHAS-1 << "): ";
    cin >> x;

    cout << "Coordenada Y(0-" << COLUNAS-1 << "): ";
    cin >> y;

    if(x<0 || x>= LINHAS || y<0 || y>= COLUNAS){
        cout << "Coordenada inválida!" << endl;
        cin.get();
        return;
    }

    cout << "===== Tipo do Evento =====" << endl;
    cout << "[1] - Buraco" << endl;
    cout << "[2] - Lixo" << endl;
    cout << "[3] - Iluminação" << endl;
    cout << "[4] - Acidente" << endl;
    cout << "[5] - Outro" << endl;
    cin >> escolha;

    switch(escolha){

        case 1:
            strcpy(tipo, "Buraco");
            break;

        case 2:
            strcpy(tipo, "Lixo");
            break;
        case 3:
            strcpy(tipo, "Iluminação");
            break;

        case 4:
            strcpy(tipo, "Acidente");
            break;

        case 5:
            strcpy(tipo, "Outro");
            break;

        default:
            cout << "Opção inválida. Evento automaticamente classificado como 'Outro'." << endl;
            strcpy(tipo, "Outro");
            break;
    }

    cin.ignore();
    cout << "Rua: ";
    cin.getline(rua, 50);

    cout << "Número: ";
    cin >> numero;

    cin.ignore();
    cout << "Descrição: ";
    cin.getline(descricao, 100);

    Evento *Novo;
    Novo = Criar_Evento(tipo, descricao, rua, numero, x, y);

    if (Novo != NULL){
        Inserir_Evento(cidade[x][y].Eventos, Novo);
        cout << "Evento registrado com ID: " << Novo->id << endl;
    }
    else{
        cout << "Erro ao alocar memória." << endl;
    }
}

void Imprimir_Cidade(){
    int achou = 0;

    for(int i = 0; i<LINHAS; i++){
        for(int j = 0; j<COLUNAS; j++){
            if(!Lista_Vazia(cidade[i][j].Eventos)){
                achou = 1;
                cout << "===== Regiao [" << i << "][" << j << "] =====" << endl;
                Imprimir_Lista(cidade[i][j].Eventos);
                cout << endl; 
            }

        }
    }

    if (!achou){
        cout << "Nenhum evento cadastrado." << endl;
    }
}

Evento* Buscar_Evento_Na_Cidade(int id, int *x_out, int *y_out){
    Evento *E;
    for(int i = 0; i<LINHAS; i++){
        for(int j = 0; j<COLUNAS; j++){
            E = Buscar_Evento(cidade[i][j].Eventos, id);
            
            if (E!= NULL){
                *x_out = i;
                *y_out = j;

                return E;
            }
        }
    }

    return NULL;
}

void Menu(){
    int Op;

    do{
        system("clear");
        cout << "===== CIDADE INTELIGENTE =====" << endl;
        cout << "[1] - Cadastrar Evento" << endl;
        cout << "[2] - Imprimir Cidade" << endl;
        cout << "[0] - Sair" << endl;
        cout << "Opção: ";
        cin >> Op;
        cin.ignore();

        switch(Op){

            case 1:
                Cadastro_Civil();
                cout << "Pressione ENTER para continuar...";
                cin.get();
                break;

            case 2:
                Imprimir_Cidade();
                cout << "Pressione ENTER para continuar...";
                cin.get();
                break;

            case 0:
                cout << "Saindo..." << endl; 
                break;

            default:
                cout << "Opção inválida." << endl;
                cout << "Pressione ENTER para continuar...";
                cin.get();
        }

    }while(Op != 0);
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    Inicializar_Cidade();

    Menu();

    Liberar_Cidade();

    return 0;
}