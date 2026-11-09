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
void Inserir_num(Fila *F, char exp[], int *i){
    char auxnum[100];
    int j=0;
    while(isdigit(exp[*i]) || exp[*i]=='.' && isdigit(exp[*i+1])){
        auxnum[j]=exp[*i];
        (*i)++;
        j++;
    }
    auxnum[j]='\0';
    Enfileirar(F, "#", atof(auxnum));
}
void Inserir_op(Fila *F, char exp[], int *i){
    char Op[3];
    Op[0] = exp[*i];
    if(exp[*i] == '(' || exp[*i] == ')') {
        Op[1] = '\0';
    }
    else{
        if(exp[*i+1] != '\0' && !isdigit(exp[*i+1]) && exp[*i+1] != '(' && exp[*i+1] != ')') {
            Op[1] = exp[*i+1];
            Op[2] = '\0';
            (*i)++;
        }
        else{
            Op[1] = '\0';
        }
    }
    Enfileirar(F, Op, 0);
}
Elemento* Digitar_exp(){
    char exp[100];
    cin.ignore();
    cout<<"\nDigite uma expressão numérica: ";
    cin.getline(exp, 100);
    cout<<endl;
    Fila F;
    Ini_Fila(&F);
    for(int i=0;exp[i]!='\0';i++){
        if(isdigit(exp[i])){
            Inserir_num(&F, exp, &i);
        }
        else{
            Inserir_op(&F, exp, &i);
        }
    }
    return F.Inicio;
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
    if(!strcmp(op, "=")){
        retorno=(num1=num2);
    }
    return retorno;
}
void Resolver_pilha(Pilha *PNum, Pilha *POp){
    float num1, num2;
    char op[10];
    num2=(Desempilhar(PNum))->Numero;
    num1=(Desempilhar(PNum))->Numero;
    strcpy(op, Desempilhar(POp)->Operador);
    Empilhar(PNum, "#", Calculo_parcial(num1, num2, op));
}
int preced(const char *Op){
    int precedencia;
    if(strcmp(Op, "<=")==0 || strcmp(Op, ">=")==0 || strcmp(Op, "<")==0 || strcmp(Op, ">")==0 || strcmp(Op, "!=")==0 || strcmp(Op, "==")==0){
        precedencia=1;
    }
    if(strcmp(Op, "+")==0 || strcmp(Op, "-")==0){
        precedencia=2;
    }
    if(strcmp(Op, "*")==0 || strcmp(Op, "×")==0 || strcmp(Op, "/")==0 || strcmp(Op, "÷")==0){
        precedencia=3;
    }
    return precedencia;
}
float Calcular_exp(Fila *F){
    Pilha PNum, POp;
    Ini_Pilha(&PNum);
    Ini_Pilha(&POp);
    Elemento *pto;
    for(pto=F->Inicio;pto!=NULL;pto=pto->Prox){
       if(strcmp(pto->Operador, "#")==0){
           Empilhar(&PNum, "#", pto->Numero);
       }
       else{
           if(!strcmp(pto->Operador, "(")){
               Empilhar(&POp, "(", 0);
           }
           else{
               if(!strcmp(pto->Operador, ")")){
                   while(!Pilha_Vazia(&POp) && strcmp(pto->Operador, "(")!=0){
                       Resolver_pilha(&PNum, &POp);
                   }
                   if(!Pilha_Vazia(&POp)){
                       free(Desempilhar(&POp));
                   }
               }
               else{
                   while(!Pilha_Vazia(&POp) && strcmp(POp.Topo->Operador, "(") != 0 && preced(aux->Operador) <= preced(POp.Topo->Operador)){
                       Resolver_pilha(&PNum, &POp);
                   }
                   Empilhar(&POp, aux->Operador, 0);
               }
           }
       } 
    }
    while(!Pilha_Vazia(&POp)){
        Resolver_pilha(&PNum, &POp);
    }
    return PNum.Topo->Numero;
}
void Menu(){
    int Op;
    Fila F;
    do{
        cout<<"[1] - Inserir expressão\n[2] - Calcular expressão\n[3] - Sair\nOpção: ";
        cin>>Op;
        switch(Op){
            case 1: F.Inicio=Digitar_exp();
                    system("cls");
                    cin.get();
                    break;
            case 2: cout<<"\nO resultado da expressão é "<<Calcular_exp(&F);
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