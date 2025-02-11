/*
 ============================================================================
 Name        : stack.c
 Author      : Leonardo Gama
 Version     : 1.0
 Description : Stack implementation in C
 ============================================================================
 
 This program implements a simple stack (LIFO) data structure in C using a linked list.
 The stack supports the following operations:
 1. Initialize (Inicializar): Initializes the stack.
 2. Push (Empilhar): Pushes a new element onto the stack.
 3. Pop (Desempilhar): Pops an element from the stack.
 4. Print (Imprimir): Prints all the elements in the stack.

 The program consists of the following main components:
 1. Data structures: Definitions for the node structure and the stack type.
 2. Function prototypes: Declarations of the functions used in the program.
 3. Main function: Provides a menu-driven interface to perform operations on the stack.
 4. Function implementations: Definitions of the functions to perform operations on the stack.

 To compile the program, use the following command:
 gcc stack.c -o <executable_name>.bin

 To execute the compiled program, use the following command:
 ./<executable_name>.bin
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//declaração da estrutura
typedef struct NoPilhaInt{
	int chave;
	struct NoPilhaInt* prox;
} NoPilhaInt, *PilhaInt;

//protótipo das funcoes
void Inicializar(PilhaInt* p);
_Bool Empilhar(PilhaInt* p,int x);
_Bool Desempilhar(PilhaInt* p,int* x);
void Imprimir(PilhaInt p);

int main(int argc, char **argv){
	PilhaInt y;
	int menu,num,a;
	for(;;){
		printf("\n\n1 - INICIALIZAR\n");
		printf("2 - EMPILHAR\n");
		printf("3 - DESEMPILHAR\n");
		printf("4 - IMPRIMIR PILHA\n\n");
		scanf("%d",&menu);	
		switch(menu){
			case 1:
				Inicializar(&y);
				break;
			case 2:
				printf("Entrada: ");
				scanf("%d",&num);
				if(Empilhar(&y,num))
					printf("Empilhou");
				else
					printf("Não empilhou");
				break;
			case 3:
				if(Desempilhar(&y,&a))
					printf("Desempilhou o numero %d",a);
				else
					printf("Não desempilhou");
				break;
			case 4:
				Imprimir(y);
				break;
			case 5:
				return 0;
				break;
		}
	}
	return 0;
}

//Funcoes
void Inicializar(PilhaInt* p){
	*p=NULL;
}

_Bool Empilhar(PilhaInt* p,int x){
	PilhaInt q;
	if ((q=(PilhaInt)malloc(sizeof(NoPilhaInt)))){
		q->chave=x;
		q->prox=*p;
		*p=q;
		return true;
	}
	return false;
}

_Bool Desempilhar(PilhaInt* p,int* x){
	PilhaInt q=*p;
	if(!(*p))
		return false;
	*x=(*p)->chave;
	*p=q->prox;
	free(q);
	return true;
}

void Imprimir(PilhaInt p){
	PilhaInt q=p;
	if(p)
		do{
			printf("%d - ",q->chave);
			q=q->prox;
		}while (q->prox!=NULL);
}