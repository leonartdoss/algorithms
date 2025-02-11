/*
 ============================================================================
 Name        : trabalho_arvores_vp.c
 Author      : Leonardo Gama
 Version     : 1.0
 Copyright   : 2013
 Description : Red-Black Tree Development in C, Ansi-style
 ============================================================================
 
 This program implements a Red-Black Tree in C. A Red-Black Tree is a balanced binary search tree with the following properties:
 1. Each node is either red or black.
 2. The root is black.
 3. All leaves (NIL nodes) are black.
 4. If a red node has children, then the children are always black (no two red nodes can be adjacent).
 5. Every path from a node to its descendant NIL nodes has the same number of black nodes.

 The program supports the following operations:
 1. Initialize (Inicializar): Initializes the Red-Black Tree.
 2. Insert (Inserir): Inserts a new node with a given key into the Red-Black Tree.
 3. Balance (Balancear): Balances the Red-Black Tree after insertion.
 4. Search (Consultar): Searches for a node with a given key in the Red-Black Tree.
 5. Print (Imprimir): Prints the keys in the Red-Black Tree in various orders.
 6. Rotate (Rotacionar): Performs left and right rotations to maintain the Red-Black Tree properties.

 The program consists of the following main components:
 1. Data structures: Definitions for the node structure and the Red-Black Tree type.
 2. Function prototypes: Declarations of the functions used in the program.
 3. Main function: Initializes the Red-Black Tree and performs operations on it based on user input.
 4. Function implementations: Definitions of the functions to perform operations on the Red-Black Tree.

 To compile the program, use the following command:
 gcc red_black_tree.c -o <executable_name>.bin

 To execute the compiled program, use the following command:
 ./<executable_name>.bin
 ============================================================================
  
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define vermelho 1
#define preto 0

typedef struct NoArvoreVP{
	int chave,cor;
	struct NoArvoreVP *esq, *dir, *pai;
}NoArvoreVP, *ArvoreVP;

void Inicializar(ArvoreVP *raiz);
_Bool Inserir(ArvoreVP *raiz,int x);
void Balancear(ArvoreVP *raiz,ArvoreVP itr);
_Bool Consultar(ArvoreVP *raiz,int x);
void ImprimirOrdemCrescente(ArvoreVP itr);
void ImprimirOrdemDecrescente(ArvoreVP itr);
void ImprimirNivel(ArvoreVP itr,int x);
void PercursoEmOrdem(ArvoreVP itr4);
void ImprimirBuscaEmLargura(ArvoreVP itr);
void ImprimirNivelEmLargura(ArvoreVP itr,int x);
int AlturaArvore(ArvoreVP itr);
ArvoreVP RotacaoEsquerda(ArvoreVP r);
ArvoreVP RotacaoDireita(ArvoreVP r);
ArvoreVP TioNo(ArvoreVP itr2);
ArvoreVP AvoNo(ArvoreVP itr3);

int main(int argc,char **argv){
	int num,nivel;
	char opcao;
	ArvoreVP A;
	Inicializar(&A);
	for(;;){
		scanf(" %c",&opcao);
		switch(opcao){
			case 'i':
				scanf("%d",&num);
				Inserir(&A,num);
			break;
			case 'c':
				scanf("%d",&num);
				if(Consultar(&A,num))
					printf("existe no com chave: %d\n",num);
				else
					printf("nao existe no com chave: %d\n",num);
			break;
			case 'p':
				scanf(" %c",&opcao);
				switch(opcao){
					case 'c':
						ImprimirOrdemCrescente(A);
					break;
					case 'd':
						ImprimirOrdemDecrescente(A);
					break;
				}
			break;
			case 'n':
				scanf("%d",&nivel);
				ImprimirNivel(A,nivel);
			break;
			case 'd':
				PercursoEmOrdem(A);
			break;
			case 'l':
				ImprimirBuscaEmLargura(A);
			break;
			case 'a':
				printf("%d\n",AlturaArvore(A));
			break;
			case 'e':
				exit(1);
			break;
		}
	}
	return 0;
}

void Inicializar(ArvoreVP *raiz){
	*raiz = NULL;
}

_Bool Inserir(ArvoreVP *raiz,int x){
	ArvoreVP itr,novo,ult = NULL;
	if(!(novo=(ArvoreVP)malloc(sizeof(NoArvoreVP))) || (Consultar(raiz,x)))
		return false;
	if(!(*raiz)){
		*raiz = novo;
		novo->cor = preto;
	}
	else{
		itr = *raiz;
		while(itr){
			ult = itr;
			if(x < itr->chave)
				itr = itr->esq;
			else
				itr = itr->dir;
		}
		if(x < ult->chave)
			ult->esq = novo;
		else
			ult->dir = novo;
		novo->cor = vermelho;
	}
	novo->chave = x;
	novo->esq = NULL;
	novo->dir = NULL;
	novo->pai = ult;
	Balancear(raiz,novo);
	return true;
}

void Balancear(ArvoreVP *raiz,ArvoreVP itr4){
	ArvoreVP tio,avo;
	if(!itr4->pai)
		return;
	while(itr4 && itr4 != *raiz){
		if(itr4->cor == vermelho && itr4->pai->cor == vermelho){
			tio = TioNo(itr4);
			avo = AvoNo(itr4);
			if((tio) && (tio->cor == vermelho)){
				avo->cor = vermelho;
				tio->cor = preto;
				itr4->pai->cor = preto;
			}
			else{
				if((!tio) || (tio->cor == preto)){
					if((avo) && (avo->dir == itr4->pai) && (itr4->pai->dir == itr4)){
						itr4 = RotacaoEsquerda(avo);
					}
					else
						if((avo) && (avo->esq == itr4->pai) && (itr4->pai->esq == itr4)){
							itr4 = RotacaoDireita(avo);
						}
						else
							if((avo) && (avo->dir == itr4->pai) && (itr4->pai->esq == itr4)){
								itr4 = RotacaoDireita(itr4->pai);
								itr4 = RotacaoEsquerda(itr4->pai);
							}
							else
								if((avo) && (avo->esq == itr4->pai) && (itr4->pai->dir == itr4)){
									itr4 = RotacaoEsquerda(itr4->pai);
									itr4 = RotacaoDireita(itr4->pai);
								}
				itr4->cor = preto;
				if(itr4->esq)
					itr4->esq->cor = vermelho;
				if(itr4->dir)
					itr4->dir->cor = vermelho;
				}
			if(!itr4->pai)
				*raiz = itr4;
			}
		}
		itr4 = itr4->pai;
	}
	(*raiz)->cor = preto;
	
}

_Bool Consultar(ArvoreVP *raiz,int x){
	ArvoreVP itr = *raiz;
	while(itr && itr->chave != x)
		if(x < itr->chave)
			itr = itr->esq;
		else
			itr = itr->dir;
	return itr;
}

void ImprimirOrdemCrescente(ArvoreVP itr){
	if(itr){
		ImprimirOrdemCrescente(itr->esq);
		printf("%d\n",itr->chave);
		ImprimirOrdemCrescente(itr->dir);
	}
}

void ImprimirOrdemDecrescente(ArvoreVP itr){
	if(itr){
		ImprimirOrdemDecrescente(itr->dir);
		printf("%d\n",itr->chave);
		ImprimirOrdemDecrescente(itr->esq);
	}
}

void ImprimirNivel(ArvoreVP itr,int x){
	if(x == 1){
		if(itr)
			printf("%d\n",itr->chave);
	}
	else{
		if(itr->esq)
			ImprimirNivel(itr->esq,x-1);
		if(itr->dir)
			ImprimirNivel(itr->dir,x-1);
	}
}

void PercursoEmOrdem(ArvoreVP itr){
	if(itr){
		PercursoEmOrdem(itr->esq);
		printf("chave: %d ",itr->chave);
		if(itr->cor)
			printf("cor: vermelho ");
		else
			printf("cor: preto ");
		if(itr->esq)
			printf("fesq: %d ",itr->esq->chave);
		else
			printf("fesq: nil ");
		if(itr->dir)
			printf("fdir: %d ",itr->dir->chave);
		else
			printf("fdir: nil ");
		printf("\n");
		PercursoEmOrdem(itr->dir);
	}
}

void ImprimirBuscaEmLargura(ArvoreVP itr){
	int nivel, altura = AlturaArvore(itr);
	for(nivel = 1;nivel <= altura;nivel++)
		ImprimirNivelEmLargura(itr,nivel);
}

void ImprimirNivelEmLargura(ArvoreVP itr,int x){
	if(x==1){
		if(itr){
			printf("chave: %d ",itr->chave);
			if(itr->cor)
				printf("cor: vermelho ");
			else
				printf("cor: preto ");
			if(itr->esq)
				printf("fesq: %d ",itr->esq->chave);
			else
				printf("fesq: nil ");
			if(itr->dir)
				printf("fdir: %d ",itr->dir->chave);
			else
				printf("fdir: nil ");
			printf("\n");
		}
	}
	else{
		if(itr->esq)
			ImprimirNivelEmLargura(itr->esq,x-1);
		if(itr->dir)
			ImprimirNivelEmLargura(itr->dir,x-1);
	}
}

int AlturaArvore(ArvoreVP itr){
	int sub_esq,sub_dir;
	if(!itr)
		return 0;
	sub_esq = AlturaArvore(itr->esq);
	sub_dir = AlturaArvore(itr->dir);
	if(sub_esq > sub_dir)
		return sub_esq +1;
	else
		return sub_dir +1;
}

ArvoreVP RotacaoEsquerda(ArvoreVP r){
	ArvoreVP q = r->dir;
	r->dir = q->esq;
	if(q->esq)
		q->esq->pai = r;
	q->esq = r;
	if(r->pai){
		if(r->pai->esq == r)
			r->pai->esq = q;
		else
			r->pai->dir = q;
	}
	q->pai = r->pai;
	r->pai = q;
	return q;
}

ArvoreVP RotacaoDireita(ArvoreVP r){
	ArvoreVP q = r->esq;
	r->esq = q->dir;
	if(q->dir)
		q->dir->pai = r;
	q->dir = r;
	if(r->pai){
		if(r->pai->esq == r)
			r->pai->esq = q;
		else
			r->pai->dir = q;
	}
	q->pai = r->pai;
	r->pai = q;
	return q;
}

ArvoreVP AvoNo(ArvoreVP itr3){
	if(!itr3->pai || !itr3)
		return NULL;
	return itr3->pai->pai;
}

ArvoreVP TioNo(ArvoreVP itr2){
	ArvoreVP avo = AvoNo(itr2);
	if(!itr2 || !avo)
		return NULL;
	if(itr2->pai == avo->esq)
		return avo->dir;
	return avo->esq;
}
