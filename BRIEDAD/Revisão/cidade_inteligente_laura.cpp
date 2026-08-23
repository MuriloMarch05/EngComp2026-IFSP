#include <iostream>
#include <string.h>
#include <locale.h>

using namespace std;

struct cidade{
    char nome[50];
    char bairros[3][50];
};

struct Bairro{
    char ruas[50];
};

cidade cidades[3][3];
Bairro bairros[3][3];

void inicializarCidade(){

    strcpy(cidades[0][0].nome,"Sao Jose do Rio Preto");
    strcpy(cidades[0][0].bairros[0],"Higienopolis");
    strcpy(cidades[0][0].bairros[1],"Jardim Walkiria");
    strcpy(cidades[0][0].bairros[2],"Estoril");

    strcpy(cidades[0][1].nome,"Birigui");
    strcpy(cidades[0][1].bairros[0],"Centro");
    strcpy(cidades[0][1].bairros[1],"Jardim America");
    strcpy(cidades[0][1].bairros[2],"Vila Guanabara");

    strcpy(cidades[0][2].nome,"Aracatuba");
    strcpy(cidades[0][2].bairros[0],"Centro");
    strcpy(cidades[0][2].bairros[1],"Saudade");
    strcpy(cidades[0][2].bairros[2],"Ipanema");

    strcpy(cidades[1][0].nome,"Catanduva");
    strcpy(cidades[1][0].bairros[0],"Centro");
    strcpy(cidades[1][0].bairros[1],"Vila Paulista");
    strcpy(cidades[1][0].bairros[2],"Jardim Soto");

    strcpy(cidades[1][1].nome,"Barretos");
    strcpy(cidades[1][1].bairros[0],"Centro");
    strcpy(cidades[1][1].bairros[1],"Nadir Kenan");
    strcpy(cidades[1][1].bairros[2],"Jardim Soares");

    strcpy(cidades[1][2].nome,"Bauru");
    strcpy(cidades[1][2].bairros[0],"Centro");
    strcpy(cidades[1][2].bairros[1],"Vila Falcao");
    strcpy(cidades[1][2].bairros[2],"Jardim America");

    strcpy(cidades[2][0].nome,"Marilia");
    strcpy(cidades[2][0].bairros[0],"Centro");
    strcpy(cidades[2][0].bairros[1],"Fragata");
    strcpy(cidades[2][0].bairros[2],"Palmital");

    strcpy(cidades[2][1].nome,"Presidente Prudente");
    strcpy(cidades[2][1].bairros[0],"Centro");
    strcpy(cidades[2][1].bairros[1],"Bosque");
    strcpy(cidades[2][1].bairros[2],"Jardim Paulista");

    strcpy(cidades[2][2].nome,"Campinas");
    strcpy(cidades[2][2].bairros[0],"Centro");
    strcpy(cidades[2][2].bairros[1],"Taquaral");
    strcpy(cidades[2][2].bairros[2],"Cambui");

    cout << "Cidades inicializadas!" << endl;
}

void inicializarBairro(){

    strcpy(bairros[0][0].ruas,"Rua Alberto Andalo");
    strcpy(bairros[1][0].ruas,"Rua General Glicerio");
    strcpy(bairros[2][0].ruas,"Rua Antonio de Godoy");

    strcpy(bairros[0][1].ruas,"Rua Joao Pessoa");
    strcpy(bairros[1][1].ruas,"Rua Maria da Penha");
    strcpy(bairros[2][1].ruas,"Rua das Flores");

    strcpy(bairros[0][2].ruas,"Rua das Palmeiras");
    strcpy(bairros[1][2].ruas,"Rua das Acacias");
    strcpy(bairros[2][2].ruas,"Rua das Orquideas");

    cout << "Bairros inicializados!" << endl;
}

void obterBairro(){

    int linha,coluna,bairro;

    cout << "Linha: ";
    cin >> linha;
    cout << "Coluna: ";
    cin >> coluna;

    if(linha<0 || linha>2 || coluna<0 || coluna>2){
        cout << "Cidade invalida!" << endl;
        return;
    }

    cout << "\nCidade: " << cidades[linha][coluna].nome << endl;

    for(int i=0;i<3;i++)
        cout << i << " - " << cidades[linha][coluna].bairros[i] << endl;

    cout << "Escolha o bairro: ";
    cin >> bairro;

    if(bairro>=0 && bairro<3)
        cout << "Bairro: " << cidades[linha][coluna].bairros[bairro] << endl;
    else
        cout << "Bairro invalido!" << endl;
}

void exibirDadosBairro(){

    int linha,coluna,bairro;

    cout << "Linha: ";
    cin >> linha;
    cout << "Coluna: ";
    cin >> coluna;

    if(linha<0 || linha>2 || coluna<0 || coluna>2){
        cout << "Cidade invalida!" << endl;
        return;
    }

    cout << "Cidade: " << cidades[linha][coluna].nome << endl;

    for(int i=0;i<3;i++)
        cout << i << " - " << cidades[linha][coluna].bairros[i] << endl;

    cout << "Escolha o bairro: ";
    cin >> bairro;

    if(bairro>=0 && bairro<3){
        cout << "\nCidade: " << cidades[linha][coluna].nome << endl;
        cout << "Bairro: " << cidades[linha][coluna].bairros[bairro] << endl;
        cout << "Rua: " << bairros[linha][coluna].ruas << endl;
    }
    else
        cout << "Bairro invalido!" << endl;
}

void listarBairros(){

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){

            cout << "\n" << cidades[i][j].nome << endl;

            for(int k=0;k<3;k++)
                cout << "- " << cidades[i][j].bairros[k] << endl;
        }
    }
}

void criarEvento(){

    int linha,coluna,bairro;
    char evento[50];

    cout << "Linha: ";
    cin >> linha;
    cout << "Coluna: ";
    cin >> coluna;

    if(linha<0 || linha>2 || coluna<0 || coluna>2){
        cout << "Cidade invalida!" << endl;
        return;
    }

    cout << "Cidade: " << cidades[linha][coluna].nome << endl;

    for(int i=0;i<3;i++)
        cout << i << " - " << cidades[linha][coluna].bairros[i] << endl;

    cout << "Escolha o bairro: ";
    cin >> bairro;

    if(bairro<0 || bairro>2){
        cout << "Bairro invalido!" << endl;
        return;
    }

    cin.ignore();
    cout << "Nome do evento: ";
    cin.getline(evento,50);

    cout << "\nEvento: " << evento << endl;
    cout << "Cidade: " << cidades[linha][coluna].nome << endl;
    cout << "Bairro: " << cidades[linha][coluna].bairros[bairro] << endl;
    cout << "Rua: " << bairros[linha][coluna].ruas << endl;
}

void imprimirCidades(){

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){

            cout << "\n[" << i << "][" << j << "] "
                 << cidades[i][j].nome << endl;

            for(int k=0;k<3;k++)
                cout << "- " << cidades[i][j].bairros[k] << endl;
        }
    }
}

void imprimirBairros(){

    for(int i=0;i<3;i++){
	
        for(int j=0;j<3;j++)
            cout << bairros[i][j].ruas << endl;
        }
}

void Menu(){

    int opcao;

    do{
        system("cls");

        cout << "MENU" << endl;
        cout << "1 - Inicializar cidades" << endl;
        cout << "2 - Inicializar bairros" << endl;
        cout << "3 - Obter bairro" << endl;
        cout << "4 - Exibir dados do bairro" << endl;
        cout << "5 - Listar bairros" << endl;
        cout << "6 - Criar evento" << endl;
        cout << "7 - Imprimir cidades" << endl;
        cout << "8 - Imprimir bairros" << endl;
        cout << "0 - Sair" << endl;

        cout << "\nOpcao: ";
        cin >> opcao;

        switch(opcao){

            case 1: inicializarCidade(); 
			break;
            case 2: inicializarBairro(); 
			break;
            case 3: obterBairro(); 
			break;
            case 4: exibirDadosBairro();
			 break;
            case 5: listarBairros(); 
			break;
            case 6: criarEvento();
			 break;
            case 7: imprimirCidades();
			 break;
            case 8: imprimirBairros();
			 break;
            case 0: cout << "Fechando..." << endl; 
			break;
            default: cout << "Opcao invalida!" << endl;
        }

        if(opcao!=0)
            system("pause");

    }while(opcao!=0);
}

int main(){

    setlocale(LC_ALL,"Portuguese");

    Menu();

    return 0;
}