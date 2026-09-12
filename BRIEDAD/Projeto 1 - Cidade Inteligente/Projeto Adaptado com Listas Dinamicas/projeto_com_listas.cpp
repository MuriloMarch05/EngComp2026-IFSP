/*Projeto cidade limpa - Bilac SP

main
 └─ inicializarCidade(Regiao cidade[][COLUNAS])
     └─ pra cada [i][j]:
         - criar Lista de eventos (Criar_Lista)
         - configurar ruas (opcional)
 └─ Menu(cidade)

Menu
 ├─ CadastroCivil  → pede coord + dados → adicionarEvento(cidade[x][y], ...)
 ├─ MenuADM        → autentica → trata evento
 ├─ Imprimir       → percorre matriz → imprime listas
 └─ Sair

Funções de lista (reaproveitadas do exercício):
 - Ini_Lista, Lista_Vazia, Criar_Lista, Liberar_Lista
 - Criar_Evento, Inserir_Evento, Remover_Evento
 - Imprimir_Lista, Comprimento_Lista, Buscar_Evento
 - Ordenar_Lista (BubbleSort trocando conteúdo)

Funções de cidade:
 - inicializarCidade, configurarRegiao, exibirMapa
 - adicionarEvento (chama Inserir_Evento na região certa)
 - buscarEventoPorId (percorre regiões e listas)
 - contarEventosNaRegiao
 - identificarRegiaoMaisCritica
 
 */
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
    int tipo; // Dado pelo usuário
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

int Comprimento_Lista(Lista *L){
    Evento *Atual;
    int cont=0;

    Atual = L->Inicio;

    while (Atual != NULL){
        cont++;
        Atual = Atual->Prox;
    }

    return cont;
}

// Bloco 2 - Evento

Evento* Criar_Evento(int tipo, char descricao[], char rua[], int numero, int locx, int locy){

    Evento *E;

    E = (Evento*) malloc(sizeof(Evento));

    if (E != NULL){

        E->id = proximo_id++; // gera o id incrementado
        E->tipo = tipo;
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

int main(){
    setlocale(LC_ALL, "Portuguese");

    Lista *L;
    L = Criar_Lista();

    cout << Lista_Vazia(L) << endl;
    cout << Comprimento_Lista(L) << endl;

    Liberar_Lista(L);
    free(L);

    return 0;
}