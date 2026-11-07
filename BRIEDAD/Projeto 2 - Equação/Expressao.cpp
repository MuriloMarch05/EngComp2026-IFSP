#include <iostream>
#include <stdlib.h>
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
            auxnum[j+1]='\0';
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
float Calculo_parcial(float num1, float num2, char op[]){
    float retorno;
    if(!strcmp(op, "+")){
        retorno=num1+num2;
    }
    if(!strcmp(op, "-")){
        retorno=num1-num2;
    }
    if(!strcmp(op, "*") || !strcmp(op, "×")){
        retorno=num1*num2;
    }
    if(!strcmp(op, "÷") || !strcmp(op, "/")){
        retorno=num1/num2;
    }
    if(!strcmp(op, "<")){
        retorno=(num1<num2);
    }
    if(!strcmp(op, ">")){
        retorno=(num1>num2);
    }
    if(!strcmp(op, "<=")){
        retorno=(num1<=num2);
    }
    if(!strcmp(op, ">=")){
        retorno=(num1>=num2);
    }
    if(!strcmp(op, "!=")){
        retorno=(num1!=num2);
    }
    return retorno;
}
void Resolver_pilha(Pilha *PNum, Pilha *POp){
    float num1, num2;
    char op[10];
    num2=(Desempilhar(PNum))->Numero;
    num1=(Desempilhar(PNum))->Numero;
    strcpy(op, (Desempilhar(POp))->Operador);
    Empilhar(PNum, "#", Calculo_parcial(num1, num2, op));
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
               if(preced(aux->Operador)<=preced(POp.Topo) && POp.Topo!=NULL){
                   while(preced(aux->Operador)<=preced(POp.Topo)){
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