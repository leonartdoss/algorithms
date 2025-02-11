/*
 ============================================================================
 Name        : circular_singly_linked_list.c
 Author      : Leonardo Gama
 Version     : 1.0
 Description : Circular Singly Linked List implementation in C
 ============================================================================
 
 This program implements a simple circular singly linked list data structure in C.
 The circular singly linked list supports the following operations:
 1. Initialize (inicializar): Initializes the circular singly linked list.
 2. Search (consultar): Searches for a node with a given key in the circular singly linked list.
 3. Insert (inserir): Inserts a new node with a given key into the circular singly linked list.
 4. Remove (retirar): Removes a node with a given key from the circular singly linked list.
 5. Print (imprimir): Prints all the elements in the circular singly linked list.

 The program consists of the following main components:
 1. Data structures: Definitions for the node structure and the circular singly linked list type.
 2. Function prototypes: Declarations of the functions used in the program.
 3. Main function: Provides a menu-driven interface to perform operations on the circular singly linked list.
 4. Function implementations: Definitions of the functions to perform operations on the circular singly linked list.

 To compile the program, use the following command:
 gcc circular_singly_linked_list.c -o <executable_name>.bin

 To execute the compiled program, use the following command:
 ./<executable_name>.bin
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

//DEFINIÇÃO DA ESTRUTURA
typedef struct NoListaInt{
	int chave;
	struct NoListaInt* prox;
} NoListaInt, *ListaInt;

//PROTÓTIPO DE FUNÇÕES
void inicializar(ListaInt* l);
_Bool consultar(ListaInt* l,int x);
_Bool inserir(ListaInt* l,int x);
void retirar(ListaInt* l,int x);
void imprimir(ListaInt l);
int main(int argc, char **argv){
	ListaInt y;
	int menu,num;
	for(;;){
		printf("\n\n1 - INICIALIZAR\n");
		printf("2 - INSERIR\n");
		printf("3 - CONSULTAR\n");
		printf("4 - RETIRAR\n");
		printf("5 - IMPRIMIR LISTA\n");
		printf("\n\n\n");
		scanf("%d",&menu);	
//abaixo procure entender tb a chamada de cada função, qualquer dúvida só me falar
		switch(menu){
			case 1:
				inicializar(&y);
				break;
			case 2:
				printf("\nDigite um numero: ");
				scanf("%d",&num);
				inserir(&y,num);
				break;
			case 3:
				printf("\nDigite um numero: ");
				scanf("%d",&num);
				if(consultar(&y,num))
					printf("A lista contem o numero %d",num);
				else
					printf("A lista nao contem o numero %d",num);
				break;
			case 4:
				printf("\nDigite um numero: ");
				scanf("%d",&num);
				retirar(&y,num);
				break;
			case 5:
				imprimir(y);
				break;
			case 6:
				return 0;
				break;
		}
	}
	return 0;
}
//FUNÇÃO INICIALIZAR
void inicializar(ListaInt* l){
	*l=NULL;
}
//FUNÇÃO CONSULTAR
_Bool consultar(ListaInt* l,int x){
	ListaInt p;
	if(*l){
		for(p=(*l)->prox;(p->chave!=x)&&(p!=*l);p=p->prox);
		if(p->chave==x)
			return true;
	}
	return false;
}
//FUNÇÃO INSERIR
_Bool inserir(ListaInt* l,int x){
	ListaInt p;
	if((!consultar(l,x))&&(p=(ListaInt)malloc(sizeof(NoListaInt)))){
		if(*l){
			if((*l)->prox==*l)
				p->prox=*l;
			else
				p->prox=(*l)->prox;
			(*l)->prox=p;
		}
		else{
			*l=p;
			p->prox=p;
		}
		p->chave=x;
		return true;
	}
	return false;
}
//FUNÇÃO RETIRAR
void retirar(ListaInt* l,int x){
	ListaInt p,q;
	int aux=0;
	for(p=*l,q=NULL;(p)&&(p->chave!=x)&&(p->prox!=*l);q=p,p=p->prox);
	if((p) && (p->prox!=*l)){ //lista nao vazia e contendo o elemento
		if(!q) //lista com 1 elemento
			if(p->prox==*l)
				*l=NULL;
			else
				if(p->prox->prox==*l){ //lista com 2 elementos
					(*l)->prox->prox=p;
					*l=(*l)->prox;
				}
				else{
					aux=p->prox->chave;
					p->prox->chave=p->chave;
					p->chave=aux;
					p=p->prox;
					(*l)->prox=p->prox;
				}
		else //lista com mais de 1 elemento
			q->prox=p->prox;
		free(p);
	}
}
//FUNÇÃO IMPRIMIR
void imprimir(ListaInt l){
	ListaInt p;
	if(l){
		p=l;
		do{
			printf(" %d - ",p->chave);
			p=p->prox;
		}while(p->prox!=l->prox);
	}
}
void imprimir2(ListaInt l){
	ListaInt p,q;
	if(l)
		for(p=l;q->prox!=l;q=p,p=p->prox)
				printf(" %d - ", p->chave);
}

//FUNÇÃO RETIRAR 2
void retirar2(ListaInt* l,int x){
	ListaInt p,q;
	int aux;
	for(p=*l,q=NULL;(((p)&&(p->chave!=x)));q=p,p=p->prox);
	if(p){
		if(!q)
			if(p->prox==*l)
				*l=NULL;
			else
				if(p->prox->prox==(*l)){
					*l=p->prox;
					p->prox->prox=p->prox;
				}
				else{
					aux=p->prox->chave;
					p->prox->chave=p->chave;
					p->chave=aux;
					p=p->prox;
					(*l)->prox=(*l)->prox->prox;
				}					
		else
			q->prox=p->prox;
		free(p);
	}
}
