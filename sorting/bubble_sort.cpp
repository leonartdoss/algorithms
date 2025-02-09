/**
 * This program implements the Bubble Sort algorithm to sort an array of integers.
 * Bubble Sort is a simple sorting algorithm that repeatedly steps through the list,
 * compares adjacent elements and swaps them if they are in the wrong order. The pass
 * through the list is repeated until the list is sorted.
 *
 * This implementation sorts an array of size 10.
 * You can change the value of SIZE to sort arrays of different sizes.
 *
 * To compile:
 * $ g++ bubble_sort.cpp -o <executable_name>.bin
 *
 * To run:
 * $ ./<executable_name>.bin
 *
 * The program will prompt the user to input 10 integers, which will then be sorted
 * using the Bubble Sort algorithm.
 */

#include <iostream>

#define SIZE 10

using namespace std;

void swap(int *v,int dst,int src){
	const int aux = v[dst];
	v[dst] = v[src];
	v[src] = aux;
}

void bubble_sort(int *v){
	for(int i = SIZE - 1;i > 0;i --)
		for(int j = 0;j < i;j ++)
			if(v[j] > v[j + 1]) swap(v, j, j + 1);
}

int main(){
	int v[SIZE];
	for(int i = 0;i < SIZE;i ++)
		cin >> v[i];
	bubble_sort(v);
	return 0;
}
