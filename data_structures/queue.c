/*
 ============================================================================
 Name        : queue.c
 Author      : Leonardo Gama
 Version     : 1.0
 Description : Queue (FIFO) implementation in C
 ============================================================================
 
 This program implements a simple queue (FIFO) data structure in C using a linked list.
 The queue supports the following operations:
 1. Initialize (Inicializar): Initializes the queue.
 2. Enqueue (Enfileirar): Adds a new element to the end of the queue.
 3. Dequeue (Desenfileirar): Removes an element from the front of the queue.
 4. Print (Imprimir): Prints all the elements in the queue.

 The program consists of the following main components:
 1. Data structures: Definitions for the node structure and the queue type.
 2. Function prototypes: Declarations of the functions used in the program.
 3. Main function: Provides a menu-driven interface to perform operations on the queue.
 4. Function implementations: Definitions of the functions to perform operations on the queue.

 To compile the program, use the following command:
 gcc queue.c -o <executable_name>.bin

 To execute the compiled program, use the following command:
 ./<executable_name>.bin
 ============================================================================
 */

//Lista FiFo - First In First Out
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//declaração da estrutura
typedef struct NoFilaInt {
	int chave;
	struct NoFilaInt* prox;
} NoFilaInt;

typedef struct{
	NoFilaInt* prim, *ult;
} FilaInt;

//protótipo de funções
void Inicializar(FilaInt* f);
_Bool Enfileirar(FilaInt* f,int x);
_Bool Desenfileirar(FilaInt* f,int* x);
void Imprimir(FilaInt* f);

int main(int argc,char** argv){
	int a,opcao,num;
	FilaInt y;
	for(;;){
		printf("Menu de opções\n");
		printf("1 - Inicializar Fila\n");
		printf("2 - Enfileirar\n");
		printf("3 - Desenfileirar\n");
		printf("4 - Imprimir Fila\n");
		printf("Opção: ");
		scanf("%d",&opcao);
		switch(opcao){
			case 1:
				Inicializar(&y);
				printf("Concluido\n");
				break;
			case 2:
				printf("Entrada: ");
					scanf("%d",&num);
				if(Enfileirar(&y,num))
					printf("Enfileirou\n");
				else
					printf("Nao enfileirou\n");
				break;
			case 3:
				if(Desenfileirar(&y,&a))
					printf("O número %d saiu da fila\n",a);
				else
					printf("Não desenfileirou\n");
				break;
			case 4:
				Imprimir(&y);
				break;
			default:
				printf("Opcao invalida. Tente novamente\n");
		}
	}	
	return 0;
}
//funções
void Inicializar(FilaInt* f){
	f->prim=NULL;
}
_Bool Enfileirar(FilaInt* f,int x){
	NoFilaInt* p=f->prim;	
	if(!(p=(NoFilaInt*)malloc(sizeof(NoFilaInt))))
		return false;
	if (!(f->prim))	
		f->prim=p;
	else
		f->ult->prox=p;
	p->chave=x;
	p->prox=NULL;
	f->ult=p;
	return true;
}
_Bool Desenfileirar(FilaInt* f,int* x){
	NoFilaInt* p=f->prim;	
	if (!(f->prim))
		return false;
	*x=f->prim->chave;
	f->prim=f->prim->prox;
	free(p);
	return true;
}
void Imprimir2(FilaInt* f){
	NoFilaInt* p=f->prim;
	if(f->prim){	
		do{
			printf("%d - ",p->chave);
			p=p->prox;
		}while (p->prox!=NULL);
		printf("%d\n",f->ult->chave);
	}
}
void Imprimir(FilaInt* f){
	NoFilaInt* p;
	if(f->prim)
		for(p=f->prim;p->prox!=NULL;p=p->prox)
			printf("%d - ",p->chave);
}