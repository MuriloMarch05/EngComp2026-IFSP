/* Projeto Cidade Inteligente - Bilac SP */
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

// Tamanho da matriz de regioes (facil de trocar depois)
#define LINHAS  10
#define COLUNAS 10

// ESTRUTURAS
struct Localizacao{
    char rua[50];
    int numero;
};

struct Evento{
    int id;                 // Gerado automaticamente
    char tipo[30];          // Dado pelo usuario
    char descricao[100];    // Dado pelo usuario
    int prioridade;         // Definido pelo ADM
    int status;             // 1 = nao resolvido, 2 = resolvido
    Localizacao endereco;   // Rua e numero
    int locx, locy;         // Coordenada da matriz
    Evento *Prox;           // Ponteiro pro proximo nó
};

struct Lista{
    Evento *Inicio;         // Cabecalho da lista
};

struct Regiao{
    char ruas[4][50];       // N, S, L, O (opcional)
    Lista *Eventos;         // Ponteiro pra lista de eventos
};

// Globais
Regiao cidade[LINHAS][COLUNAS];  // Matriz de regioes
int proximo_id = 1;              // Contador global de IDs

// LISTA - funcoes basicas (copiei do professor valtemir)
void Ini_Lista(Lista *L){ // Inicializa a lista vazia
    L->Inicio = NULL;
}

int Lista_Vazia(Lista *L){ // 1 = vazia, 0 = tem elementos
    if (L->Inicio == NULL){
        return 1;
    }
    return 0;
}

Lista* Criar_Lista(){ // Aloca e inicializa uma lista
    Lista *L;
    L = (Lista*) malloc(sizeof(Lista));
    if (L != NULL){
        Ini_Lista(L);
    }
    return L;
}

void Liberar_Lista(Lista *L){ // Libera os nos da lista (nao a struct)
    Evento *Atual;
    Evento *Prox;

    Atual = L->Inicio;
    while (Atual != NULL){
        Prox = Atual->Prox; // Salva o proximo antes de liberar
        free(Atual);
        Atual = Prox;
    }
    L->Inicio = NULL;
}

// EVENTO - criar, inserir, buscar, remover, imprimir
Evento* Criar_Evento(const char tipo[], const char descricao[],
                     const char rua[], int numero, int locx, int locy)
{
    Evento *E;
    E = (Evento*) malloc(sizeof(Evento));

    if (E != NULL){
        E->id = proximo_id++;         // Gera id incrementado
        strcpy(E->tipo, tipo);
        strcpy(E->descricao, descricao);
        E->prioridade = 0;            // Padrao; ADM muda depois
        E->status = 1;                // Nasce nao resolvido
        strcpy(E->endereco.rua, rua);
        E->endereco.numero = numero;
        E->locx = locx;
        E->locy = locy;
        E->Prox = NULL;
    }
    return E;
}

void Inserir_Evento(Lista *L, Evento *Novo){ // Insere no inicio
    if (Novo != NULL){
        Novo->Prox = L->Inicio; // Novo aponta pro antigo inicio
        L->Inicio = Novo;       // Inicio aponta pro novo
    }
}

Evento* Buscar_Evento(Lista *L, int id){ // Busca por id numa lista
    Evento *Atual;
    Atual = L->Inicio;

    while (Atual != NULL){
        if (Atual->id == id){
            return Atual; // Achou, devolve ponteiro
        }
        Atual = Atual->Prox;
    }
    return NULL; // Nao achou
}

void Remover_Evento(Lista *L, int id){ // Remove por id
    Evento *Atual;
    Evento *Anterior;

    Atual = L->Inicio;
    Anterior = NULL;

    while (Atual != NULL && Atual->id != id){
        Anterior = Atual;
        Atual = Atual->Prox;
    }

    if (Atual == NULL){
        cout << "Evento com ID " << id << " nao encontrado." << endl;
    }
    else{
        if (Anterior == NULL){
            L->Inicio = Atual->Prox; // Removendo o primeiro
        }
        else{
            Anterior->Prox = Atual->Prox; // Removendo do meio/fim
        }
        free(Atual);
        cout << "Evento removido com sucesso." << endl;
    }
}

void Imprimir_Lista(Lista *L){ // Imprime os eventos de uma lista
    Evento *Atual;
    Atual = L->Inicio;

    while (Atual != NULL){
        cout << "  ID: " << Atual->id << endl;
        cout << "  Tipo: " << Atual->tipo << endl;
        cout << "  Prioridade: " << Atual->prioridade << endl;
        cout << "  Status: " << Atual->status << endl;
        cout << "  Rua: " << Atual->endereco.rua;
        cout << ", n " << Atual->endereco.numero << endl;
        cout << "  Descricao: " << Atual->descricao << endl;
        cout << "  -----" << endl;
        Atual = Atual->Prox;
    }
}

// Inicializar a matriz da cidade
void Inicializar_Cidade(){
    for (int i = 0; i < LINHAS; i++){
        for (int j = 0; j < COLUNAS; j++){
            cidade[i][j].Eventos = Criar_Lista(); // Cria lista de cada regiao
            strcpy(cidade[i][j].ruas[0], "");
            strcpy(cidade[i][j].ruas[1], "");
            strcpy(cidade[i][j].ruas[2], "");
            strcpy(cidade[i][j].ruas[3], "");
        }
    }
}

void Liberar_Cidade(){
    for (int i = 0; i < LINHAS; i++){
        for (int j = 0; j < COLUNAS; j++){
            Liberar_Lista(cidade[i][j].Eventos); // Libera os nos
            free(cidade[i][j].Eventos); // Libera a struct lista
            cidade[i][j].Eventos = NULL; // Evita vazar memória
        }
    }
}

// Cadastro do usuario
void Cadastro_Civil(){
    int x, y, numero, escolha;
    char tipo[30], rua[50], descricao[100];

    cout << "Coordenada X (0-" << LINHAS-1 << "): ";
    cin >> x;
    cout << "Coordenada Y (0-" << COLUNAS-1 << "): ";
    cin >> y;

    if (x < 0 || x >= LINHAS || y < 0 || y >= COLUNAS){
        cout << "Coordenada invalida!" << endl;
        return;
    }

    cout << "===== Tipo do Evento =====" << endl;
    cout << "[1] Buraco" << endl;
    cout << "[2] Lixo" << endl;
    cout << "[3] Iluminacao" << endl;
    cout << "[4] Acidente" << endl;
    cout << "[5] Outro" << endl;
    cout << "Opcao: ";
    cin >> escolha;

    switch(escolha){
        case 1: 
            strcpy(tipo, "Buraco");     
            break;
        case 2: 
            strcpy(tipo, "Lixo");       
            break;
        case 3: 
            strcpy(tipo, "Iluminacao"); 
            break;
        case 4: 
            strcpy(tipo, "Acidente");   
            break;
        case 5: 
            strcpy(tipo, "Outro");     
             break;
        default: 
            strcpy(tipo, "Outro");    
             break;
    }

    cin.ignore(); // Limpa \n do cin >> escolha
    cout << "Rua: ";
    cin.getline(rua, 50);

    cout << "Numero: ";
    cin >> numero;

    cin.ignore(); // Limpa \n do cin >> numero
    cout << "Descricao: ";
    cin.getline(descricao, 100);

    Evento *Novo = Criar_Evento(tipo, descricao, rua, numero, x, y);

    if (Novo != NULL){
        Inserir_Evento(cidade[x][y].Eventos, Novo);
        cout << "Evento registrado com ID " << Novo->id << endl;
    }
    else{
        cout << "Erro ao alocar memoria." << endl;
    }
}

// Imprime a cidade inteira
void Imprimir_Cidade(){
    int achou = 0;

    for (int i = 0; i < LINHAS; i++){
        for (int j = 0; j < COLUNAS; j++){
            if (!Lista_Vazia(cidade[i][j].Eventos)){
                achou = 1;
                cout << "===== Regiao [" << i << "][" << j << "] =====" << endl;
                Imprimir_Lista(cidade[i][j].Eventos);
            }
        }
    }

    if (!achou){
        cout << "Nenhum evento cadastrado." << endl;
    }
}

// Busca na cidade inteira por ID
// Devolve o ponteiro do evento E escreve a regiao em *x_out e *y_out
Evento* Buscar_Evento_Na_Cidade(int id, int *x_out, int *y_out){
    for (int i = 0; i < LINHAS; i++){
        for (int j = 0; j < COLUNAS; j++){
            Evento *E = Buscar_Evento(cidade[i][j].Eventos, id);
            if (E != NULL){
                *x_out = i; // Escreve a regiao nos ponteiros de saida
                *y_out = j;
                return E;
            }
        }
    }
    return NULL;
}

// Funcoes adm
void Tratar_Evento(){ // Altera status e prioridade de um evento
    int id, x, y;
    cout << "ID do evento: ";
    cin >> id;

    Evento *E;
    E = Buscar_Evento_Na_Cidade(id, &x, &y);
    if (E == NULL){
        cout << "Evento nao encontrado." << endl;
        return;
    }

    cout << "Evento na regiao [" << x << "][" << y << "]" << endl;
    cout << "Descricao: " << E->descricao << endl;
    cout << "Status atual: " << E->status << endl;
    cout << "Prioridade atual: " << E->prioridade << endl;

    cout << "Novo status (1=nao resolvido, 2=resolvido): ";
    cin >> E->status; // Altera direto no nó

    cout << "Nova prioridade (0-5): ";
    cin >> E->prioridade;

    cout << "Evento atualizado." << endl;
}

void Remover_Evento_Menu(){ // Remove com confirmacao
    int id, x, y, conf;
    cout << "ID do evento a remover: ";
    cin >> id;

    Evento *E;
    E = Buscar_Evento_Na_Cidade(id, &x, &y);
    if (E == NULL){
        cout << "Evento nao encontrado." << endl;
        return;
    }

    cout << "Evento: " << E->descricao;
    cout << " (regiao [" << x << "][" << y << "])" << endl;
    cout << "Confirma remocao? (1=sim, 0=nao): ";
    cin >> conf;

    if (conf == 1){
        Remover_Evento(cidade[x][y].Eventos, id); // Passa a lista certa
    } else {
        cout << "Remocao cancelada." << endl;
    }
}

bool AutenticarADM(){ // Verifica senha do ADM
    char Codigo[20];
    cout << "Digite o codigo de acesso ADM: ";
    cin.getline(Codigo, 20);
    return (strcmp(Codigo, "ADMIN2") == 0);
}

void MenuADM(){ // Submenu do administrador
    int Op;
    do {
        system("clear");
        cout << "===== MENU ADMINISTRADOR =====" << endl;
        cout << "[1] Tratar evento" << endl;
        cout << "[2] Remover evento" << endl;
        cout << "[3] Imprimir cidade" << endl;
        cout << "[0] Voltar" << endl;
        cout << "Opcao: ";
        cin >> Op;
        cin.ignore();

        switch(Op){
            case 1:
                Tratar_Evento();
                cin.ignore(); // Limpa \n do cin >> id
                cout << "Pressione ENTER...";
                cin.get();
                break;
            case 2:
                Remover_Evento_Menu();
                cin.ignore();
                cout << "Pressione ENTER...";
                cin.get();
                break;
            case 3:
                Imprimir_Cidade();
                cout << "Pressione ENTER...";
                cin.get();
                break;
            case 0:
                break;
            default:
                cout << "Opcao invalida!" << endl;
                cout << "Pressione ENTER...";
                cin.get();
        }
    } while (Op != 0);
}

void Menu(){
    int Op;
    do {
        system("clear");
        cout << "===== CIDADE INTELIGENTE =====" << endl;
        cout << "[1] Cadastrar Evento" << endl;
        cout << "[2] Imprimir Cidade" << endl;
        cout << "[3] Acesso Administrador" << endl;
        cout << "[0] Sair" << endl;
        cout << "Opcao: ";
        cin >> Op;
        cin.ignore(); // Limpa \n do cin >> Op

        switch(Op){
            case 1:
                Cadastro_Civil();
                cout << "Pressione ENTER...";
                cin.get();
                break;
            case 2:
                Imprimir_Cidade();
                cout << "Pressione ENTER...";
                cin.get();
                break;
            case 3:
                if (AutenticarADM()){
                    MenuADM();
                } else {
                    cout << "Acesso negado!" << endl;
                    cout << "Pressione ENTER...";
                    cin.get();
                }
                break;
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida!" << endl;
                cout << "Pressione ENTER...";
                cin.get();
        }
    } while (Op != 0);
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    Inicializar_Cidade(); // Cria as 100 listas (uma por regiao)
    Menu();              
    Liberar_Cidade();// Libera tudo no final

    return 0;
}