#include <iostream>
using namespace std;

/*
    ============================================================
    STRUCT Contato
    ============================================================
    Uma struct é uma "planta" de uma caixa que agrupa vários
    dados relacionados dentro de UMA única variável.

    Aqui, em vez de ter 6 variáveis soltas (nome, email, telefone...)
    para CADA pessoa, criamos um "modelo" chamado Contato, que já
    vem com essas 6 gavetas prontas: 5 de texto (string) e 1 de
    número (int).

    Isso NÃO cria nenhuma pessoa ainda -- só define o formato.
*/
struct Contato{
    string Nome, Email, Telefone, Cidade, Estado;
    int Idade;
};

/*
    ============================================================
    VETOR Agenda[10]
    ============================================================
    Do mesmo jeito que "int notas[10]" cria 10 números inteiros
    um do lado do outro, "Contato Agenda[10]" cria 10 "caixas"
    Contato, uma do lado da outra.

    Cada posição (Agenda[0], Agenda[1], ... Agenda[9]) é uma
    PESSOA INTEIRA, com todos os 6 campos dela.

    Está declarada como variável GLOBAL (fora de qualquer função),
    por isso pode ser usada no main() sem precisar "criar" de novo.
*/
Contato Agenda[10];

/*
    ============================================================
    FUNÇÃO Cadastrar
    ============================================================
    Objetivo: ler os dados de UMA nova pessoa e guardar na
    próxima posição livre do vetor.

    Parâmetros:
    - Contato A[]  -> é um "apelido" para o vetor Agenda, válido
                      só dentro desta função. Quando chamamos
                      Cadastrar(Agenda, Tam), o "A" aqui dentro
                      passa a se referir ao mesmo vetor Agenda.
    - int Tam      -> representa quantas pessoas já foram
                      cadastradas até agora. Também indica qual
                      é a PRÓXIMA posição livre do vetor.
                      Ex: se Tam = 3, as posições 0, 1 e 2 já
                      têm dados, e a 3 está livre.

    IMPORTANTE sobre o retorno:
    Em C++, quando um "int" é passado como parâmetro (sem &),
    a função recebe uma CÓPIA do valor. Ou seja, o "Tam" aqui
    dentro e o "Tam" de quem chamou a função são variáveis
    DIFERENTES, mesmo tendo o mesmo nome.
    Por isso, para quem chamou a função "saber" que Tam mudou,
    a função precisa DEVOLVER (return) o novo valor, e quem
    chamou precisa GUARDAR esse retorno:
        Tam = Cadastrar(A, Tam);
*/
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

    Tam++; // Preenchemos uma posição a mais, então a próxima livre sobe 1
    return Tam; // Devolve o novo valor para quem chamou atualizar o Tam externo
}

/*
    ============================================================
    FUNÇÃO Imprimir_Reg
    ============================================================
    Objetivo: imprimir os dados de APENAS UMA posição do vetor
    (uma pessoa só), não percorre nada, não tem "for".

    Parâmetros:
    - Contato A[]  -> o vetor (apelido, igual explicado acima)
    - int Pos      -> a posição EXATA que queremos imprimir
                      (ex: Pos = 3 imprime a pessoa da posição 3)
    - int Tipo     -> controla o "nível de detalhe" da impressão:
                      Tipo == 1 -> imprime TODOS os campos
                      Tipo == 2 (ou qualquer outro) -> imprime só
                      Nome, Email e Telefone (dados básicos)

    Essa função é a "peça reaproveitável" que outras funções
    (Imprimir_Vetor, BuscaEstado, o Menu) usam sempre que
    precisam mostrar os dados de UMA pessoa na tela.
*/
void Imprimir_Reg(Contato A[], int Pos, int Tipo){
    cout << "Nome[" << Pos << "]: " << A[Pos].Nome << endl;
    cout << "E-mail[" << Pos << "]: " << A[Pos].Email << endl;
    cout << "Telefone[" << Pos << "]: " << A[Pos].Telefone << endl;

    if (Tipo == 1){ // Só imprime esses campos extras se for impressão "Total"
        cout << "Cidade[" << Pos << "]: " << A[Pos].Cidade << endl;
        cout << "Estado[" << Pos << "]: " << A[Pos].Estado << endl;
        cout << "Idade[" << Pos << "]: " << A[Pos].Idade << endl;
    }
}

/*
    ============================================================
    FUNÇÃO Imprimir_Vetor
    ============================================================
    Objetivo: imprimir TODAS as pessoas já cadastradas no vetor,
    uma atrás da outra.

    Parâmetros:
    - Contato A[]  -> o vetor
    - int Tam      -> até onde o "for" deve percorrer (só as
                      posições realmente preenchidas)
    - int Tipo     -> repassado para Imprimir_Reg (1 = tudo,
                      2 = parcial)

    Essa função NÃO imprime nada diretamente com cout -- ela só
    organiza o "for" e delega o trabalho de imprimir 1 pessoa
    para a função Imprimir_Reg. Isso evita repetir a mesma
    lógica de impressão duas vezes (reaproveitamento de código).

    Reparem: usamos "cont" (que muda a cada volta: 0, 1, 2...)
    como a posição passada para Imprimir_Reg -- e NÃO "Tam"
    (que não muda e só serve de limite para o for).
*/
void Imprimir_Vetor(Contato A[], int Tam, int Tipo){
    int cont;
    for(cont = 0; cont < Tam; cont++){
        Imprimir_Reg(A, cont, Tipo); // cont = posição da vez sendo impressa
    }
}

/*
    ============================================================
    FUNÇÃO BuscaEstado
    ============================================================
    Objetivo: procurar, dentro do vetor, todas as pessoas que
    sejam MAIORES DE 18 ANOS (idade >= 18) E que pertençam ao
    Estado informado pelo usuário. Imprime direto na tela quem
    encontrar.

    Parâmetros:
    - Contato A[]     -> o vetor
    - int Tam         -> limite do "for" (só posições preenchidas)
    - string Estado   -> o estado que queremos buscar; ele é
                         RECEBIDO como parâmetro -- quem lê o
                         valor digitado pelo usuário é o Menu,
                         antes de chamar esta função.

    A condição do "if" usa o operador && (E lógico): as DUAS
    condições (idade e estado) precisam ser verdadeiras ao
    mesmo tempo para a pessoa ser impressa.

    Reaproveita Imprimir_Reg(A, cont, 1) para mostrar os dados
    completos de quem for encontrado.
*/
void BuscaEstado(Contato A[], int Tam, string Estado){
    int cont;
    for (cont = 0; cont < Tam; cont++){
        if (A[cont].Idade >= 18 && A[cont].Estado == Estado){
            Imprimir_Reg(A, cont, 1);
        }
    }
}

/*
    ============================================================
    FUNÇÃO BuscaMaisVelho
    ============================================================
    Objetivo: encontrar a POSIÇÃO da pessoa com a maior idade
    no vetor, e RETORNAR essa posição (não imprime nada aqui
    dentro -- quem imprime é o Menu, depois de receber o
    retorno, conforme pede o enunciado).

    Estratégia ("melhor candidato até agora"):
    1) Assumimos que a posição 0 é a mais velha (chute inicial,
       sempre válido desde que exista pelo menos 1 pessoa).
    2) Percorremos o resto do vetor (a partir da posição 1,
       já que a posição 0 já é nossa referência inicial e não
       precisa ser comparada com ela mesma).
    3) A cada posição, comparamos a idade dela com a idade do
       "candidato" atual guardado em Maisvelho. Se for maior,
       atualizamos Maisvelho para essa nova posição.
    4) No final, Maisvelho contém a posição da pessoa mais
       velha de todo o vetor, e é isso que retornamos.

    Repare que "Maisvelho" guarda uma POSIÇÃO (índice), não a
    idade em si -- é o índice que precisamos para depois buscar
    todos os outros dados dessa pessoa (nome, email etc).
*/
int BuscaMaisVelho(Contato A[], int Tam){
    int Maisvelho = 0, cont; // chute inicial: posição 0

    for (cont = 1; cont < Tam; cont++){
        if (A[cont].Idade > A[Maisvelho].Idade){
            Maisvelho = cont; // achou alguém mais velho, atualiza a posição
        }
    }

    return Maisvelho; // devolve só a posição, sem imprimir nada
}

/*
    ============================================================
    FUNÇÃO Menu
    ============================================================
    Objetivo: controlar o programa inteiro através de um menu
    de opções que se repete até o usuário escolher sair.

    - "do...while" garante que o menu apareça AO MENOS 1 vez.
    - "switch" decide o que fazer conforme o número digitado.
    - "Tam" é declarado AQUI (não no main), começando em 0,
      e vai sendo atualizado a cada cadastro feito.
*/
void Menu(Contato A[]){
    int Op, Tam = 0, OpImp, PosMaisVelho;
    string EstadoBusca;

    do{
        cout << "[1] - Cadastrar" << endl;
        cout << "[2] - Imprimir" << endl;
        cout << "[3] - Busca por Estado" << endl;
        cout << "[4] - Mais velho" << endl;
        cout << "[5] - Sair" << endl;
        cout << "Opção: ";
        cin >> Op;

        switch(Op){

            case 1:
                // Cadastra e ATUALIZA Tam com o valor retornado pela função
                // (lembra: sem isso, o Tam do Menu nunca mudaria!)
                Tam = Cadastrar(A, Tam);
                break;

            case 2:
                // Pergunta o tipo de impressão (1 = total, 2 = parcial)
                cout << "[1] - Total" << endl;
                cout << "[2] - Parcial" << endl;
                cout << "Opção: ";
                cin >> OpImp;
                Imprimir_Vetor(A, Tam, OpImp);
                break;

            case 3:
                // O Menu lê o Estado digitado e REPASSA como parâmetro
                // para a função, que já sabe filtrar e imprimir sozinha
                cout << "Qual Estado? (sigla):  ";
                cin >> EstadoBusca;
                BuscaEstado(A, Tam, EstadoBusca);
                break;

            case 4:
                // A função só devolve a POSIÇÃO da pessoa mais velha;
                // quem imprime os dados é o Menu, usando Imprimir_Reg
                PosMaisVelho = BuscaMaisVelho(A, Tam);
                Imprimir_Reg(A, PosMaisVelho, 1);
                break;

            case 5:
                break; // Sai do switch; a condição do while (Op != 5) encerra o laço

            default:
                cout << "Opção inválida." << endl;
        }

    } while(Op != 5);
}

/*
    ============================================================
    FUNÇÃO main
    ============================================================
    Segue a regra do enunciado: no programa principal só pode
    haver a chamada do Menu. Toda a lógica fica dentro das
    funções que já construímos acima.
*/
int main(){
    setlocale(LC_ALL, "Portuguese"); // Ajusta acentuação/caracteres especiais

    Menu(Agenda); // Passa o vetor global Agenda como parâmetro para o Menu

    return 0;
}
