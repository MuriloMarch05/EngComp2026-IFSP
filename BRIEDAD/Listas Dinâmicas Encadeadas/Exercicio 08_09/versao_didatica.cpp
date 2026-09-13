#include <iostream>
#include <stdlib.h>
#include <clocale>

using namespace std;


/*
=========================================================
ESTRUTURA DO ITEM (NÓ)
=========================================================

Cada elemento da nossa lista será um "Item".

Um Item possui duas coisas:

1. Valor -> guarda o número inteiro.
2. Prox  -> guarda o endereço do próximo Item.

Exemplo:

    10        20        30
   +---+     +---+     +---+
   |10 | --> |20 | --> |30 | --> NULL
   +---+     +---+     +---+
    Valor     Valor     Valor
     Prox      Prox      Prox
*/
struct Item{
    int Valor;
    Item *Prox;
};


/*
=========================================================
ESTRUTURA DA LISTA
=========================================================

A estrutura Lista possui apenas um ponteiro:

Inicio

Esse ponteiro guarda o endereço do primeiro Item.

Exemplo:

    Inicio
       |
       v
      10        20        30
     +---+     +---+     +---+
     |10 | --> |20 | --> |30 | --> NULL
     +---+     +---+     +---+

Se a lista estiver vazia:

    Inicio
       |
       v
      NULL
*/
struct Lista{
    Item *Inicio;
};


/*
=========================================================
FUNÇÃO: Ini_Lista
=========================================================

Inicializa uma lista.

Quando criamos uma lista nova, ainda não existe nenhum
Item nela.

Por isso, Inicio deve apontar para NULL.

Recebemos:

Lista *L

L é um ponteiro para uma estrutura Lista.

Por isso usamos:

L->Inicio

O "->" significa:

"acesse o campo Inicio da Lista apontada por L".
*/
void Ini_Lista(Lista *L){

    L->Inicio = NULL;
}


/*
=========================================================
FUNÇÃO: Lista_Vazia
=========================================================

Verifica se uma lista está vazia.

Retorno:

1 -> lista vazia
0 -> lista possui elementos
*/
int Lista_Vazia(Lista *L){

    int Ret = 1;

    /*
    Se Inicio NÃO for NULL, significa que existe
    pelo menos um Item na lista.
    */
    if(L->Inicio != NULL){
        Ret = 0;
    }

    return Ret;
}


/*
=========================================================
FUNÇÃO: Criar_Lista
=========================================================

Reserva memória para uma nova estrutura Lista.

malloc() reserva espaço na memória.

Depois chamamos Ini_Lista() para deixar a lista vazia.
*/
Lista* Criar_Lista(){

    Lista *L;

    /*
    Reserva memória suficiente para uma estrutura Lista.
    */
    L = (Lista *) malloc(sizeof(Lista));

    /*
    Se a memória foi reservada com sucesso,
    inicializamos a lista.
    */
    if(L != NULL){
        Ini_Lista(L);
    }

    return L;
}


/*
=========================================================
FUNÇÃO: Criar_Item
=========================================================

Cria um novo nó da lista.

Recebe um número inteiro e coloca esse número no campo
Valor do novo Item.

O campo Prox começa apontando para NULL.
*/
Item* Criar_Item(int Valor){

    Item *Elemento;

    /*
    Reserva memória para um novo Item.
    */
    Elemento = (Item *) malloc(sizeof(Item));

    /*
    Verifica se a memória foi reservada.
    */
    if(Elemento != NULL){

        /*
        Coloca o valor recebido no novo Item.
        */
        Elemento->Valor = Valor;

        /*
        Como ainda não sabemos qual será o próximo Item,
        inicialmente Prox aponta para NULL.
        */
        Elemento->Prox = NULL;
    }

    return Elemento;
}


/*
=========================================================
FUNÇÃO: Inserir_Item
=========================================================

Insere um novo número no INÍCIO da lista.

Como a lista NÃO é ordenada, não precisamos procurar
uma posição específica.

Exemplo:

Lista antes:

    Inicio
       |
       v
      20 -> 10 -> 5 -> NULL

Inserindo 30:

    Inicio
       |
       v
      30 -> 20 -> 10 -> 5 -> NULL


PASSO 1:

Criamos o novo Item:

    Novo
     |
     v
    30 -> NULL


PASSO 2:

Fazemos Novo->Prox apontar para o antigo Inicio:

    Novo
     |
     v
    30 -----> 20 -> 10 -> 5 -> NULL
               ^
               |
             Inicio


PASSO 3:

Fazemos Inicio apontar para Novo:

    Inicio
       |
       v
      30 -> 20 -> 10 -> 5 -> NULL
*/
void Inserir_Item(Lista *L, int Valor){

    Item *Novo;

    /*
    Cria um novo Item contendo o valor recebido.
    */
    Novo = Criar_Item(Valor);

    /*
    Verifica se conseguimos criar o Item.
    */
    if(Novo != NULL){

        /*
        O próximo do novo Item será o atual primeiro Item.
        */
        Novo->Prox = L->Inicio;

        /*
        Agora o novo Item passa a ser o primeiro da lista.
        */
        L->Inicio = Novo;
    }
}


/*
=========================================================
FUNÇÃO: Remover_Item
=========================================================

Remove a PRIMEIRA ocorrência de um determinado valor.

Precisamos de dois ponteiros:

Atual:
    indica o Item que estamos analisando.

Anterior:
    indica o Item que vem antes do Atual.

Exemplo:

10 -> 20 -> 30 -> 40 -> NULL
          ^      ^
       Anterior Atual

Se queremos remover 30:

Anterior->Prox deverá passar a apontar para 40.

Resultado:

10 -> 20 -> 40 -> NULL


CASO ESPECIAL:

Se o elemento a remover estiver no início:

10 -> 20 -> 30
^

Nesse caso não existe "Anterior".

Então precisamos simplesmente fazer:

L->Inicio = Atual->Prox;
*/
void Remover_Item(Lista *L, int Valor){

    Item *Atual;
    Item *Anterior;

    /*
    Começamos pelo primeiro Item.
    */
    Atual = L->Inicio;

    /*
    No início não existe Item anterior.
    Por isso Anterior começa como NULL.
    */
    Anterior = NULL;


    /*
    Continuamos procurando enquanto:

    1. Atual não for NULL
    2. O valor de Atual não for o valor procurado
    */
    while(Atual != NULL && Atual->Valor != Valor){

        /*
        Antes de avançar Atual, guardamos seu endereço
        em Anterior.
        */
        Anterior = Atual;

        /*
        Avançamos para o próximo Item.
        */
        Atual = Atual->Prox;
    }


    /*
    Se Atual chegou em NULL, significa que percorremos
    a lista inteira e não encontramos o valor.
    */
    if(Atual == NULL){

        cout << "Valor nao encontrado!" << endl;
    }

    else{

        /*
        Se Anterior é NULL, significa que o Item encontrado
        era o primeiro da lista.
        */
        if(Anterior == NULL){

            /*
            O segundo Item passa a ser o primeiro.
            */
            L->Inicio = Atual->Prox;
        }

        else{

            /*
            Estamos removendo um Item do meio ou do final.

            Fazemos o Item anterior "pular" o Item atual.

            Antes:

            Anterior -> Atual -> Proximo

            Depois:

            Anterior ----------> Proximo
            */
            Anterior->Prox = Atual->Prox;
        }


        /*
        Como o Item foi removido da lista, podemos liberar
        sua memória.
        */
        free(Atual);
    }
}


/*
=========================================================
FUNÇÃO: Imprimir_Lista
=========================================================

Percorre a lista inteira e imprime seus valores.

Usamos um ponteiro chamado Atual.

Ele começa no primeiro Item:

Atual = L->Inicio

Depois avançamos:

Atual = Atual->Prox

até chegar em NULL.
*/
void Imprimir_Lista(Lista *L){

    Item *Atual;

    /*
    Começamos pelo primeiro Item.
    */
    Atual = L->Inicio;


    /*
    Enquanto Atual apontar para algum Item,
    continuamos imprimindo.
    */
    while(Atual != NULL){

        cout << Atual->Valor << " ";

        /*
        Passa para o próximo Item.
        */
        Atual = Atual->Prox;
    }

    cout << endl;
}


/*
=========================================================
FUNÇÃO: Comprimento_Lista
=========================================================

Retorna a quantidade de Items existentes na lista.

Exemplo:

10 -> 20 -> 30 -> NULL

Comprimento = 3
*/
int Comprimento_Lista(Lista *L){

    Item *Atual;
    int Contador = 0;

    /*
    Começamos no primeiro Item.
    */
    Atual = L->Inicio;


    /*
    Percorremos a lista.
    */
    while(Atual != NULL){

        /*
        Encontramos um Item, então incrementamos.
        */
        Contador++;

        /*
        Passamos para o próximo.
        */
        Atual = Atual->Prox;
    }


    return Contador;
}


/*
=========================================================
FUNÇÃO: Contar_Valor
=========================================================

Conta quantas vezes um determinado número aparece.

Exemplo:

10 -> 5 -> 10 -> 20 -> 10 -> NULL

Contar_Valor(L, 10)

Resultado:

3
*/
int Contar_Valor(Lista *L, int N){

    Item *Atual;
    int Contador = 0;

    Atual = L->Inicio;


    while(Atual != NULL){

        /*
        Verifica se o valor do Item é igual a N.
        */
        if(Atual->Valor == N){

            Contador++;
        }

        /*
        Vai para o próximo Item.
        */
        Atual = Atual->Prox;
    }


    return Contador;
}


/*
=========================================================
FUNÇÃO: Trocar_Valor
=========================================================

Troca TODAS as ocorrências de um valor por outro.

Exemplo:

Original = 10
Novo = 99

Antes:

10 -> 5 -> 10 -> 20 -> 10

Depois:

99 -> 5 -> 99 -> 20 -> 99
*/
void Trocar_Valor(Lista *L, int Original, int Novo){

    Item *Atual;

    Atual = L->Inicio;


    while(Atual != NULL){

        /*
        Se encontramos o valor original,
        substituímos pelo novo.
        */
        if(Atual->Valor == Original){

            Atual->Valor = Novo;
        }

        /*
        Continua percorrendo.
        */
        Atual = Atual->Prox;
    }
}


/*
=========================================================
FUNÇÃO: Dividir_Lista
=========================================================

Recebe:

- uma lista original;
- um número N;
- uma lista para os maiores;
- uma lista para os menores.

Exemplo:

Lista:

10 -> 25 -> 3 -> 18 -> 7 -> 30

N = 15

Maiores:

25 -> 18 -> 30

Menores:

10 -> 3 -> 7

Os valores iguais a N NÃO entram em nenhuma lista.
*/
void Dividir_Lista(
    Lista *L,
    int N,
    Lista *Maiores,
    Lista *Menores
){

    Item *Atual;


    /*
    Garantimos que as duas listas de resultado
    estejam vazias antes de começar.
    */
    Ini_Lista(Maiores);
    Ini_Lista(Menores);


    /*
    Começamos pelo primeiro Item da lista original.
    */
    Atual = L->Inicio;


    while(Atual != NULL){

        /*
        Se o valor for maior que N,
        colocamos na lista Maiores.
        */
        if(Atual->Valor > N){

            Inserir_Item(Maiores, Atual->Valor);
        }

        /*
        Se o valor for menor que N,
        colocamos na lista Menores.
        */
        else if(Atual->Valor < N){

            Inserir_Item(Menores, Atual->Valor);
        }


        /*
        Passamos para o próximo Item da lista original.
        */
        Atual = Atual->Prox;
    }
}


/*
=========================================================
FUNÇÃO: Existe_Valor
=========================================================

Função auxiliar.

Verifica se determinado valor existe na lista.

Retorna:

1 -> encontrou
0 -> não encontrou
*/
int Existe_Valor(Lista *L, int Valor){

    Item *Atual;

    Atual = L->Inicio;


    while(Atual != NULL){

        /*
        Se encontrou o valor:
        */
        if(Atual->Valor == Valor){

            return 1;
        }

        Atual = Atual->Prox;
    }


    /*
    Percorreu a lista inteira sem encontrar.
    */
    return 0;
}


/*
=========================================================
FUNÇÃO: Inter_Lista
=========================================================

Cria uma nova lista contendo os elementos que aparecem
nas duas listas.

Exemplo:

Lista 1:

10 -> 20 -> 30 -> 40

Lista 2:

5 -> 20 -> 40 -> 50

Resultado:

20 -> 40

A função percorre a Lista 1 e verifica se cada valor
também existe na Lista 2.
*/
Lista* Inter_Lista(Lista *L1, Lista *L2){

    Lista *Resultado;
    Item *Atual;


    /*
    Criamos uma nova lista para armazenar a interseção.
    */
    Resultado = Criar_Lista();


    /*
    Começamos no primeiro Item da Lista 1.
    */
    Atual = L1->Inicio;


    while(Atual != NULL){

        /*
        Verificamos se o valor atual da Lista 1
        também existe na Lista 2.
        */
        if(Existe_Valor(L2, Atual->Valor)){

            /*
            Se existe nas duas listas,
            colocamos no Resultado.
            */
            Inserir_Item(Resultado, Atual->Valor);
        }


        /*
        Passamos para o próximo Item da Lista 1.
        */
        Atual = Atual->Prox;
    }


    return Resultado;
}


/*
=========================================================
FUNÇÃO: Selecionar_Lista
=========================================================

Pergunta ao usuário se ele quer trabalhar com:

1 -> Lista 1
2 -> Lista 2

Retorna o ponteiro da lista escolhida.
*/
Lista* Selecionar_Lista(Lista *L1, Lista *L2){

    int Op;
    Lista *L;


    do{

        cout << endl;
        cout << "Qual lista deseja utilizar?" << endl;
        cout << "Lista 1 = [1]" << endl;
        cout << "Lista 2 = [2]" << endl;
        cout << "Resposta: ";
        cin >> Op;


        if(Op != 1 && Op != 2){

            cout << endl;
            cout << "Lista invalida!!" << endl;
        }

        else{

            if(Op == 1){

                L = L1;
            }

            else{

                L = L2;
            }
        }

    }while(Op != 1 && Op != 2);


    return L;
}


/*
=========================================================
FUNÇÃO: Menu
=========================================================

Aqui ficará o menu principal do programa.

O usuário escolhe uma operação através do switch.
*/
void Menu(Lista *L1, Lista *L2){

    int Op;
    int Valor;
    int Original;
    int Novo;
    int N;

    Lista *L;

    /*
    Listas utilizadas na operação de divisão.
    */
    Lista *Maiores;
    Lista *Menores;

    /*
    Lista utilizada na interseção.
    */
    Lista *Intersecao;


    do{

        system("cls");


        cout << "==================================================" << endl;
        cout << "       TESTE DE OPERACOES COM LISTAS" << endl;
        cout << "==================================================" << endl;

        cout << "1 - Inserir na lista" << endl;
        cout << "2 - Excluir da lista" << endl;
        cout << "3 - Imprimir listas" << endl;
        cout << "4 - Comprimento da lista" << endl;
        cout << "5 - Contar ocorrencias" << endl;
        cout << "6 - Trocar valores" << endl;
        cout << "7 - Dividir uma lista em duas" << endl;
        cout << "8 - Intersecao das listas" << endl;
        cout << "0 - Sair" << endl;

        cout << "==================================================" << endl;

        cout << "Opcao: ";
        cin >> Op;


        switch(Op){


            /*
            =================================================
            CASE 1 - INSERÇÃO
            =================================================
            */
            case 1:

                system("cls");

                cout << "---------------- INSERCAO ----------------" << endl;


                /*
                Escolhe Lista 1 ou Lista 2.
                */
                L = Selecionar_Lista(L1, L2);


                cout << "Digite um valor a ser inserido: ";
                cin >> Valor;


                /*
                Insere o valor no início da lista escolhida.
                */
                Inserir_Item(L, Valor);


                cout << endl;
                cout << "Valor inserido!" << endl;


                system("pause");

                break;


            /*
            =================================================
            CASE 2 - REMOÇÃO
            =================================================
            */
            case 2:

                system("cls");

                cout << "---------------- EXCLUSAO ----------------" << endl;


                L = Selecionar_Lista(L1, L2);


                cout << "Digite um valor a ser excluido: ";
                cin >> Valor;


                Remover_Item(L, Valor);


                system("pause");

                break;


            /*
            =================================================
            CASE 3 - IMPRESSÃO
            =================================================
            */
            case 3:

                system("cls");

                cout << "---------------- IMPRESSAO ----------------" << endl;


                cout << "LISTA 1: ";

                Imprimir_Lista(L1);


                cout << "LISTA 2: ";

                Imprimir_Lista(L2);


                system("pause");

                break;


            /*
            =================================================
            CASE 4 - COMPRIMENTO
            =================================================
            */
            case 4:

                system("cls");

                cout << "---------------- COMPRIMENTO ----------------" << endl;


                L = Selecionar_Lista(L1, L2);


                cout << endl;
                cout << "Quantidade de elementos: ";
                cout << Comprimento_Lista(L) << endl;


                system("pause");

                break;


            /*
            =================================================
            CASE 5 - CONTAR OCORRÊNCIAS
            =================================================
            */
            case 5:

                system("cls");

                cout << "---------------- OCORRENCIAS ----------------" << endl;


                L = Selecionar_Lista(L1, L2);


                cout << "Digite o valor que deseja procurar: ";
                cin >> N;


                cout << endl;

                cout << "O valor " << N << " aparece ";
                cout << Contar_Valor(L, N);
                cout << " vez(es)." << endl;


                system("pause");

                break;


            /*
            =================================================
            CASE 6 - TROCAR VALORES
            =================================================
            */
            case 6:

                system("cls");

                cout << "---------------- TROCAR VALORES ----------------" << endl;


                L = Selecionar_Lista(L1, L2);


                cout << "Digite o valor original: ";
                cin >> Original;


                cout << "Digite o novo valor: ";
                cin >> Novo;


                /*
                Troca TODAS as ocorrências.
                */
                Trocar_Valor(L, Original, Novo);


                cout << endl;
                cout << "Lista resultante: ";

                Imprimir_Lista(L);


                system("pause");

                break;


            /*
            =================================================
            CASE 7 - DIVISÃO
            =================================================
            */
            case 7:

                system("cls");

                cout << "---------------- DIVISAO ----------------" << endl;


                /*
                Escolhemos qual lista será dividida.
                */
                L = Selecionar_Lista(L1, L2);


                cout << "Digite um valor para dividir a lista: ";
                cin >> N;


                /*
                Criamos as duas novas listas.
                */
                Maiores = Criar_Lista();
                Menores = Criar_Lista();


                /*
                Fazemos a divisão.
                */
                Dividir_Lista(
                    L,
                    N,
                    Maiores,
                    Menores
                );


                cout << endl;

                cout << "ELEMENTOS MAIORES QUE " << N << ": ";
                Imprimir_Lista(Maiores);


                cout << "ELEMENTOS MENORES QUE " << N << ": ";
                Imprimir_Lista(Menores);


                system("pause");

                break;


            /*
            =================================================
            CASE 8 - INTERSEÇÃO
            =================================================
            */
            case 8:

                system("cls");

                cout << "---------------- INTERSECAO ----------------" << endl;


                cout << "LISTA 1: ";
                Imprimir_Lista(L1);


                cout << "LISTA 2: ";
                Imprimir_Lista(L2);


                /*
                Cria uma nova lista contendo os elementos
                presentes nas duas listas.
                */
                Intersecao = Inter_Lista(L1, L2);


                cout << endl;

                cout << "ITENS COMUNS: ";
                Imprimir_Lista(Intersecao);


                system("pause");

                break;


            /*
            =================================================
            CASE 0 - SAIR
            =================================================
            */
            case 0:

                cout << endl;
                cout << "Saindo do programa..." << endl;

                break;


            /*
            =================================================
            DEFAULT
            =================================================
            */
            default:

                cout << endl;
                cout << "Opcao invalida!!!" << endl;

                system("pause");
        }


    }while(Op != 0);
}


/*
=========================================================
VARIÁVEIS GLOBAIS
=========================================================
*/
Lista *L1;
Lista *L2;


/*
=========================================================
MAIN
=========================================================
*/
int main(){

    /*
    Permite trabalhar com caracteres acentuados.
    */
    setlocale(LC_ALL, "Portuguese");


    /*
    Cria a Lista 1.
    */
    L1 = Criar_Lista();


    /*
    Cria a Lista 2.
    */
    L2 = Criar_Lista();


    /*
    Executa o menu principal.
    */
    Menu(L1, L2);


    return 0;
}