/*
 * This program implements a simple singly linked list in C.
 * The linked list supports the following operations:
 * 1. initialize: Initializes the linked list.
 * 2. search: Searches for a node with a given key in the linked list.
 * 3. insert: Inserts a new node with a given key at the beginning of the linked list.
 * 4. delete: Deletes a node with a given key from the linked list.
 * 5. print: Prints all the keys in the linked list.
 *
 * The program consists of the following main components:
 * 1. Data structures: Definitions for the node structure and the linked list type.
 * 2. Function prototypes: Declarations of the functions used in the program.
 * 3. Main function: Initializes the linked list and performs operations on it.
 * 4. Function implementations: Definitions of the functions to perform operations on the linked list.
 *
 * To compile the program, use the following command:
 * gcc singly_linked_list.c -o <executable_name>.bin
 *
 * To execute the compiled program, use the following command:
 * ./<executable_name>.bin
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0

typedef struct node{
	int key;
	struct node *next;
}node,*List;

void initialize(List *l);
_Bool search(List *l,int key);
_Bool insert(List *l,int key);
_Bool delete(List *l,int key);
void print(List l);

int main(int argc,char **argv){
	List l;
	initialize(&l);
	return 0;
}

void initialize(List *l){
	*l = NULL;
}

_Bool search(List *l,int key){
	List node;
	for(node = *l;(node) && (node->key != key);node = node->next);
	return node;
}

_Bool insert(List *l,int key){
	List new_node;
	if((new_node = (node *)malloc(sizeof(node)))){
		new_node->next = *l;
		*l = new_node;
		new_node->key = key;
		return true;
	}
	return false;
}

_Bool delete(List *l,int key){
	List node,q;
	for(node = *l,q = *l;(node) && (node->key != key);q = node,node = node->next);	
	if(node){
		if(*l == node) *l = node->next;
		else q->next = node->next;
		free(node);
		return true;
	}
	return false;
}

void print(List l){
	printf("%d",l->key);
	l = l->next;
	for(;l;l = l->next) printf(" %d",l->key);
	printf("\n");	
}