/*
 ============================================================================
 Name        : binary_tree.c
 Author      : Leonardo Gama
 Version     : 1.0
 Description : Binary Search Tree implementation in C
 ============================================================================
 
 This program implements a simple Binary Search Tree (BST) data structure in C.
 The BST supports the following operations:
 1. Initialize (Inicializar): Initializes the BST.
 2. Insert (Inserir): Inserts a new node with a given key into the BST.
 3. Remove (Remover): Removes a node with a given key from the BST.
 4. Search (Consultar): Searches for a node with a given key in the BST.
 5. Pre-order Traversal (PercursoPreOrdem): Prints the keys in the BST in pre-order.
 6. In-order Traversal (PercursoEmOrdem): Prints the keys in the BST in in-order.
 7. Post-order Traversal (PercursoPosOrdem): Prints the keys in the BST in post-order.
 8. Find Minimum (BuscaMenor): Finds the node with the minimum key in the BST.
 9. Find Local Minimum (BuscaLocalMenorChave): Finds the local minimum key in the BST.

 The program consists of the following main components:
 1. Data structures: Definitions for the node structure and the BST type.
 2. Function prototypes: Declarations of the functions used in the program.
 3. Main function: Provides a menu-driven interface to perform operations on the BST.
 4. Function implementations: Definitions of the functions to perform operations on the BST.

 To compile the program, use the following command:
 gcc binary_search_tree.c -o <executable_name>.bin

 To execute the compiled program, use the following command:
 ./<executable_name>.bin
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct NoArvoreBB{
	int chave;
	struct NoArvoreBB *esq, *dir, *pai;
}NoArvoreBB, *ArvoreBB;

void Inicializar(ArvoreBB* raiz);
ArvoreBB Consultar(ArvoreBB* raiz,int x);
_Bool Inserir(ArvoreBB* raiz,int x);
void Remover(ArvoreBB* raiz,int x);
void PercursoPreOrdem(ArvoreBB itr);
void PercursoEmOrdem(ArvoreBB itr);
void PercursoPosOrdem(ArvoreBB itr);
int BuscaMenor(ArvoreBB itr,int *menor);
ArvoreBB BuscaLocalMenorChave(ArvoreBB itr,ArvoreBB *local);

int main(){
	int num,opcao,menor;
	ArvoreBB raiz;
	for(;;){
		printf("1 - iniciar\n");
		printf("2 - consultar\n");
		printf("3 - inserir\n");
		printf("4 - remover\n");
		printf("5 - imprimir em pre ordem\n");
		printf("6 - imprimir em ordem\n");
		printf("7 - imprimir em pos ordem\n");
		scanf("%d",&opcao);
		switch(opcao){
			case 1:
				Inicializar(&raiz);
			break;
			case 2:
				printf("valor_remocao de consulta: ");scanf("%d",&num);
				if(Consultar(&raiz,num))
					printf("O valor_remocao esta na arvore\n");
				else
					printf("O valor_remocao nao esta na arvore\n");
			break;
			case 3:
				printf("valor_remocao de entrada: ");scanf("%d",&num);
				Inserir(&raiz,num);
				printf("Raiz: %d\n",raiz->chave);
			break;
			case 4:
				printf("valor_remocao de remocao: ");scanf("%d",&num);
				Remover(&raiz,num);
			break;
			case 5:
				PercursoPreOrdem(raiz);
				printf("\n");
			break;
			case 6:
				PercursoEmOrdem(raiz);
				printf("\n");
			break;
			case 7:
				PercursoPosOrdem(raiz);
				printf("\n");
			break;
			case 8:
				menor=raiz->chave;
				printf("%d\n",BuscaMenor(raiz,&menor));
			break;
		}
	}
	return 0;
}
void Inicializar(ArvoreBB* raiz){
	*raiz=NULL;
}
ArvoreBB Consultar(ArvoreBB* raiz,int x){
	ArvoreBB itr;
	itr=*raiz;
	while((itr)&&(itr->chave!=x))
		if(x<itr->chave)
			itr=itr->esq;
		else
			itr=itr->dir;
	return (itr);
}
_Bool Inserir(ArvoreBB* raiz,int x){
	ArvoreBB itr,novo,ult=NULL;
	if(!(novo=(ArvoreBB)malloc(sizeof(NoArvoreBB))))
		return false;
	if(!(*raiz))
		*raiz=novo;
	else{
		itr=*raiz;
		while(itr){
			ult=itr;
			if(x<itr->chave)
				itr=itr->esq;
			else
				itr=itr->dir;
		}
		if(x<ult->chave)
			ult->esq=novo;
		else
			ult->dir=novo;
	}
	novo->chave=x;
	novo->esq=NULL;
	novo->dir=NULL;
	novo->pai=ult;
	return true;
}
void Remover(ArvoreBB *raiz,int x){
	ArvoreBB itr,real_free,valor_remocao=Consultar(raiz,x);
	if(!valor_remocao)
		return;
	if((!valor_remocao->esq) || (!valor_remocao->dir))
		real_free=valor_remocao;
	else
		real_free=BuscaLocalMenorChave(valor_remocao->dir,&(valor_remocao->dir));
	if(real_free->esq)
		itr=real_free->esq;
	else
		itr=real_free->dir;
	if(itr)
		itr->pai=real_free->pai;
	if(!real_free->pai)
		*raiz=itr;
	else
		if(real_free==real_free->pai->esq)
			real_free->pai->esq=itr;
		else
			real_free->pai->dir=itr;
	if(real_free!=valor_remocao)
		valor_remocao->chave=real_free->chave;
	free(real_free);
}
void PercursoPreOrdem(ArvoreBB itr){
	if(itr!=NULL){
		printf("%d ",itr->chave);
		PercursoPreOrdem(itr->esq);
		PercursoPreOrdem(itr->dir);
	}
}
void PercursoEmOrdem(ArvoreBB itr){
	if(itr!=NULL){
		PercursoEmOrdem(itr->esq);
		printf("%d ",itr->chave);
		PercursoEmOrdem(itr->dir);
	}
}
void PercursoPosOrdem(ArvoreBB itr){
	if(itr!=NULL){	
		PercursoPosOrdem(itr->esq);
		PercursoPosOrdem(itr->dir);
		printf("%d ",itr->chave);
	}
}
int BuscaMenor(ArvoreBB itr,int *menor){
	if(itr!=NULL){
		BuscaMenor(itr->esq,menor);
		if(itr->chave < *menor)
			*menor=itr->chave;
		BuscaMenor(itr->dir,menor);
	}
	return *menor;
}

ArvoreBB BuscaLocalMenorChave(ArvoreBB itr,ArvoreBB *local){
	if(itr!=NULL){
		BuscaLocalMenorChave(itr->esq,local);
		if((itr->chave) < ((*local)->chave))
			*local=itr;
		BuscaLocalMenorChave(itr->dir,local);
	}
	printf("Menor chave: %d\n",(*local)->chave);
	return *local;
}