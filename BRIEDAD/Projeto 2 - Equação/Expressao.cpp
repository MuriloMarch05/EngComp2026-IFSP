#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
struct Elemento{
    char Operador[10];
    float Numero;
    Elemento *Prox;
};

struct Fila{
    Elemento *Inicio;
    Elemento *Fim;
};

struct Pilha{
    Elemento *Topo;
};

void Ini_Fila(Fila *F){
    F->Inicio = NULL;
    F->Fim = NULL;
}

void Ini_Pilha(Pilha *P){
    P->Topo = NULL;
}

bool Fila_Vazia(Fila *F){
    return (F->Inicio == NULL);
}

bool Pilha_Vazia(Pilha *P){
    return (P->Topo == NULL);
}
Elemento * Criar_Elemento(const char* Op, float Num){
    Elemento *Ret;
    Ret = (Elemento *) malloc(sizeof(Elemento));
    if (Ret !=NULL){
	       strcpy(Ret->Operador, Op);
	       Ret->Numero = Num;
        Ret->Prox = NULL;
    }
    return Ret;
}
void Enfileirar(Fila *F, const char* Op, float Num){
    Elemento *ptE;
    ptE = Criar_Elemento(Op, Num);
    if (ptE !=NULL){
        if (Fila_Vazia(F)){
            F->Inicio = ptE;
        }
        else{
            F->Fim->Prox = ptE;
        }
        F->Fim = ptE;
    }	
}
Fila Digitar_exp(){
    char exp[100];
    cout<<"\nDigite uma expressão numérica: ";
    cin.getline(exp, 100);
    cout<<endl;
    Fila F;
    Ini_Fila(&F);
    char Op[2];
    for(int i=0;exp[i]!='\0';i++){
        if(isdigit(exp[i])){
            char auxnum[100];
            int j=0;
            while(isdigit(exp[i])){
                auxnum[j]=exp[i];
                j++;
                i++;
            }
            auxnum[j]='\0';
            i--;
            Enfileirar(&F, "#", atoi(auxnum));
        }
        else{
            Op[0]=exp[i];
            Op[1]='\0';
            Enfileirar(&F, Op, 0);
        }
    }
    return F;
}
Elemento * Desenfileirar(Fila *F){
    Elemento *Ret = NULL;
    if (!Fila_Vazia(F)){
        Ret = F->Inicio;
        if (F->Inicio == F->Fim){
            F->Inicio = NULL;
            F->Fim = F->Inicio;
        }
        else{
            F->Inicio = F->Inicio->Prox;
        }
    }
    return Ret;
}
void Empilhar(Pilha *P, const char* Op, float Num){
    Elemento *ptE;
    ptE=Criar_Elemento(Op, Num);
    if(ptE!=NULL){
        if (!Pilha_Vazia(P)){
            ptE->Prox = P->Topo;
        }
        P->Topo = ptE;
    }	
}
Elemento * Desempilhar(Pilha *P){
    Elemento *Ret = NULL;
    if (!Pilha_Vazia(P)){
        Ret = P->Topo;
        P->Topo = P->Topo->Prox;
    }
    return Ret;
}
float Calcular(float num1, float num2, const char* operador){

    float resultado = 0;
    switch(operador[0]){

        case '+':
            resultado = num1 + num2;
            break;
        case '-':
            resultado = num1 - num2;
            break;
        case '*':
            resultado = num1 * num2;
            break;

        case '/':
            if(num2 != 0){
                resultado = num1 / num2;
                break;
            }
            else{
                cout << "Erro. Divisao por zero." << endl;
                break;
            }

        default:

            if(strcmp(operador, ">") == 0){
                resultado = num1 > num2;
                break;
            }
            else{
                if(strcmp(operador, "<") == 0){
                    resultado = num1 < num2;
                    break;
                }
                else{
                    if(strcmp(operador, "=") == 0){
                        resultado = num1 == num2;
                        break;
                    }
                    else{
                        if(strcmp(operador, "!=") == 0){
                            resultado = num1 != num2;
                            break;
                        }
                        else{
                            if(strcmp(operador, ">=") == 0){
                                resultado = num1 >= num2;
                                break;
                            }
                            else{
                                if(strcmp(operador, "<=") == 0){
                                    resultado = num1 <= num2;
                                    break;
                                }
                                else{
                                    if(strcmp(operador, "!") == 0){
                                        resultado = !num1;
                                        break;
                                    }
                                    else{
                                        cout << "Operador invalido." << endl;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
    }

    return resultado;
}
void Resolver_pilha(Pilha *PNum, Pilha *POp){
    float num1, num2;
    char op[10];
    num2=(Desempilhar(PNum))->Numero;
    num1=(Desempilhar(PNum))->Numero;
    strcpy(op, (Desempilhar(POp))->Operador);
    Empilhar(PNum, "#", Calcular(num1, num2, op));
}
int preced(const char* operador){

    int prioridade = 0;

    if(strcmp(operador, "!") == 0){
        prioridade = 4;
    }
    else if(strcmp(operador, "*") == 0 || strcmp(operador, "/") == 0){
        prioridade = 3;
    }
    else if(strcmp(operador, "+") == 0 || strcmp(operador, "-") == 0){
        prioridade = 2;
    }
    else if(strcmp(operador, ">") == 0 || strcmp(operador, "<") == 0 ||
            strcmp(operador, ">=") == 0 || strcmp(operador, "<=") == 0 ||
            strcmp(operador, "=") == 0 || strcmp(operador, "!=") == 0){
        prioridade = 1;
    }

    return prioridade;
}
void Calcular_exp(Fila *F){
    Pilha PNum, POp;
    Ini_Pilha(&PNum);
    Ini_Pilha(&POp);
    Elemento *pto, *aux;
    for(pto=F->Inicio;pto!=NULL;pto=pto->Prox){
        aux=Desenfileirar(F);
       if(!strcmp(aux->Operador, "#")){
           Empilhar(&PNum, "#", aux->Numero);
       }
       else{
           if(POp.Topo==NULL){
               Empilhar(&POp, aux->Operador, 0);
           }
           else{
               if(preced(aux->Operador)<=preced(POp.Topo->Operador) && POp.Topo!=NULL){
                   while(preced(aux->Operador)<=preced(POp.Topo->Operador)){
                       Resolver_pilha(&PNum, &POp);
                   }
               }
               else{
                   Resolver_pilha(&PNum, &POp);
               }
           }
       } 
    }
}
void Menu(){
    int Op;
    Fila F;
    do{
        cout<<"[1] - Inserir expressão\n[2] - Calcular expressão\n[3] - Sair\nOpção: ";
        cin>>Op;
        switch(Op){
            case 1: F=Digitar_exp();
                    system("cls");
                    cin.get();
                    break;
            case 2: Calcular_exp(&F);
                    system("cls");
                    cin.get();
                    break;
            case 3: system("cls");
                    cin.get();
                    break;
            default:cout<<"\nOpção inválida\n";
                    system("cls");
                    cin.get();
                    break;
        }
    }while(Op!=3);
}
int main(){
    Menu();
    return 0;
}