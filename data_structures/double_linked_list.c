/*
 ============================================================================
 Name        : double_linked_list.c
 Author      : Leonardo Gama
 Version     : 1.0
 Description : Double Linked List implementation in C
 ============================================================================
 
 This program implements a simple double linked list data structure in C.
 The double linked list supports the following operations:
 1. Initialize (inicializar): Initializes the double linked list.
 2. Search (consultar): Searches for a node with a given key in the double linked list.
 3. Insert (inserir): Inserts a new node with a given key into the double linked list.
 4. Remove (retirar): Removes a node with a given key from the double linked list.
 5. Print (imprimir): Prints all the elements in the double linked list.

 The program consists of the following main components:
 1. Data structures: Definitions for the node structure and the double linked list type.
 2. Function prototypes: Declarations of the functions used in the program.
 3. Main function: Provides a menu-driven interface to perform operations on the double linked list.
 4. Function implementations: Definitions of the functions to perform operations on the double linked list.

 To compile the program, use the following command:
 gcc double_linked_list.c -o <executable_name>.bin

 To execute the compiled program, use the following command:
 ./<executable_name>.bin
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//protótipo das funções

typedef struct NoListaInt{
	int chave;
	struct NoListaInt* prox;
	struct NoListaInt* ant;
}NoListaInt, *ListaInt;


void inicializar(ListaInt* l);
_Bool consultar(ListaInt* l,int x);
_Bool inserir(ListaInt* l,int x);
void retirar(ListaInt* l,int x);
void imprimir(ListaInt l);

int main(){
	int opcao,num;
	ListaInt l;
	for(;;){
		scanf("%d",&opcao);
		switch(opcao){
			case 1:
				inicializar(&l);
				printf("zerou a lista\n");
			break;
			case 2:
				scanf("%d",&num);
				if(consultar(&l,num))
					printf("encontra-se na lista\n");
				else
					printf("nao encontra-se na lista\n");
			break;
			case 3:
				printf("inserir: ");
				scanf("%d",&num);
				inserir(&l,num);
			break;
			case 4:
				printf("remover: ");
				scanf("%d",&num);
				retirar(&l,num);
			break;
			case 5:
				imprimir(l);
			break;
		}
	}
	return 0;
}
//FUNÇÕES BASEADAS EM UM PONTEIRO APONTANDO PARA O PRIMEIRO ELEMENTO DA LISTA//
//função inicializar
void inicializar(ListaInt* l){
	*l=NULL;
}
//função consultar
_Bool consultar(ListaInt* l,int x){
	ListaInt p;
	for(p=*l;(p)&&(p->chave!=x);p=p->prox);
	return(p);
}

//função inserir
_Bool inserir(ListaInt* l,int x){
	ListaInt p;
	if((!consultar(l,x))&&(p=(ListaInt)malloc(sizeof(NoListaInt)))){
		p->chave=x;		
		p->ant=NULL;
		if(*l)
			(*l)->ant=p;
		p->prox=*l;
		*l=p;	
		return true;
	}
	return false;
}
//função retirar
void retirar(ListaInt* l,int x){
	ListaInt p;
	for(p=*l;p->chave!=x;p=p->prox);
	if(p){
		if(p->ant){
			p->ant->prox=p->prox;
			if(!(p->prox))
				p->ant=NULL;
		}
		else
			if((*l)->prox)
				*l=p->prox;
		free(p);
	}
}

void retira (ListaInt *l, int x){
	ListaInt p;
	for(p=*l;(p) && (p->chave != x); p=p->prox);
	if(p->ant){
		(p->ant)->prox = p->prox;
		if(p->prox)
			(p->prox)->ant = p->ant;
	}
	else{
		*l = p->prox;
	free(p);
	}
}

void imprimir(ListaInt l){
	while(l){
		printf("%d ",l->chave);
		l=l->prox;
	}
	printf("\n");
}